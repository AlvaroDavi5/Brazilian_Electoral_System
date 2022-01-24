import source.*;
import java.io.IOException;
import java.lang.ArrayIndexOutOfBoundsException;


public class Election {

	public static void main(String[] args) throws IOException {
		Utils util = new Utils();

		try {
			ElectionInfo candidatesElection = util.readFile(args[0]);
			ElectionInfo partiesElection = util.readFile(args[1]);

			candidatesElection.setElectionDate(candidatesElection.parseStringToDate(args[2]));
			partiesElection.setElectionDate(partiesElection.parseStringToDate(args[2]));

			candidatesElection.loadEntitiesFromData();
			partiesElection.loadEntitiesFromData();
		}
		catch (ArrayIndexOutOfBoundsException exception) {
			System.out.println("Please enter the correct number of arguments (2 arguments)");
			System.out.println(exception);
		}
	}

}
