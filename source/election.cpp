#include "../include/election.h"


Election::Election() {
	//// do nothing
}

const string& Election::getData() {
	return data;
}
void Election::setData(const string &newData) {
	this->data = newData;
}
void Election::addData(string &newData) {
	this->data += newData + "\n";
}

const char Election::getEntity() {
	return entity;
}
void Election::setEntity(const char newEntity) {
	this->entity = newEntity;
}

const time_t Election::getElectionDate() {
	return electionDate;
}
void Election::setElectionDate(const time_t newElectionDate) {
	this->electionDate = newElectionDate;
}

vector<Candidate*> Election::getCandidates() {
	return candidates;
}
void Election::setCandidates(vector<Candidate*> newCandidates) {
	this->candidates = newCandidates;
}
void Election::addCandidate(Candidate &newCandidate) {
	this->candidates.push_back(&newCandidate);
}

vector<Party*> Election::getParties() {
	return parties;
}
void Election::setParties(vector<Party*> newParties) {
	this->parties = newParties;
}
void Election::addParty(Party &newParty) {
	this->parties.push_back(&newParty);
}

void Election::readFile(string path, Election &eleInfo) {
	Utils util = Utils();
	string line = "";
	bool firstLine = true;
	ifstream file;
	file.open(path);

	if (!file.is_open()) {
		cout << "Error opening file" << endl;
	}

	while (getline(file, line))
	{
		if (firstLine && line != "")
		{
			if (util.countColumns(line) == 4)
			{
				eleInfo.setEntity('p');
			}
			else
			{
				eleInfo.setEntity('c');
			}
			firstLine = false;
		}
		else
		{
			eleInfo.addData(line);
		}
	}

	file.close();
}
bool Election::loadEntitiesFromData() {
	Utils util = Utils();
	bool success = false;
	stringstream dataStream(getData());
	string line;
	vector<string> lines;

	while(getline(dataStream, line, '\n'))
	{
		lines.push_back(line);
	}

	try {
		for (int i = 0; i < (int)lines.size(); i++) {
			string lineData = lines[i];
			stringstream lineDataStream(lineData);
			string splitedData;
			vector<string> splitedLineData;

			while(getline(lineDataStream, splitedData, ','))
			{
				splitedLineData.push_back(splitedData);
			}


			for (int j = 0; j < (int)splitedLineData.size(); j++) {
				string trimmedData = splitedLineData[j];

				const string whiteSpaces = " \n\r\t\f\v";
				size_t startPos = trimmedData.find_first_not_of(whiteSpaces);
				trimmedData = (startPos == string::npos) ? "" : trimmedData.substr(startPos);
				size_t endPos = trimmedData.find_last_not_of(whiteSpaces);
				trimmedData = (endPos == string::npos) ? "" : trimmedData.substr(0, endPos + 1);

				splitedLineData[j] = trimmedData;
			}

			if (getEntity() == 'c') {
				Candidate* candidate = new Candidate(
					splitedLineData[4]
				);
				candidate->setNumber(
					stoi(splitedLineData[0])
				);
				candidate->setVotes(
					stoi(splitedLineData[1])
				);
				candidate->setSituation(splitedLineData[2]);
				candidate->setName(splitedLineData[3]);
				candidate->setGender(
					char((splitedLineData[5])[0])
				);
				size_t n = (splitedLineData[6]).size();
				char charBirthDate[n+1];
				strcpy(charBirthDate, splitedLineData[6].c_str());
				candidate->setBirthDate(
					util.parseStringToTime(charBirthDate)
				);
				candidate->setVotesDestiny(splitedLineData[7]);
				candidate->setPoliticalPartyNumber(
					stoi(splitedLineData[8])
				);

				addCandidate(*candidate);
				success = true;
			}
			else if (getEntity() == 'p') {
				Party* party = new Party(splitedLineData[3]);
				party->setNumber(
					stoi(splitedLineData[0])
				);
				party->setPartyVotes(
					stoi(splitedLineData[1])
				);
				party->setName(splitedLineData[2]);

				addParty(*party);
				success = true;
			}
			else {
				cout << "Error: entity not found" << endl;
				success = false;
			}
		}

		setEntity('\0');
		setData("");
	}
	catch (const exception e) {
		cout << "An unexpected error has ocurred!" << endl;
		cerr << e.what() << endl;
	}

	return success;
}

vector<Candidate*> Election::getCandidatesByParty(int partyNumber) {
	vector<Candidate*> candidatesByParty = vector<Candidate*>();

	for (int i = 0; i < (int)getCandidates().size(); i++) {
		Candidate* candidate = (getCandidates())[i];

		if (candidate->getPoliticalPartyNumber() == partyNumber) {
			candidatesByParty.push_back(candidate);
		}
	}

	return candidatesByParty;
}

void Election::PopulatePartiesCandidatesList() {
	for (int i = 0; i < (int)getParties().size(); i++) {
		Party* party = getParties()[i];


		party->setCandidates(
			getCandidatesByParty(party->getNumber())
		);

		for (Candidate* candidate : party->getCandidates()) {
			if (candidate->getVotesDestiny() == "Válido") {
				party->setTotalVotes(
					party->getTotalVotes() + candidate->getVotes()
				);
			}
		}
		party->setTotalVotes(
			party->getTotalVotes() + party->getPartyVotes()
		);
	}
}

vector<Candidate*> Election::getElectedCandidates() {
	vector<Candidate*> allCandidates = vector<Candidate*>();
	vector<Candidate*> electedCandidates = vector<Candidate*>();

	for (Candidate* candidate : getCandidates()) {
		allCandidates.push_back(candidate);
	}

	for (int i = 0; i < (int)allCandidates.size(); i++) {
		if (allCandidates[i]->getSituation() == "Eleito") {
			electedCandidates.push_back(allCandidates[i]);
		}
	}

	for (int i = 0; i < (int)electedCandidates.size(); i++) {
		for (int j = i+1; j < (int)electedCandidates.size(); j++) {
			if (electedCandidates[i]->getVotes() < electedCandidates[j]->getVotes()) {
				Candidate* aux = electedCandidates[i];
				electedCandidates[i] = electedCandidates[j];
				electedCandidates[j] = aux;
			}
		}
	}

	return electedCandidates;
}

const int Election::getNumberOfElectedCandidates() {
	return getElectedCandidates().size();
}

vector<Candidate*> Election::getCandidatesOrderedByVotes() {
	vector<Candidate*> allCandidates = vector<Candidate*>();
	vector<Candidate*> candidatesOrderedByVotes = vector<Candidate*>();

	for (Candidate* candidate : getCandidates()) {
		candidate->setPosition(0);
		allCandidates.push_back(candidate);
	}

	sort(*allCandidates.begin(), *allCandidates.end(), Comparator::CandidatesVotesComparator);

	for (int k = 0; k < (int)allCandidates.size(); k++) {
		Candidate* candidate = (allCandidates)[k];
		candidate->setPosition(k+1);
		candidatesOrderedByVotes.push_back(candidate);
	}

	return candidatesOrderedByVotes;
}

vector<Candidate*> Election::getMostVotedCandidates() {
	vector<Candidate*> allCandidates = vector<Candidate*>();
	vector<Candidate*> mostVotedCandidates = vector<Candidate*>();

	for (Candidate* candidate : getCandidatesOrderedByVotes()) {
		allCandidates.push_back(candidate);
	}

	for (int k = 0; k < getNumberOfElectedCandidates(); k++) {
		Candidate* candidate = allCandidates[k];
		mostVotedCandidates.push_back(candidate);
	}

	return mostVotedCandidates;
}

vector<Candidate*> Election::getMostVotedAndNotElectedCandidates() {
	vector<Candidate*> mostVotedAndNotElectedCandidates = vector<Candidate*>();

	for (Candidate* candidate : getMostVotedCandidates()) {
		if (!(candidate->getSituation() == "Eleito")) {
			mostVotedAndNotElectedCandidates.push_back(candidate);
		}
	}

	return mostVotedAndNotElectedCandidates;
}

vector<Candidate*> Election::getElectedButNotMostVotedCandidates() {
	Utils util = Utils();
	vector<Candidate*> electedButNotMostVotedCandidates = vector<Candidate*>();
	Candidate* lastMostVotedCandidate = getMostVotedCandidates()[
		(getMostVotedCandidates().size() - 1)
	];

	for (Candidate* candidate : getElectedCandidates()) {
		bool isTheSameCandidate = (lastMostVotedCandidate->getNumber() == candidate->getNumber());
		int isOlderThan = util.olderThan(lastMostVotedCandidate->getBirthDate(), candidate->getBirthDate());

		if (lastMostVotedCandidate->getVotes() > candidate->getVotes()) {
			electedButNotMostVotedCandidates.push_back(candidate);
		}
		else if (lastMostVotedCandidate->getVotes() == candidate->getVotes() && !isTheSameCandidate) {
			if (isOlderThan >= 0) {
				electedButNotMostVotedCandidates.push_back(candidate);
			}
			else {
				electedButNotMostVotedCandidates.push_back(lastMostVotedCandidate);
			}
		}
	}

	return electedButNotMostVotedCandidates;
}

vector<Party*> Election::getPartiesOrderedByTotalVotes() {
	vector<Party*> partiesOrderedByTotalVotes = vector<Party*>();

	for (Party* party : getParties()) {
		partiesOrderedByTotalVotes.push_back(party);
	}

	sort(*partiesOrderedByTotalVotes.begin(), *partiesOrderedByTotalVotes.end(), Comparator::PartiesTotalVotesComparator);

	return partiesOrderedByTotalVotes;
}

const int Election::getElectedCandidatesNumberFromParty(Party party) {
	int electedCandidatesFromParty = 0;

	for (Candidate* candidate : getElectedCandidates()) {
		if (candidate->getPoliticalPartyNumber() == party.getNumber()) {
			electedCandidatesFromParty++;
		}
	}

	return electedCandidatesFromParty;
}

const float Election::getPartyVotesPercent(Party party) {
	float partyVotesPercent = 0.00f;

	partyVotesPercent = (float) party.getPartyVotes() / (float) party.getTotalVotes();

	return partyVotesPercent * (float) 100;
}

const float Election::getGeneralPercent(float p, float t) {
	float r = 0.00f;

	r = (float) p / (float) t;

	return r * (float) 100;
}

vector<Party*> Election::getPartiesOrderedByPartyVotes() {
	vector<Party*> partiesOrderedByPartyVotes = vector<Party*>();

	for (Party* party : getParties()) {
		partiesOrderedByPartyVotes.push_back(party);
	}

	sort(*partiesOrderedByPartyVotes.begin(), *partiesOrderedByPartyVotes.end(), Comparator::PartiesPartyVotesComparator );

	return partiesOrderedByPartyVotes;
}

vector<Party*> Election::getPartiesWithCandidatesOrderedByVotes() {
	vector<Party*> parties = vector<Party*>();

	for (Party* party : getParties()) {
		parties.push_back(party);
	}

	for (Party* party : parties) {
		vector<Candidate*> candidates = party->getCandidates();
		sort(*candidates.begin(),*candidates.end(), Comparator::CandidatesVotesComparator );
	}
	sort(*parties.begin(), *parties.end(), Comparator::PartiesCandidateVotesComparator );

	return parties;
}

const int Election::getAmountOfCandidatesVotes() {
	int amountOfCandidatesVotes = 0;

	for (Candidate* candidate : getCandidates()) {
		if (candidate->getVotesDestiny() == "Válido") {
			amountOfCandidatesVotes += candidate->getVotes();
		}
	}

	return amountOfCandidatesVotes;
}

const int Election::getAmountOfPartyVotes() {
	int amountOfPartyVotes = 0;

	for (Party* party : getParties()) {
		amountOfPartyVotes += party->getPartyVotes();
	}

	return amountOfPartyVotes;
}

const int Election::getAmountOfTotalVotes() {
	return getAmountOfCandidatesVotes() + getAmountOfPartyVotes();
}
