package de.brightsolutions.filehandler;

/**
 * 
 * 
 * @author lavong.soysavanh
 * @since 2012-01-13
 */
public interface FileHandlerCallback {

	void onDownloadFileStarted(String filename);

	void onDownloadFileFinished(String filename);

	void onDownloadFileFailed(String message);

	void onUploadFileStarted(String source, String destination);

	void onUploadFileFinished(String source, String destination);

	void onUploadFileFailed(String message);

	void onProgressUpdate(int progress);
	
	void onMessage(String message);

}
