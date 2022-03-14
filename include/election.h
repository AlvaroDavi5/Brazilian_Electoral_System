#ifndef ELECTION_H

	#define ELECTION_H

	#include <iostream>
	#include <string>
	#include <list>
	#include <ctime>
	#include <locale>
	#include "./candidate.h"
	#include "./party.h"

	using namespace std;


	class Election {
		private:
			// * Members
			string data = "";
			char entity = '\0';
			time_t electionDate = -1;
			list<Candidate> candidates;
			list<Party> parties;


		public:
			// ! Constructor(s) and Destructor
			~Election();


			// ? Member Functions
			time_t parseStringToDate(string strDate);
			string parseDateToString(time_t date);

			string getData();
			void setData(string newData);
			void addData(string newData);

			char getEntity();
			void setEntity(char newEntity);

			time_t getElectionDate();
			void setElectionDate(time_t newElectionDate);

			list<Candidate> getCandidates();
			void setCandidates(list<Candidate> newCandidates);
			void addCandidate(Candidate newCandidate);

			list<Party> getParties();
			void setParties(list<Party> newParties);
			void addParty(Party newParty);

			bool loadEntitiesFromData();

			list<Candidate> getCandidatesByParty(int partyNumber);

			void PopulatePartiesCandidatesList();

			list<Candidate> getElectedCandidates();

			int getNumberOfElectedCandidates();

			list<Candidate> getCandidatesOrderedByVotes();

			list<Candidate> getMostVotedCandidates();

			list<Candidate> getMostVotedAndNotElectedCandidates();

			list<Candidate> getElectedButNotMostVotedCandidates();

			list<Party> getPartiesOrderedByTotalVotes();

			float getPartyVotesPercent(Party party);

			float getGeneralPercent(float p, float t);

			list<Party> getPartiesOrderedByPartyVotes();

			list<Party> getPartiesWithCandidatesOrderedByVotes();

			int getAmountOfCandidatesVotes();

			int getAmountOfPartyVotes();

			int getAmountOfTotalVotes();
	};

#endif // ELECTION_H
