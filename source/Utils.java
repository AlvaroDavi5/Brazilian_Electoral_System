package source;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Scanner;


public class Utils {
	// methods
	public int countColumns(String row)
	{
		String[] columns = row.split(",");

		return columns.length;
	}

	public ElectionInfo readFile(String path) throws IOException
	{
		FileReader reader = new FileReader(path);
		BufferedReader buff = new BufferedReader(reader);
		String line = "";
		boolean firstLine = true;
		ElectionInfo eleInfo = new ElectionInfo();

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

		return eleInfo;
	}

	public boolean writeFile(String path) throws IOException
	{
		FileWriter writer = new FileWriter(path);
		BufferedWriter buff = new BufferedWriter(writer);
		String line = "";

		Scanner in = new Scanner(System.in);
		System.out.println("Type anything: ");
		line = in.nextLine();
		buff.append(line + '\n');
		buff.close();
		in.close();

		return false;
	}

}
