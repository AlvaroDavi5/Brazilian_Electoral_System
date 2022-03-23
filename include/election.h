#ifndef ELECTION_H

	#define ELECTION_H

	#include <iostream>
	#include <string>
	#include <cstring>
	#include <sstream>
	#include <fstream>
	#include <algorithm>
	#include <vector>
	#include <ctime>
	#include "./candidate.h"
	#include "./party.h"
	#include "./utils.h"
	#include "./comparators.h"

	using namespace std;


	class Election {
		private:
			// * Members
			string data = "";
			char entity = '\0';
			time_t electionDate = -1;
			vector<Candidate*> candidates;
			vector<Party*> parties;


		public:
			// ! Constructor(s) and Destructor

			Election();
			// TODO: ~Election();


			// ? Member Functions
			const string& getData();
			void setData(const string &newData);
			void addData(string &newData);

			const char getEntity();
			void setEntity(const char newEntity);

			const time_t getElectionDate();
			void setElectionDate(const time_t newElectionDate);

			vector<Candidate*> getCandidates();
			void setCandidates(vector<Candidate*> newCandidates);
			void addCandidate(Candidate &newCandidate);

			vector<Party*> getParties();
			void setParties(vector<Party*> newParties);
			void addParty(Party &newParty);

			void readFile(string path, Election &eleInfo);
			bool loadEntitiesFromData();

			vector<Candidate*> getCandidatesByParty(int partyNumber);

			void PopulatePartiesCandidatesList();

			vector<Candidate*> getElectedCandidates();

			const int getNumberOfElectedCandidates();

			vector<Candidate*> getCandidatesOrderedByVotes();

			vector<Candidate*> getMostVotedCandidates();

			vector<Candidate*> getMostVotedAndNotElectedCandidates();

			vector<Candidate*> getElectedButNotMostVotedCandidates();

			vector<Party*> getPartiesOrderedByTotalVotes();

			const int getElectedCandidatesNumberFromParty(Party party);

			const float getPartyVotesPercent(Party party);

			const float getGeneralPercent(float p, float t);

			vector<Party*> getPartiesOrderedByPartyVotes();

			vector<Party*> getPartiesWithCandidatesOrderedByVotes();

			const int getAmountOfCandidatesVotes();

			const int getAmountOfPartyVotes();

			const int getAmountOfTotalVotes();
	};

#endif // ELECTION_H
