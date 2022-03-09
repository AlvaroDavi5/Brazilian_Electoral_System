/*
  - Faltou o locale
  - Associações não estão corretas no diagrama de classes
  - Usou pacote "src.classes", que confunde toda a organização das pastas. Não usou election date, recalculou idade com base em datas representadas em strings
  - Tornar repositório do github privado, ArrayIndexOutOfBoundsException não deveria ter tratada, deveria ser evitada. Deveria ter mais comentários
*/


#include <iostream>
#include <string>
#include <locale>
#include "../include/election.h"
#include "../include/utils.h"
#include "../include/reports.h"

using namespace std;


int main(int argc, char *argv[]) {
	setlocale(LC_CTYPE, "");

	try {
		if (argc < 4) {
			cout << "Please enter the correct number of arguments (3 arguments)";
			return 1;
		}

		Utils utils = new Utils();
		Election election = new Election();

		utils.readFile(argv[1], election);
		election.loadEntitiesFromData();

		utils.readFile(argv[2], election);
		election.loadEntitiesFromData();

		election.setElectionDate(
			election.parseStringToDate(argv[3])
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
	catch (exception e) {
		cout << "An unexpected error has ocurred!";
	}

	return 0;
}

