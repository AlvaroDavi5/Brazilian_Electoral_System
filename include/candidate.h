#ifndef CANDIDATE_H

	#define CANDIDATE_H

	#include <iostream>
	#include <string>
	#include <vector>
	#include <ctime>
	#include "./utils.h"

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
			Candidate(const string &ballotBoxAlias);
			// TODO: ~Candidate();


			// ? Member Functions
			void displayCandidateInfo();

			const int getNumber();
			void setNumber(const int number);

			const int getPoliticalPartyNumber();
			void setPoliticalPartyNumber(const int politicalPartyNumber);

			const string& getName();
			void setName(const string &name);

			const string& getBallotBoxAlias();
			void setBallotBoxAlias(const string &ballotBoxAlias);

			const int getVotes();
			void setVotes(const int votes);
			void addVotes(const int votes);

			const string& getVotesDestiny();
			void setVotesDestiny(const string &votesDestiny);

			const string& getSituation();
			void setSituation(const string &situation);

			const char getGender();
			void setGender(char gender);

			const time_t getBirthDate();
			void setBirthDate(time_t birthDate);

			const int getPosition();
			void setPosition(const int position);
	};

#endif // CANDIDATE_H
