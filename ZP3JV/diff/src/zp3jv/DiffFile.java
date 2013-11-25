package zp3jv;

import java.util.ArrayList;

public class DiffFile {

	private ArrayList<DiffLine> content = new ArrayList<DiffLine>();

	public void add(DiffLine line) {
		content.add(line);
	}

	public void add(DiffFile file) {
		for(DiffLine line : file.getContent())
			content.add(line);
	}

	/**
	 * @return the content
	 */
	public ArrayList<DiffLine> getContent() {
		return content;
	}

	@Override
	public String toString()
	{
		String s = "";
		for(DiffLine line : this.content)
			s += line.toString() + System.getProperty("line.separator");
		return s;
	}
}