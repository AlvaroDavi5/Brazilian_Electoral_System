package src.classes;
import java.util.Date;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import src.Election;


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

	public int olderThan(Date d1, Date d2) {
		int diff = d1.compareTo(d2);

		if (diff > 0) {
			return -1;
		}
		else if (diff == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}

	public int calculateAge(String birthDate, String currentDate) {
		String[] splitedBirthDate = birthDate.split("/");
		String[] splitedCurrentDate = currentDate.split("/");
		int birthDateDay = Integer.parseInt(splitedBirthDate[0]);
		int birthDateMoth = Integer.parseInt(splitedBirthDate[1]);
		int birthDateYear = Integer.parseInt(splitedBirthDate[2]);
		int currentDateDay = Integer.parseInt(splitedCurrentDate[0]);
		int currentDateMoth = Integer.parseInt(splitedCurrentDate[1]);
		int currentDateYear = Integer.parseInt(splitedCurrentDate[2]);

		int age = currentDateYear - birthDateYear;

		if (currentDateMoth < birthDateMoth) {
			age--;
		}
		else if (currentDateMoth == birthDateMoth) {
			if (currentDateDay < birthDateDay) {
				age--;
			}
		}

		return age;
	}

}
