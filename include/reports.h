#ifndef REPORTS_H

	#define REPORTS_H

	#include <iostream>
	#include <iomanip>
	#include <string>
	#include "./utils.h"
	#include "./election.h"

	using namespace std;


	class Reports {
		private:
			// * Members
			Election electionInfo;


		public:
			// ! Constructor(s) and Destructor
			Reports(Election &election);
			~Reports();


			// ? Member Functions
			const string displayFloat(float f);

			const string& getPoliticalPartyNameByNumber(vector<Party*> parties, int politicalPartyNumber);
			const string& getPoliticalPartyAliasByNumber(vector<Party*> parties, int politicalPartyNumber);

			void displayNumberOfElectedCandidates();

			void displayElectedCandidates();

			void displayMostVotedCandidates();

			void displayMostVotedAndNotElectedCandidates();

			void displayElectedButNotMostVotedCandidates();

			void displayPartiesTotalVotes();

			void displayPartiesVotes();

			void displayPartiesCandidates();

			void displayAgeOfElectedCandidates();

			void displayGenderOfElectedCandidates();

			void displayAllVotes();
	};

#endif // REPORTS_H
