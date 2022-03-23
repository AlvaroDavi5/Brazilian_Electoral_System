#include "../include/reports.h"


Reports::Reports(Election &election) {
	this->electionInfo = election;
}
Reports::~Reports() {
	//// do nothing
}


const string& Reports::getPoliticalPartyNameByNumber(vector<Party*> parties, int politicalPartyNumber) {
	const string& defaultStr = "";

	for (Party* party : parties) {
		if (party->getNumber() == politicalPartyNumber) {
			return party->getName();
		}
	}
	return defaultStr;
}
const string& Reports::getPoliticalPartyAliasByNumber(vector<Party*> parties, int politicalPartyNumber) {
	const string& defaultStr = "";

	for (Party* party : parties) {
		if (party->getNumber() == politicalPartyNumber) {
			return party->getAlias();
		}
	}
	return defaultStr;
}

void Reports::displayNumberOfElectedCandidates() {
	cout << "Número de vagas: " << electionInfo.getNumberOfElectedCandidates() << endl;
	cout << endl;
}

void Reports::displayElectedCandidates() {
	cout << "Vereadores eleitos:" << endl;
	for (int i = 0; i < (int)electionInfo.getElectedCandidates().size(); i++) {
		Candidate* candidate = electionInfo.getElectedCandidates()[i];
		string votesOnSingularOrPlural = " votos)";
		if (candidate->getVotes() <= 0) {
			votesOnSingularOrPlural = " voto)";
		}
		cout << i+1 << " - " << candidate->getName() << " / " << candidate->getBallotBoxAlias() <<	" (" << getPoliticalPartyAliasByNumber(electionInfo.getParties(), candidate->getPoliticalPartyNumber()) << ", " << candidate->getVotes() << votesOnSingularOrPlural << endl;
	}
	cout << endl;
}

void Reports::displayMostVotedCandidates() {
	cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
	for (Candidate* candidate : electionInfo.getMostVotedCandidates()) {
		string votesOnSingularOrPlural = " votos)";
		if (candidate->getVotes() <= 0) {
			votesOnSingularOrPlural = " voto)";
		}
		cout << candidate->getPosition() << " - " << candidate->getName() << " / " << candidate->getBallotBoxAlias() << " (" << getPoliticalPartyAliasByNumber(electionInfo.getParties(), candidate->getPoliticalPartyNumber()) << ", " << candidate->getVotes() << votesOnSingularOrPlural << endl;
	}
	cout << endl;
}

void Reports::displayMostVotedAndNotElectedCandidates() {
	cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << endl;
	for (Candidate* candidate : electionInfo.getMostVotedAndNotElectedCandidates()) {
		string votesOnSingularOrPlural = " votos)";
		if (candidate->getVotes() <= 0) {
			votesOnSingularOrPlural = " voto)";
		}
		cout << candidate->getPosition() << " - " << candidate->getName() << " / " << candidate->getBallotBoxAlias() << " (" << getPoliticalPartyAliasByNumber(electionInfo.getParties(), candidate->getPoliticalPartyNumber()) << ", " << candidate->getVotes() << votesOnSingularOrPlural << endl;
	}
	cout << endl;
}

void Reports::displayElectedButNotMostVotedCandidates() {
	cout << "Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;
	for (Candidate* candidate : electionInfo.getElectedButNotMostVotedCandidates()) {
		string votesOnSingularOrPlural = " votos)";
		if (candidate->getVotes() <= 0) {
			votesOnSingularOrPlural = " voto)";
		}
		cout << candidate->getPosition() << " - " << candidate->getName() << " / " << candidate->getBallotBoxAlias() << " (" << getPoliticalPartyAliasByNumber(electionInfo.getParties(), candidate->getPoliticalPartyNumber()) << ", " << candidate->getVotes() << votesOnSingularOrPlural << endl;
	}
	cout << endl;
}

void Reports::displayPartiesTotalVotes() {
	cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
	for (int i = 0; i < (int)electionInfo.getPartiesOrderedByTotalVotes().size(); i++) {
		Party* party = electionInfo.getPartiesOrderedByTotalVotes()[i];
		string candidatesOnSingularOrPlural = " candidatos eleitos";
		vector<string> votesOnSingularOrPlural = {" votos", " nominais"};
		if (electionInfo.getElectedCandidatesNumberFromParty(*party) <= 1) {
			candidatesOnSingularOrPlural = " candidato eleito";
		}
		if (party->getTotalVotes() <= 1) {
			vector<string> votesOnSingularOrPlural = {" voto", " nominal"};
		}
		cout << i+1 << " - " << party->getAlias() << " - " << party->getNumber() << ", " << party->getTotalVotes() << votesOnSingularOrPlural[0] << " (" << (party->getTotalVotes() - party->getPartyVotes()) << votesOnSingularOrPlural[1] << " e " << party->getPartyVotes() << " de legenda), " << electionInfo.getElectedCandidatesNumberFromParty(*party) << candidatesOnSingularOrPlural << endl;
	}
	cout << endl;
}

void Reports::displayPartiesVotes() {
	cout << fixed;
	cout << setprecision(2);
	cout << "Votação dos partidos (apenas votos de legenda):" << endl;
	for (int i = 0; i < (int)electionInfo.getPartiesOrderedByPartyVotes().size(); i++) {
		Party* party = electionInfo.getPartiesOrderedByPartyVotes()[i];
		if (party->getPartyVotes() <= 0) {
			cout << i+1 << " - " << party->getAlias() << " - " << party->getNumber() << ", " << party->getPartyVotes() << " voto de legenda (proporção não calculada, 0 voto no partido)" << endl;
		}
		else {
			cout << i+1 << " - " << party->getAlias() << " - " << party->getNumber() << ", " << party->getPartyVotes() << " votos de legenda (" << electionInfo.getPartyVotesPercent(*party) << "%% do total do partido)" << endl;
		}
	}
	cout << endl;
}

void Reports::displayPartiesCandidates() {
	cout << "Primeiro e último colocados de cada partido:" << endl;
	for (int i = 0; i < (int)electionInfo.getPartiesWithCandidatesOrderedByVotes().size(); i++) {
		Party* party = electionInfo.getPartiesWithCandidatesOrderedByVotes()[i];
		Candidate* firstCandidate = party->getCandidates()[0];
		Candidate* lastCandidate = party->getCandidates()[(party->getCandidates().size()-1)];
		for (Candidate* actualCandidate : party->getCandidates()) {
			if (actualCandidate->getVotesDestiny() == "Válido") {
				firstCandidate = actualCandidate;
				break;
			}
		}
		for (int k = party->getCandidates().size() -1; k >= 0; k--) {
			Candidate* actualCandidate = party->getCandidates()[k];
			if (actualCandidate->getVotesDestiny() == "Válido") {
				lastCandidate = actualCandidate;
				break;
			}
		}
		if (!(firstCandidate->getVotesDestiny() == "Válido") && !(lastCandidate->getVotesDestiny() == "Válido")) {
			continue;
		}
		string firstCandidateVotesOnSingularOrPlural = " votos) / ";
		if (firstCandidate->getVotes() <= 1) {
			firstCandidateVotesOnSingularOrPlural = " voto) / ";
		}
		string lastCandidateVotesOnSingularOrPlural = " votos)";
		if (lastCandidate->getVotes() <= 1) {
			lastCandidateVotesOnSingularOrPlural = " voto)";
		}
		cout << i+1 << " - " << party->getAlias() << " - " << party->getNumber() << ", " << firstCandidate->getBallotBoxAlias() << " (" << firstCandidate->getNumber() << ", " << firstCandidate->getVotes() << firstCandidateVotesOnSingularOrPlural << lastCandidate->getBallotBoxAlias() << " (" << lastCandidate->getNumber() << ", " << lastCandidate->getVotes() << lastCandidateVotesOnSingularOrPlural << endl;
	}
	cout << endl;
}

void Reports::displayAgeOfElectedCandidates() {
	cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
	Utils utils = Utils();
	int age1 = 0, age2 = 0, age3 = 0, age4 = 0, age5 = 0, ageTotal = 0;
	for (Candidate* candidate : electionInfo.getElectedCandidates()) {
		int age = utils.calculateAge(
			candidate->getBirthDate(),
			electionInfo.getElectionDate()
		);
		if (age < 30) {
			age1++;
		}
		else if (30 <= age && age < 40) {
			age2++;
		}
		else if (40 <= age && age < 50) {
			age3++;
		}
		else if (50 <= age && age < 60) {
			age4++;
		}
		else {
			age5++;
		}
		ageTotal++;
	}
	cout << "      Idade < 30: " << age1 << " (" << ((float) age1 / ageTotal * 100) << "%%)" << endl;
	cout << "30 <= Idade < 40: " << age2 << " (" << ((float) age2 / ageTotal * 100) << "%%)" << endl;
	cout << "40 <= Idade < 50: " << age3 << " (" << ((float) age3 / ageTotal * 100) << "%%)" << endl;
	cout << "50 <= Idade < 60: " << age4 << " (" << ((float) age4 / ageTotal * 100) << "%%)" << endl;
	cout << "60 <= Idade     : " << age5 << " (" << ((float) age5 / ageTotal * 100) << "%%)" << endl;
	cout << endl;
}

void Reports::displayGenderOfElectedCandidates() {
	cout << "Eleitos, por sexo:" << endl;
	int male = 0, female = 0, total = 0;
	for (Candidate* candidate : electionInfo.getElectedCandidates()) {
		if (candidate->getGender() == 'M') {
			male++;
		}
		else {
			female++;
		}
		total++;
	}
	cout << "Feminino: " << female << " (" << electionInfo.getGeneralPercent(female, total) << "%%)" << endl;
	cout << "Masculino: " << male << " (" << electionInfo.getGeneralPercent(male, total) << "%%)" << endl;
	cout << endl;
}

void Reports::displayAllVotes() {
	cout << "Total de votos válidos:    " << electionInfo.getAmountOfTotalVotes() << endl;
	cout << "Total de votos nominais:   " << electionInfo.getAmountOfCandidatesVotes() << " (" << electionInfo.getGeneralPercent(electionInfo.getAmountOfCandidatesVotes(), electionInfo.getAmountOfTotalVotes()) << "%%)" << endl;
	cout << "Total de votos de legenda: " << electionInfo.getAmountOfPartyVotes() << " (" << electionInfo.getGeneralPercent(electionInfo.getAmountOfPartyVotes(), electionInfo.getAmountOfTotalVotes()) << "%%)" << endl;
}
