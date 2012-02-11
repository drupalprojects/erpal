package de.brightsolutions.filehandler.controller;

import de.brightsolutions.filehandler.FileHandlerCallback;

/**
 * 
 * 
 * @author lavong.soysavanh
 * @since 2012-01-13
 */
public abstract class FileController {

	protected final FileHandlerCallback listener;

	public FileController(FileHandlerCallback listener) {
		this.listener = listener;
	}

	public abstract void downloadFile(String url, String localFileName);

	public abstract void uploadFile(String localFileName, String url);

}
