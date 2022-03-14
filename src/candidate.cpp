#include "../include/candidate.h"


Candidate::Candidate(string ballotBoxAlias) {
	this->ballotBoxAlias = ballotBoxAlias;
}


void Candidate::displayCandidateInfo() {
	cout << "Candidate alias: " << ballotBoxAlias << endl;
	cout << "Candidate number: " << number << endl;
	cout << "Candidate name: " << name << endl;
	cout << "Candidate votes: " << votes << endl;
	cout << "Candidate votes destiny: " << votesDestiny << endl;
	cout << "Candidate situation: " << situation << endl;
	cout << "Candidate political party number: " << politicalPartyNumber << endl;
	cout << "Candidate gender: " << gender << endl;
	Election info = new Election();
	cout << "Candidate birthdate: " << info.parseDateTostring(birthDate) << endl;
	cout << "Candidate position: " << position << endl;
	cout << "\n";
}

int Candidate::getNumber() {
	return number;
}
void Candidate::setNumber(int number) {
	this->number = number;
}

int Candidate::getPoliticalPartyNumber() {
	return politicalPartyNumber;
}
void Candidate::setPoliticalPartyNumber(int politicalPartyNumber) {
	this->politicalPartyNumber = politicalPartyNumber;
}
string getPoliticalPartyNameByNumber(list<Party> parties) {
	for (Party party : parties) {
		if (party.getNumber() == politicalPartyNumber) {
			return party.getName();
		}
	}
	return "";
}
string Candidate::getPoliticalPartyAliasByNumber(list<Party> parties) {
	for (Party party : parties) {
		if (party.getNumber() == politicalPartyNumber) {
			return party.getAlias();
		}
	}
	return "";
}

string Candidate::getName() {
	return name;
}
void Candidate::setName(string name) {
	this->name = name;
}

string Candidate::getBallotBoxAlias() {
	return ballotBoxAlias;
}
void Candidate::setBallotBoxAlias(string ballotBoxAlias) {
	this->ballotBoxAlias = ballotBoxAlias;
}

int Candidate::getVotes() {
	return votes;
}
void Candidate::setVotes(int votes) {
	this->votes = votes;
}
void Candidate::addVotes(int votes) {
	this->votes += votes;
}

string Candidate::getVotesDestiny() {
	return votesDestiny;
}
void Candidate::setVotesDestiny(string votesDestiny) {
	this->votesDestiny = votesDestiny;
}

string Candidate::getSituation() {
	return situation;
}
void Candidate::setSituation(string situation) {
	this->situation = situation;
}

char Candidate::getGender() {
	return gender;
}
void Candidate::setGender(char gender) {
	this->gender = gender;
}

time_t Candidate::getBirthDate() {
	return birthDate;
}
void Candidate::setBirthDate(time_t birthDate) {
	this->birthDate = birthDate;
}

int Candidate::getPosition() {
	return position;
}
void Candidate::setPosition(int position) {
	this->position = position;
}
