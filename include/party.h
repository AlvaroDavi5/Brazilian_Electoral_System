#ifndef PARTY_H

	#define PARTY_H

	#include <iostream>
	#include <string>
	#include <vector>
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
			vector<Candidate*> candidates;


		public:
			// ! Constructor(s) and Destructor
			Party(const string &alias);
			~Party();


			// ? Member Functions
			void displayPartyInfo();

			const int getNumber();
			void setNumber(const int number);

			const string& getName();
			void setName(const string &name);

			const string& getAlias();
			void setAlias(const string &alias);

			const int getPartyVotes();
			void setPartyVotes(const int votes);

			const int getTotalVotes();
			void setTotalVotes(const int votes);

			vector<Candidate*> getCandidates();
			void setCandidates(vector<Candidate*> candidates);
			void addCandidate(Candidate &candidate);
			void removeCandidate(Candidate &candidate);
	};

#endif // PARTY_H
