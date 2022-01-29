package source;
import source.classes.*;
import java.io.IOException;
import java.lang.ArrayIndexOutOfBoundsException;


public class Main {

	public static void main(String[] args) throws IOException {
		Election election = new Election();

		try {
			Utils util = new Utils();
			Election candidatesElection = util.readFile(args[0]);
			Election partiesElection = util.readFile(args[1]);

			candidatesElection.loadEntitiesFromData();
			partiesElection.loadEntitiesFromData();

			election.setCandidates(
				candidatesElection.getCandidates()
			);
			election.setParties(
				partiesElection.getParties()
			);
			election.setElectionDate(
				election.parseStringToDate(args[2])
			);
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Please enter the correct number of arguments (2 arguments)");
		}
		catch (Exception exception) {
			System.out.println(exception);
		}
	}

}
