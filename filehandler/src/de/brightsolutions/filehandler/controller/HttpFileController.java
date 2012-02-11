package de.brightsolutions.filehandler.controller;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.HttpVersion;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.mime.MultipartEntity;
import org.apache.http.entity.mime.content.ContentBody;
import org.apache.http.entity.mime.content.FileBody;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.CoreProtocolPNames;

import de.brightsolutions.filehandler.FileHandlerCallback;

/**
 * 
 * 
 * @author lavong.soysavanh
 * @since 2012-01-14
 */
public class HttpFileController extends FileController {

	public HttpFileController(FileHandlerCallback listener) {
		super(listener);
	}

	@Override
	public void downloadFile(String url, String localFileName) {
		if (listener != null) {
			listener.onDownloadFileStarted(localFileName);
		}

		FileOutputStream fos = null;
		try {
			URLConnection conn = new URL(url).openConnection();
			InputStream rs = conn.getInputStream();
			//			String rsString = streamToString(rs);
			//			System.out.println("rs: " + rsString);

			fos = new FileOutputStream(localFileName);
			byte buf[] = new byte[1024];
			int len;
			while ((len = rs.read(buf)) > 0) {
				fos.write(buf, 0, len);
			}
			System.out.println("wrote to file: " + localFileName);

		} catch (Exception e) {
			e.printStackTrace();
			if (listener != null) {
				listener.onDownloadFileFailed("upload failed: " + e.getMessage());
			}
		} finally {
			if (fos != null) {
				try {
					fos.close();
				} catch (IOException e) {
				}
			}
		}

		if (listener != null) {
			listener.onDownloadFileFinished(localFileName);
		}
	}

	@Override
	public void uploadFile(String localFileName, String url) {
		if (listener != null) {
			listener.onUploadFileStarted(localFileName, url);
		}

		try {

//			HttpPost httpPost = new HttpPost(url);
//			FileEntity entity = new FileEntity(new File(localFileName), "binary/octet-stream");
//			entity.setContentType("binary/octet-stream");
//			httpPost.setEntity(entity);

		    HttpPost httpPost = new HttpPost(url);
		    File file = new File(localFileName);

		    MultipartEntity mpEntity = new MultipartEntity();
		    ContentBody cbFile = new FileBody(file, "binary/octet-stream");
		    mpEntity.addPart("userfile", cbFile);


		    httpPost.setEntity(mpEntity);

			HttpClient httpClient = new DefaultHttpClient();
			httpClient.getParams().setParameter(CoreProtocolPNames.PROTOCOL_VERSION, HttpVersion.HTTP_1_1);

			HttpResponse rs = httpClient.execute(httpPost);
			String rsString = streamToString(rs.getEntity().getContent());
			int status = rs.getStatusLine().getStatusCode();
			System.out.println("rs status: " + status);
			System.out.println("rs: " + rsString);
			if (HttpStatus.SC_OK != status) {
				if (listener != null) {
					listener.onUploadFileFailed("upload failed. status 200 expected. received " + status + ".");
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
			if (listener != null) {
				listener.onUploadFileFailed("upload failed: " + e.getMessage());
			}
		}

		if (listener != null) {
			listener.onUploadFileFinished(localFileName, url);
		}
	}

	private String streamToString(InputStream in) {
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		StringBuffer sb = new StringBuffer();
		String line = null;

		try {
			while ((line = br.readLine()) != null) {
				sb.append(line + "\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
			} catch (IOException e) {
			}
		}

		return sb.toString();
	}

}
