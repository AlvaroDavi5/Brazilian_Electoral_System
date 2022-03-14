#ifndef PARTY_H

	#define PARTY_H

	#include <iostream>
	#include <string>
	#include <list>
	#include <ctime>
	#include <locale>
	#include "./candidate.h"

	using namespace std;


	class Party {
		private:
			// * Members
			int number = 0;
			string name = "";
			string alias = "";
			int partyVotes = 0;
			int totalVotes = 0;
			list<Candidate> candidates;


		public:
			// ! Constructor(s) and Destructor
			Party(string alias);
			~Party();


			// ? Member Functions
			void displayPartyInfo();

			int getNumber();
			void setNumber(int number);

			string getName();
			void setName(string name);

			string getAlias();
			void setAlias(string alias);

			int getPartyVotes();
			void setPartyVotes(int votes);

			int getTotalVotes();
			void setTotalVotes(int votes);

			list<Candidate> getCandidates();
			void setCandidates(list<Candidate> candidates);
	};

#endif // PARTY_H
