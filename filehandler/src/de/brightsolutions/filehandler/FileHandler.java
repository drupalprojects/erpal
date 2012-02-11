package de.brightsolutions.filehandler;

import static java.nio.file.StandardWatchEventKinds.ENTRY_CREATE;
import static java.nio.file.StandardWatchEventKinds.ENTRY_DELETE;
import static java.nio.file.StandardWatchEventKinds.ENTRY_MODIFY;
import static java.nio.file.StandardWatchEventKinds.OVERFLOW;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Desktop;
import java.awt.Dimension;
import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.WatchEvent;
import java.nio.file.WatchEvent.Kind;
import java.nio.file.WatchKey;
import java.nio.file.WatchService;
import java.util.Arrays;

import javax.swing.JFrame;
import javax.swing.UIManager;

import de.brightsolutions.filehandler.controller.HttpFileController;
import de.brightsolutions.filehandler.ui.FileHandlerPanel;

/**
 * 
 * 
 * @author lavong.soysavanh
 * @since 2012-01-12
 */
public class FileHandler {

	private static FileHandlerPanel fileHandlerPanel;

	private static HttpFileController controller;

	private static final int WATCH_INTERVAL = 42 * 23;

	private static final String ARG_DOWNLOAD_LINK = "download=";
	private static final String ARG_UPLOAD_LINK = "upload=";
	private static final String ARG_SESSION = "session=";
	private static final String ARG_FILE_ID = "fid=";
	private static final String ARG_FILE_NAME = "filename=";

	/**
	 * download/upload listener
	 * 
	 * @author lavong.soysavanh
	 * @since 2012-01-14
	 */
	private static class FileControllerCallback implements FileHandlerCallback {

		@Override
		public void onDownloadFileStarted(String filename) {
			fileHandlerPanel.enableProgressbar();
			fileHandlerPanel.append("file download started: " + filename);
		}

		@Override
		public void onDownloadFileFinished(String filename) {
			fileHandlerPanel.append("file download finished: " + filename);
			fileHandlerPanel.setProgressBarText("done");
		}

		@Override
		public void onDownloadFileFailed(String message) {
			fileHandlerPanel.append("file download failed: " + message);
			fileHandlerPanel.setProgressBarText("failed");
			shutdown();
		}

		@Override
		public void onUploadFileStarted(String source, String destination) {
			fileHandlerPanel.enableProgressbar();
			fileHandlerPanel.append("file upload started: " + source + " -> " + destination);
		}

		@Override
		public void onUploadFileFinished(String source, String destination) {
			fileHandlerPanel.append("file upload finished: " + source + " -> " + destination);
			fileHandlerPanel.setProgressBarText("done");
			fileHandlerPanel.disableProgressbar();
			shutdown();
		}

		@Override
		public void onUploadFileFailed(String message) {
			fileHandlerPanel.append("file upload failed: " + message);
			fileHandlerPanel.setProgressBarText("failed");
			fileHandlerPanel.disableProgressbar();
			shutdown();
		}

		@Override
		public void onProgressUpdate(int progress) {
			fileHandlerPanel.append("progress update: " + progress);
		}

	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		fileHandlerPanel = new FileHandlerPanel();
		controller = new HttpFileController(new FileControllerCallback());
		boolean fileOpened = true;

		System.out.println("args: " + Arrays.toString(args));

		// display GUI
		createAndShowGUI();

		// extract arguments
		String downloadUrl = null; // = "http://www.rfc-editor.org/rfc/rfc1880.txt";
		String uploadUrl = null; // = "http://localhost/plupload/examples/upload.php?name=";
		String sessionId = null; // = "";
		String fileId = null; // = "someFileId";
		String filename = null;
		for (String arg : args) {
			if (arg.startsWith(ARG_DOWNLOAD_LINK)) {
				downloadUrl = arg.split("=")[1];
			} else if (arg.startsWith(ARG_UPLOAD_LINK)) {
				uploadUrl = arg.substring(ARG_UPLOAD_LINK.length(), arg.length());
			} else if (arg.startsWith(ARG_SESSION)) {
				sessionId = arg.split("=")[1];
			} else if (arg.startsWith(ARG_FILE_ID)) {
				fileId = arg.split("=")[1];
			} else if (arg.startsWith(ARG_FILE_NAME)) {
				filename = arg.split("=")[1];
			} else {
				System.out.println("ignoring unknown argument " + arg);
			}
		}
		fileHandlerPanel.append("args: " + Arrays.toString(args));

		// download file
		String pathName = System.getProperty("user.home", "/");
		pathName += File.separator + "Downloads";
		new File(pathName).mkdirs();
		controller.downloadFile(downloadUrl, pathName + File.separator + filename);
		//String fileName = "";
		//URL url;
		//		try {
		//			//url = new URL(downloadUrl);
		//			//			fileName = extractFileName(url.getFile());
		//			//			if (fileName == null || "".equals(fileName)) {
		//			//				fileName = fileId;
		//			//			}
		//		} catch (MalformedURLException e) {
		//			e.printStackTrace();
		//			fileHandlerPanel.append("unable to download from: " + downloadUrl + " - " + e.getMessage());
		//			shutdown();
		//		}
		File file = new File(pathName, filename);

		// attempt to open file with default application
		fileHandlerPanel.append("opening file " + file.getPath() + " ...");
		Desktop desktop = Desktop.getDesktop();
		try {
			desktop.open(file);
			fileHandlerPanel.setProgressBarText("observing file for changes");
		} catch (Exception e) {
			e.printStackTrace();
			fileHandlerPanel.append("weren't able to open file - " + e.getMessage());
			fileHandlerPanel.disableProgressbar();
			fileOpened = false;
		}

		if (fileOpened) {
			try {
				// register directory watch service
				WatchService watcher = FileSystems.getDefault().newWatchService();
				fileHandlerPanel.append("observing directory: " + pathName);
				Path path = Paths.get(pathName);
				WatchKey key = path.register(watcher, ENTRY_CREATE, ENTRY_DELETE, ENTRY_MODIFY);

				// start listening for changes in directory indefinitely
				while (fileHandlerPanel.isVisible()) {
					for (WatchEvent<?> event : key.pollEvents()) {
						Kind<?> kind = event.kind();
						if (kind == OVERFLOW) {
							continue;
						}
						WatchEvent<Path> ev = cast(event);
						Path changedPath = ev.context();
						Path child = path.resolve(changedPath);
						String s = String.format("%s: %s", event.kind().name(), child);
						System.out.println(s);
						fileHandlerPanel.append("found - " + s);
						// child.getFileName().toString()

						// uploading
						if (kind == ENTRY_MODIFY) {
							fileHandlerPanel.append("uploading to " + uploadUrl);
							fileHandlerPanel.append(child + "...");
							fileHandlerPanel.setProgressBarText("uploading...");

							//controller.uploadFile(child.toString(), uploadUrl + child.getFileName().toString());
							controller.uploadFile(child.toString(), uploadUrl);
						}
					}
					try {
						Thread.sleep(WATCH_INTERVAL);
					} catch (InterruptedException e) {
					}
				}
			} catch (IOException e) {
				fileHandlerPanel.append("not able to observe directory - " + e.getMessage());
				e.printStackTrace();
			}
		}

		/*
		 * this is only necessary if something unexpected happened (file doesn't
		 * exists, no permission to open, no application to open, or the like)
		 * and our jframe's default close operation doesn't kick in
		 */
		shutdown();
	}

	private static String extractFileName(String url) {
		if (url != null) {
			String[] u = url.split("/");
			if (u.length > 0) {
				return u[u.length - 1];
			}
		}
		return "";
	}

	@SuppressWarnings("unchecked")
	static <T> WatchEvent<T> cast(WatchEvent<?> event) {
		return (WatchEvent<T>) event;
	}

	/**
	 * Create the GUI and show it. For thread safety, this method should be
	 * invoked from the event-dispatching thread.
	 */
	private static void createAndShowGUI() {
		// attempt to set system look and feel
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e) {
		}

		// initialize GUI
		JFrame frame = new JFrame("File Handler");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setPreferredSize(new Dimension(400, 150));

		Container contentPane = frame.getContentPane();
		contentPane.add(fileHandlerPanel, BorderLayout.CENTER);

		frame.pack();
		frame.setVisible(true);
	}

	private static void shutdown() {
		//		int sleepTime = 10;
		//		for (int i = sleepTime; i > 0; i--) {
		//			fileHandlerPanel.append("closing application in " + i);
		//			try {
		//				Thread.sleep(1000);
		//			} catch (InterruptedException e) {
		//			}
		//		}
		//		System.exit(0);
	}

}
