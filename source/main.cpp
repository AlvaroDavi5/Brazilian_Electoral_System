#include <iostream>
#include <locale>
#include "../include/election.h"
#include "../include/utils.h"
#include "../include/reports.h"


using namespace std;


int main(int argc, char *argv[]) {

  setlocale(LC_NUMERIC, "pt_BR");
	auto loc = locale("pt_BR.UTF-8");
	locale::global(loc);

	try {
		if (argc < 4) {
			cout << "Please enter the correct number of arguments (3 arguments)" << endl;
			return 1;
		}

		Utils util = Utils();
		Election election = Election();

		election.readFile(argv[1], election);
		election.loadEntitiesFromData();

		election.readFile(argv[2], election);
		election.loadEntitiesFromData();

		election.setElectionDate(
			util.parseStringToTime(argv[3])
		);
		election.PopulatePartiesCandidatesList();

		Reports reports = Reports(election);

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
	catch (const exception* e) {
		cout << "An unexpected error has ocurred!" << endl;
		cerr << e->what() << endl;
	}

	cout.imbue(locale("C"));

	return 0;
}
