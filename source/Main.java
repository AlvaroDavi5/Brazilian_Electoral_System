package source;
import source.classes.*;
import java.io.IOException;
import java.lang.ArrayIndexOutOfBoundsException;


public class Main {

	public static void main(String[] args) throws IOException {
		try {
			Utils util = new Utils();
			Election election = new Election();

			util.readFile(args[0], election);
			election.loadEntitiesFromData();

			util.readFile(args[1], election);
			election.loadEntitiesFromData();

			election.setElectionDate(
				election.parseStringToDate(args[2])
			);
			election.PopulatePartiesCandidatesList();

			Reports reports = new Reports(election);
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Please enter the correct number of arguments (3 arguments)");
		}
		catch (Exception exception) {
			System.out.println(exception);
		}
	}

}
