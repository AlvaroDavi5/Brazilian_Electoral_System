package src;
import src.classes.*;
import java.io.IOException;
import java.lang.ArrayIndexOutOfBoundsException;


public class Main {

	// main static method
	public static void main(String[] args) throws IOException {
		try {
			Utils utils = new Utils();
			Election election = new Election();

			utils.readFile(args[0], election);
			election.loadEntitiesFromData();

			utils.readFile(args[1], election);
			election.loadEntitiesFromData();

			election.setElectionDate(
				election.parseStringToDate(args[2])
			);
			election.PopulatePartiesCandidatesList();

			Reports reports = new Reports(election);

			reports.displayNumberOfElectedCandidates();
			reports.displayElectedCandidates();
			reports.displayMostVotedCandidates();
			reports.displayMostVotedAndNotElectedCandidates();
			reports.displayElectedButNotMostVotedCandidates();
			reports.displayPartiesTotalVotes();
			reports.displayPartiesVotes();
			reports.displayPartiesCandidates();
			reports.displayAgeOfElectedCandidates();
			reports.displayGenderOfElectedCandidates();
			reports.displayAllVotes();
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Please enter the correct number of arguments (3 arguments)");
		}
		catch (Exception exception) {
			System.out.println(exception);
		}
	}

}
