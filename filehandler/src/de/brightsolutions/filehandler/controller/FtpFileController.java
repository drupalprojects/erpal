package de.brightsolutions.filehandler.controller;

import de.brightsolutions.filehandler.FileHandlerCallback;

/**
 * 
 * 
 * @author lavong.soysavanh
 * @since 2012-01-13
 */
public class FtpFileController extends FileController {

	private final String ftpUsername;
	private final String ftpPassword;

	public FtpFileController(FileHandlerCallback listener, String ftpUsername, String ftpPassword) {
		super(listener);
		this.ftpUsername = ftpUsername;
		this.ftpPassword = ftpPassword;
	}

	@Override
	public void downloadFile(String url, String localFileName) {
		if (listener != null) {
			listener.onDownloadFileStarted(localFileName);
		}

		// TODO implement

		if (listener != null) {
			listener.onDownloadFileFinished(localFileName);
		}
	}

	@Override
	public void uploadFile(String localFileName, String url) {
		if (listener != null) {
			listener.onUploadFileStarted(localFileName, url);
		}

		// TODO implement

		if (listener != null) {
			listener.onUploadFileFinished(localFileName, url);
		}
	}

}
