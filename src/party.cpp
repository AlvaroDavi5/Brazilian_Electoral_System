#include "../include/party.h"


Party::Party(string alias) {
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

int Party::getNumber() {
	return number;
}
void Party::setNumber(int number) {
	this->number = number;
}

string Party::getName() {
	return name;
}
void Party::setName(string name) {
	this->name = name;
}

string Party::getAlias() {
	return alias;
}
void Party::setAlias(string alias) {
	this->alias = alias;
}

int Party::getPartyVotes() {
	return partyVotes;
}
void Party::setPartyVotes(int votes) {
	this->partyVotes = votes;
}

int Party::getTotalVotes() {
	return totalVotes;
}
void Party::setTotalVotes(int votes) {
	this->totalVotes = votes;
}

list<Candidate> Party::getCandidates() {
	return candidates;
}
void Party::setCandidates(list<Candidate> candidates) {
	this->candidates = candidates;
}
