#include "../include/candidate.h"


Candidate::Candidate(const string &ballotBoxAlias) {
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
	Utils util = Utils();
	cout << "Candidate birthdate: " << util.parseTimeToString(birthDate) << endl;
	cout << "Candidate position: " << position << endl;
	cout << "\n";
}

const int Candidate::getNumber() {
	return number;
}
void Candidate::setNumber(const int number) {
	this->number = number;
}

const int Candidate::getPoliticalPartyNumber() {
	return politicalPartyNumber;
}
void Candidate::setPoliticalPartyNumber(const int politicalPartyNumber) {
	this->politicalPartyNumber = politicalPartyNumber;
}

const string& Candidate::getName() {
	return name;
}
void Candidate::setName(const string &name) {
	this->name = name;
}

const string& Candidate::getBallotBoxAlias() {
	return ballotBoxAlias;
}
void Candidate::setBallotBoxAlias(const string &ballotBoxAlias) {
	this->ballotBoxAlias = ballotBoxAlias;
}

const int Candidate::getVotes() {
	return votes;
}
void Candidate::setVotes(const int votes) {
	this->votes = votes;
}
void Candidate::addVotes(const int votes) {
	this->votes += votes;
}

const string& Candidate::getVotesDestiny() {
	return votesDestiny;
}
void Candidate::setVotesDestiny(const string &votesDestiny) {
	this->votesDestiny = votesDestiny;
}

const string& Candidate::getSituation() {
	return situation;
}
void Candidate::setSituation(const string &situation) {
	this->situation = situation;
}

const char Candidate::getGender() {
	return gender;
}
void Candidate::setGender(char gender) {
	this->gender = gender;
}

const time_t Candidate::getBirthDate() {
	return birthDate;
}
void Candidate::setBirthDate(time_t birthDate) {
	this->birthDate = birthDate;
}

const int Candidate::getPosition() {
	return position;
}
void Candidate::setPosition(const int position) {
	this->position = position;
}
