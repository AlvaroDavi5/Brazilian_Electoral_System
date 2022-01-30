package source.classes;
import java.util.Date;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import source.Election;


public class Utils {
	// methods
	public int countColumns(String row) {
		String[] columns = row.split(",");

		return columns.length;
	}

	public void readFile(String path, Election eleInfo) throws IOException {
		FileReader reader = new FileReader(path);
		BufferedReader buff = new BufferedReader(reader);
		String line = "";
		boolean firstLine = true;

		while (true)
		{
			if (line != null)
			{
				if (firstLine && line != "")
				{
					if (countColumns(line) == 4)
					{
						eleInfo.setEntity('p');
					}
					else
					{
						eleInfo.setEntity('c');
					}
					firstLine = false;
				}
				else
				{
					eleInfo.addData(line);
				}
			}
			else
			{
				break;
			}
			line = buff.readLine();
		}

		buff.close();
	}

	public boolean writeFile(String path, String text) throws IOException {
		FileWriter writer = new FileWriter(path);
		BufferedWriter buff = new BufferedWriter(writer);

		buff.append(text);
		buff.close();

		return true;
	}

	public boolean olderThan(Date d1, Date d2) {
		int comparation = d1.compareTo(d2);

		if (comparation >= 0) {
			return false;
		}
		else {
			return true;
		}
	}

}
