#ifndef REPORTS_H

	#define REPORTS_H

	#include <iostream>
	#include <string>
	#include <list>
	#include <ctime>
	#include <locale>
	#include "./election.h"

	using namespace std;


	class Reports {
		private:
			// * Members
			Election electionInfo;


		public:
			// ! Constructor(s) and Destructor
			Reports(Election election);
			~Reports();


			// ? Member Functions
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
