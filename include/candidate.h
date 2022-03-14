#ifndef CANDIDATE_H

	#define CANDIDATE_H

	#include <iostream>
	#include <string>
	#include <list>
	#include <ctime>
	#include <locale>
	#include "./party.h"

	using namespace std;


	class Candidate {
		private:
			// * Members
			int number = 0;
			int politicalPartyNumber = 0;
			string name = "";
			string ballotBoxAlias = "";
			int votes = 0;
			string votesDestiny = "";
			string situation = "";
			char gender = ' ';
			time_t birthDate = 0;
			int position = 0;


		public:
			// ! Constructor(s) and Destructor
			Candidate(string ballotBoxAlias);
			~Candidate();


			// ? Member Functions
			void displayCandidateInfo();

			int getNumber();
			void setNumber(int number);

			int getPoliticalPartyNumber();
			void setPoliticalPartyNumber(int politicalPartyNumber);
			string getPoliticalPartyNameByNumber(list<Party> parties);
			string getPoliticalPartyAliasByNumber(list<Party> parties);

			string getName();
			void setName(string name);

			string getBallotBoxAlias();
			void setBallotBoxAlias(string ballotBoxAlias);

			int getVotes();
			void setVotes(int votes);
			void addVotes(int votes);

			string getVotesDestiny();
			void setVotesDestiny(string votesDestiny);

			string getSituation();
			void setSituation(string situation);

			char getGender();
			void setGender(char gender);

			time_t getBirthDate();
			void setBirthDate(time_t birthDate);

			int getPosition();
			void setPosition(int position);
	};

#endif // CANDIDATE_H
