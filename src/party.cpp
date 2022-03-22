#include "../include/party.h"


Party::Party(const string &alias) {
	this->alias = alias;
}


void Party::displayPartyInfo() {
	cout << "Party alias: " << alias << endl;
	cout << "Party number: " << number << endl;
	cout << "Party name: " << name << endl;
	cout << "Party votes: " << partyVotes << endl;
	cout << "Total votes: " << totalVotes << endl;
	cout << "\n";
}

const int Party::getNumber() {
	return number;
}
void Party::setNumber(const int number) {
	this->number = number;
}

const string& Party::getName() {
	return name;
}
void Party::setName(const string &name) {
	this->name = name;
}

const string& Party::getAlias() {
	return alias;
}
void Party::setAlias(const string &alias) {
	this->alias = alias;
}

const int Party::getPartyVotes() {
	return partyVotes;
}
void Party::setPartyVotes(const int votes) {
	this->partyVotes = votes;
}

const int Party::getTotalVotes() {
	return totalVotes;
}
void Party::setTotalVotes(const int votes) {
	this->totalVotes = votes;
}

vector<Candidate*> Party::getCandidates() {
	return candidates;
}
void Party::setCandidates(vector<Candidate*> candidates) {
	this->candidates = candidates;
}
void addCandidate(Candidate &candidate) {
	candidates.push_back(&candidate);
}
void removeCandidate(Candidate &candidate) {
	candidates.remove(&candidate);
}
