package de.brightsolutions.filehandler.ui;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

/**
 * 
 * 
 * @author lavong.soysavanh
 * @since 2012-01-12
 */
public class FileHandlerPanel extends JPanel {

	private static final long serialVersionUID = 1L;

	private JTextArea textArea = new JTextArea();
	private JProgressBar progressBar = new JProgressBar();

	public FileHandlerPanel() {
		setLayout(new BorderLayout());
		JScrollPane textAreaScrollPane = new JScrollPane(textArea);
		add(textAreaScrollPane, BorderLayout.CENTER);
		progressBar.setIndeterminate(true);
		progressBar.setStringPainted(true);
		add(progressBar, BorderLayout.SOUTH);
	}

	public void append(String text) {
		if (text != null) {
			textArea.append(text + "\n");
			textArea.setCaretPosition(textArea.getText().length());
		}
	}

	public void setProgressBarText(String text) {
		progressBar.setStringPainted(true);
		progressBar.setString(text);
	}

	public void disableProgressbar() {
		progressBar.setStringPainted(false);
		progressBar.setIndeterminate(false);
	}

	public void enableProgressbar() {
		progressBar.setStringPainted(true);
		progressBar.setIndeterminate(true);
	}

}
