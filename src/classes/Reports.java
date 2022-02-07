package src.classes;
import src.Election;


public class Reports {
	// attributes
	private Election electionInfo = null;


	// constructor method
	public Reports(Election election) {
		this.electionInfo = election;
	}


	// methods
	public void displayNumberOfElectedCandidates() {
		System.out.println("Número de vagas: " + electionInfo.getNumberOfElectedCandidates());
		System.out.println();
	}

	public void displayElectedCandidates() {
		System.out.println("Vereadores eleitos:");
		for (int i = 0; i < electionInfo.getElectedCandidates().size(); i++) {
			Candidate candidate = electionInfo.getElectedCandidates().get(i);
			String votesOnSingularOrPlural = " votos)";
			if (candidate.getVotes() <= 0) {
				votesOnSingularOrPlural = " voto)";
			}
			System.out.println(
				i+1 + " - " +
				candidate.getName() + " / " + candidate.getBallotBoxAlias() +
				" (" +
				candidate.getPoliticalPartyAliasByNumber(
					electionInfo.getParties()
				)
				+ ", " + candidate.getVotes() + votesOnSingularOrPlural
			);
		}
		System.out.println();
	}

	public void displayMostVotedCandidates() {
		System.out.println("Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
		for (Candidate candidate : electionInfo.getMostVotedCandidates()) {
			String votesOnSingularOrPlural = " votos)";
			if (candidate.getVotes() <= 0) {
				votesOnSingularOrPlural = " voto)";
			}
			System.out.println(
				candidate.getPosition() + " - " +
				candidate.getName() + " / " + candidate.getBallotBoxAlias() +
				" (" +
				candidate.getPoliticalPartyAliasByNumber(
					electionInfo.getParties()
				)
				+ ", " + candidate.getVotes() + votesOnSingularOrPlural
			);
		}
		System.out.println();
	}

	public void displayMostVotedAndNotElectedCandidates() {
		System.out.println("Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)");
		for (Candidate candidate : electionInfo.getMostVotedAndNotElectedCandidates()) {
			String votesOnSingularOrPlural = " votos)";
			if (candidate.getVotes() <= 0) {
				votesOnSingularOrPlural = " voto)";
			}
			System.out.println(
				candidate.getPosition() + " - " +
				candidate.getName() + " / " + candidate.getBallotBoxAlias() +
				" (" +
				candidate.getPoliticalPartyAliasByNumber(
					electionInfo.getParties()
				)
				+ ", " + candidate.getVotes() + votesOnSingularOrPlural
			);
		}
		System.out.println();
	}

	public void displayElectedButNotMostVotedCandidates() {
		System.out.println("Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)");
		for (Candidate candidate : electionInfo.getElectedButNotMostVotedCandidates()) {
			String votesOnSingularOrPlural = " votos)";
			if (candidate.getVotes() <= 0) {
				votesOnSingularOrPlural = " voto)";
			}
			System.out.println(
				candidate.getPosition() + " - " +
				candidate.getName() + " / " + candidate.getBallotBoxAlias() +
				" (" +
				candidate.getPoliticalPartyAliasByNumber(
					electionInfo.getParties()
				)
				+ ", " + candidate.getVotes() + votesOnSingularOrPlural
			);
		}
		System.out.println();
	}

	public void displayPartiesTotalVotes() {
		System.out.println("Votação dos partidos e número de candidatos eleitos:");
		for (int i = 0; i < electionInfo.getPartiesOrderedByTotalVotes().size(); i++) {
			Party party = electionInfo.getPartiesOrderedByTotalVotes().get(i);
			String candidatesOnSingularOrPlural = " candidatos eleitos";
			String[] votesOnSingularOrPlural = {" votos", " nominais"};
			if (electionInfo.getElectedCandidatesNumberFromParty(party) <= 1) {
				candidatesOnSingularOrPlural = " candidato eleito";
			}
			if (party.getTotalVotes() <= 1) {
				votesOnSingularOrPlural = new String[] {" voto", " nominal"};
			}
			System.out.println(
				i+1 + " - " + party.getAlias() + " - " + party.getNumber() +
				", " + party.getTotalVotes() + votesOnSingularOrPlural[0] + " (" + (party.getTotalVotes() - party.getPartyVotes()) + votesOnSingularOrPlural[1] + " e " + party.getPartyVotes() + " de legenda), " +
				electionInfo.getElectedCandidatesNumberFromParty(party) + candidatesOnSingularOrPlural
			);
		}
		System.out.println();
	}

	public void displayPartiesVotes() {
		System.out.println("Votação dos partidos (apenas votos de legenda):");
		for (int i = 0; i < electionInfo.getPartiesOrderedByPartyVotes().size(); i++) {
			Party party = electionInfo.getPartiesOrderedByPartyVotes().get(i);
			if (party.getPartyVotes() <= 0) {
				System.out.printf("%d - %s - %d, %d voto de legenda (proporção não calculada, 0 voto no partido)\n",
					i+1, party.getAlias(), party.getNumber(), party.getPartyVotes()
				);
			}
			else {
				System.out.printf("%d - %s - %d, %d votos de legenda (%.2f%% do total do partido)\n",
					i+1, party.getAlias(), party.getNumber(), party.getPartyVotes(), electionInfo.getPartyVotesPercent(party)
				);
			}
		}
		System.out.println();
	}

	public void displayPartiesCandidates() {
		System.out.println("Primeiro e último colocados de cada partido:");
		for (int i = 0; i < electionInfo.getPartiesWithCandidatesOrderedByVotes().size(); i++) {
			Party party = electionInfo.getPartiesWithCandidatesOrderedByVotes().get(i);
			Candidate firstCandidate = party.getCandidates().get(0);
			Candidate lastCandidate = party.getCandidates().get(party.getCandidates().size()-1);
			for (Candidate actualCandidate : party.getCandidates()) {
				if (actualCandidate.getVotesDestiny().equals("Válido")) {
					firstCandidate = actualCandidate;
					break;
				}
			}
			for (int k = party.getCandidates().size() -1; k >= 0; k--) {
				Candidate actualCandidate = party.getCandidates().get(k);
				if (actualCandidate.getVotesDestiny().equals("Válido")) {
					lastCandidate = actualCandidate;
					break;
				}
			}
			if (!firstCandidate.getVotesDestiny().equals("Válido") && !lastCandidate.getVotesDestiny().equals("Válido")) {
				continue;
			}
			String firstCandidateVotesOnSingularOrPlural = " votos) / ";
			if (firstCandidate.getVotes() <= 1) {
				firstCandidateVotesOnSingularOrPlural = " voto) / ";
			}
			String lastCandidateVotesOnSingularOrPlural = " votos)";
			if (lastCandidate.getVotes() <= 1) {
				lastCandidateVotesOnSingularOrPlural = " voto)";
			}
			System.out.println(i+1 + " - " + party.getAlias() + " - " + party.getNumber() + ", " +
				firstCandidate.getBallotBoxAlias() + " (" + firstCandidate.getNumber() + ", " + firstCandidate.getVotes() + firstCandidateVotesOnSingularOrPlural +
				lastCandidate.getBallotBoxAlias() + " (" + lastCandidate.getNumber() + ", " + lastCandidate.getVotes() + lastCandidateVotesOnSingularOrPlural
			);
		}
		System.out.println();
	}

	public void displayAgeOfElectedCandidates() {
		System.out.println("Eleitos, por faixa etária (na data da eleição):");
		Utils utils = new Utils();
		int age1 = 0, age2 = 0, age3 = 0, age4 = 0, age5 = 0, ageTotal = 0;
		for (Candidate candidate : electionInfo.getElectedCandidates()) {
			int age = utils.calculateAge(
				electionInfo.parseDateToString(candidate.getBirthDate()),
				electionInfo.parseDateToString(electionInfo.getElectionDate())
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
		System.out.print("      Idade < 30: " + age1);
		System.out.printf(" (%.2f%%)\n", ((float) age1 / ageTotal * 100));
		System.out.print("30 <= Idade < 40: " + age2);
		System.out.printf(" (%.2f%%)\n", ((float) age2 / ageTotal * 100));
		System.out.print("40 <= Idade < 50: " + age3);
		System.out.printf(" (%.2f%%)\n", ((float) age3 / ageTotal * 100));
		System.out.print("50 <= Idade < 60: " + age4);
		System.out.printf(" (%.2f%%)\n", ((float) age4 / ageTotal * 100));
		System.out.print("60 <= Idade : " + age5);
		System.out.printf(" (%.2f%%)\n", ((float) age5 / ageTotal * 100));
		System.out.println();
	}

	public void displayGenderOfElectedCandidates() {
		System.out.println("Eleitos, por sexo:");
		int male = 0, female = 0, total = 0;
		for (Candidate candidate : electionInfo.getElectedCandidates()) {
			if (candidate.getGender() == 'M') {
				male++;
			}
			else {
				female++;
			}
			total++;
		}
		System.out.print("Feminino: "+ female);
		System.out.printf(" (%.2f%%)\n", electionInfo.getGeneralPercent(female, total));
		System.out.print("Masculino: " + male);
		System.out.printf(" (%.2f%%)\n", electionInfo.getGeneralPercent(male, total));
		System.out.println();
	}

	public void displayAllVotes() {
		System.out.printf(
			"Total de votos válidos:    %d\n",
			electionInfo.getAmountOfTotalVotes()
		);
		System.out.printf(
			"Total de votos nominais:   %d (%.2f%%)\n",
			electionInfo.getAmountOfCandidatesVotes(),
			electionInfo.getGeneralPercent(
				electionInfo.getAmountOfCandidatesVotes(), electionInfo.getAmountOfTotalVotes()
			)
		);
		System.out.printf(
			"Total de votos de legenda: %d (%.2f%%)",
			electionInfo.getAmountOfPartyVotes(),
			electionInfo.getGeneralPercent(
				electionInfo.getAmountOfPartyVotes(), electionInfo.getAmountOfTotalVotes()
			)
		);
	}

}
