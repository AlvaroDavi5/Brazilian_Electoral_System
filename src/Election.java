package src;
import java.util.Date;
import java.util.LinkedList;
import java.util.Collections;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import src.classes.*;


public class Election {
	// attributes
	private String data = "";
	private char entity = '\0';
	private Date electionDate = null;
	private LinkedList<Candidate> candidates = null;
	private LinkedList<Party> parties = null;


	// methods
	public Date parseStringToDate(String strDate) {
		Date date = null;

		try {
			SimpleDateFormat dateFormatter = new SimpleDateFormat(
				"dd/MM/yyyy"
			);
			date = dateFormatter.parse(strDate);
		}
		catch (ParseException exception) {
			exception.printStackTrace();
		}

		return date;
	}
	public String parseDateToString(Date date) {
		String strDate = "";

		try {
			SimpleDateFormat dateFormatter = new SimpleDateFormat(
				"dd/MM/yyyy"
			);
			strDate = dateFormatter.format(date);
		}
		catch (Exception exception) {
			exception.printStackTrace();
		}

		return strDate;
	}

	public String getData() {
		return data;
	}
	public void setData(String newData) {
		this.data = newData;
	}
	public void addData(String newData) {
		this.data += newData + "\n";
	}

	public char getEntity() {
		return entity;
	}
	public void setEntity(char newEntity) {
		this.entity = newEntity;
	}

	public Date getElectionDate() {
		return electionDate;
	}
	public void setElectionDate(Date newElectionDate) {
		this.electionDate = newElectionDate;
	}

	public LinkedList<Candidate> getCandidates() {
		if (candidates == null) {
			this.candidates = new LinkedList<Candidate>();
		}

		return candidates;
	}
	public void setCandidates(LinkedList<Candidate> newCandidates) {
		this.candidates = newCandidates;
	}
	public void addCandidate(Candidate newCandidate) {
		if (candidates == null) {
			this.candidates = new LinkedList<Candidate>();
		}

		this.candidates.add(newCandidate);
	}

	public LinkedList<Party> getParties() {
		if (parties == null) {
			this.parties = new LinkedList<Party>();
		}

		return parties;
	}
	public void setParties(LinkedList<Party> newParties) {
		this.parties = newParties;
	}
	public void addParty(Party newParty) {
		if (parties == null) {
			this.parties = new LinkedList<Party>();
		}

		this.parties.add(newParty);
	}

	public boolean loadEntitiesFromData() {
		boolean success = false;
		String[] lines = getData().split("\n");

		try {
			for (int i = 0; i < lines.length; i++) {
				String lineData = lines[i];
	
				if (lineData.length() != 0 && lineData != "" && lineData != null) {
					String[] splitedLineData = lineData.split(",");
	
					for (int j = 0; j < splitedLineData.length; j++) {
						splitedLineData[j] = splitedLineData[j].trim();
					}
	
					if (getEntity() == 'c') {
						Candidate candidate = new Candidate(
							splitedLineData[4]
						);
						candidate.setNumber(
							Integer.parseInt(splitedLineData[0])
						);
						candidate.setVotes(
							Integer.parseInt(splitedLineData[1])
						);
						candidate.setSituation(splitedLineData[2]);
						candidate.setName(splitedLineData[3]);
						candidate.setGender(
							splitedLineData[5].charAt(0)
						);
						candidate.setBirthDate(
							parseStringToDate(splitedLineData[6])
						);
						candidate.setVotesDestiny(splitedLineData[7]);
						candidate.setPoliticalPartyNumber(
							Integer.parseInt(splitedLineData[8])
						);
	
						addCandidate(candidate);
						success = true;
					}
					else if (getEntity() == 'p') {
						Party party = new Party(splitedLineData[3]);
						party.setNumber(
							Integer.parseInt(splitedLineData[0])
						);
						party.setPartyVotes(
							Integer.parseInt(splitedLineData[1])
						);
						party.setName(splitedLineData[2]);
	
						addParty(party);
						success = true;
					}
					else {
						System.out.println("Error: entity not found");
						success = false;
					}
				}
			}
			setEntity('\0');
			setData("");
		}
		catch (Exception exception) {
			exception.printStackTrace();
		}

		return success;
	}

	public LinkedList<Candidate> getCandidatesByParty(int partyNumber) {
		LinkedList<Candidate> candidatesByParty = new LinkedList<Candidate>();

		for (int i = 0; i < getCandidates().size(); i++) {
			Candidate candidate = getCandidates().get(i);

			if (candidate.getPoliticalPartyNumber() == partyNumber) {
				candidatesByParty.add(candidate);
			}
		}

		return candidatesByParty;
	}

	public void PopulatePartiesCandidatesList() {
		for (int i = 0; i < getParties().size(); i++) {
			Party party = getParties().get(i);

			party.setCandidates(
				getCandidatesByParty(party.getNumber())
			);

			for (Candidate candidate : party.getCandidates()) {
				if (candidate.getVotesDestiny().equals("Válido")) {
					party.setTotalVotes(
						party.getTotalVotes() + candidate.getVotes()
					);
				}
			}
			party.setTotalVotes(
				party.getTotalVotes() + party.getPartyVotes()
			);
		}
	}

	public LinkedList<Candidate> getElectedCandidates() {
		LinkedList<Candidate> allCandidates = new LinkedList<Candidate>();
		LinkedList<Candidate> electedCandidates = new LinkedList<Candidate>();

		for (Candidate candidate : getCandidates()) {
			allCandidates.add(candidate);
		}

		for (int i = 0; i < allCandidates.size(); i++) {
			if (allCandidates.get(i).getSituation().equals("Eleito")) {
				electedCandidates.add(allCandidates.get(i));
			}
		}

		for (int i = 0; i < electedCandidates.size(); i++) {
			for (int j = i+1; j < electedCandidates.size(); j++) {
				if (electedCandidates.get(i).getVotes() < electedCandidates.get(j).getVotes()) {
					Candidate aux = electedCandidates.get(i);
					electedCandidates.set(i, electedCandidates.get(j));
					electedCandidates.set(j, aux);
				}
			}
		}

		return electedCandidates;
	}

	public int getNumberOfElectedCandidates() {
		return getElectedCandidates().size();
	}

	public LinkedList<Candidate> getCandidatesOrderedByVotes() {
		LinkedList<Candidate> allCandidates = new LinkedList<Candidate>();
		LinkedList<Candidate> candidatesOrderedByVotes = new LinkedList<Candidate>();

		for (Candidate candidate : getCandidates()) {
			candidate.setPosition(0);
			allCandidates.add(candidate);
		}

		Collections.sort(allCandidates, new CandidatesVotesComparator());

		for (int k = 0; k < allCandidates.size(); k++) {
			Candidate candidate = allCandidates.get(k);
			candidate.setPosition(k+1);
			candidatesOrderedByVotes.add(candidate);
		}

		return candidatesOrderedByVotes;
	}

	public LinkedList<Candidate> getMostVotedCandidates() {
		LinkedList<Candidate> allCandidates = new LinkedList<Candidate>();
		LinkedList<Candidate> mostVotedCandidates = new LinkedList<Candidate>();

		for (Candidate candidate : getCandidatesOrderedByVotes()) {
			allCandidates.add(candidate);
		}

		for (int k = 0; k < getNumberOfElectedCandidates(); k++) {
			Candidate candidate = allCandidates.get(k);
			mostVotedCandidates.add(candidate);
		}

		return mostVotedCandidates;
	}

	public LinkedList<Candidate> getMostVotedAndNotElectedCandidates() {
		LinkedList<Candidate> mostVotedAndNotElectedCandidates = new LinkedList<Candidate>();

		for (Candidate candidate : getMostVotedCandidates()) {
			if (!candidate.getSituation().equals("Eleito")) {
				mostVotedAndNotElectedCandidates.add(candidate);
			}
		}

		return mostVotedAndNotElectedCandidates;
	}

	public LinkedList<Candidate> getElectedButNotMostVotedCandidates() {
		Utils utils = new Utils();
		LinkedList<Candidate> electedButNotMostVotedCandidates = new LinkedList<Candidate>();
		Candidate lastMostVotedCandidate = getMostVotedCandidates().get(
			(getMostVotedCandidates().size() - 1)
		);

		for (Candidate candidate : getElectedCandidates()) {
			boolean isTheSameCandidate = lastMostVotedCandidate.getNumber() == candidate.getNumber();
			int isOlderThan = utils.olderThan(lastMostVotedCandidate.getBirthDate(), candidate.getBirthDate());

			if (lastMostVotedCandidate.getVotes() > candidate.getVotes()) {
				electedButNotMostVotedCandidates.add(candidate);
			}
			else if (lastMostVotedCandidate.getVotes() == candidate.getVotes() && !isTheSameCandidate) {
				if (isOlderThan >= 0) {
					electedButNotMostVotedCandidates.add(candidate);
				}
				else {
					electedButNotMostVotedCandidates.add(lastMostVotedCandidate);
				}
			}
		}

		return electedButNotMostVotedCandidates;
	}

	public LinkedList<Party> getPartiesOrderedByTotalVotes() {
		LinkedList<Party> partiesOrderedByTotalVotes = new LinkedList<Party>();

		for (Party party : getParties()) {
			partiesOrderedByTotalVotes.add(party);
		}

		Collections.sort(partiesOrderedByTotalVotes, new PartiesTotalVotesComparator());

		return partiesOrderedByTotalVotes;
	}

	public int getElectedCandidatesNumberFromParty(Party party) {
		int electedCandidatesFromParty = 0;

		for (Candidate candidate : getElectedCandidates()) {
			if (candidate.getPoliticalPartyNumber() == party.getNumber()) {
				electedCandidatesFromParty++;
			}
		}

		return electedCandidatesFromParty;
	}

	public float getPartyVotesPercent(Party party) {
		float partyVotesPercent = 0.00f;

		partyVotesPercent = (float) party.getPartyVotes() / (float) party.getTotalVotes();

		return partyVotesPercent * (float) 100;
	}

	public float getGeneralPercent(float p, float t) {
		float r = 0.00f;

		r = (float) p / (float) t;

		return r * (float) 100;
	}

	public LinkedList<Party> getPartiesOrderedByPartyVotes() {
		LinkedList<Party> partiesOrderedByPartyVotes = new LinkedList<Party>();

		for (Party party : getParties()) {
			partiesOrderedByPartyVotes.add(party);
		}

		Collections.sort(partiesOrderedByPartyVotes, new PartiesPartyVotesComparator());

		return partiesOrderedByPartyVotes;
	}

	public LinkedList<Party> getPartiesWithCandidatesOrderedByVotes() {
		LinkedList<Party> parties = new LinkedList<Party>();

		for (Party party : getParties()) {
			parties.add(party);
		}

		for (Party party : parties) {
			Collections.sort(party.getCandidates(), new CandidatesVotesComparator());
		}
		Collections.sort(parties, new PartiesCandidateVotesComparator());

		return parties;
	}

	public int getAmountOfCandidatesVotes() {
		int amountOfCandidatesVotes = 0;

		for (Candidate candidate : getCandidates()) {
			if (candidate.getVotesDestiny().equals("Válido")) {
				amountOfCandidatesVotes += candidate.getVotes();
			}
		}

		return amountOfCandidatesVotes;
	}

	public int getAmountOfPartyVotes() {
		int amountOfPartyVotes = 0;

		for (Party party : getParties()) {
			amountOfPartyVotes += party.getPartyVotes();
		}

		return amountOfPartyVotes;
	}

	public int getAmountOfTotalVotes() {
		return getAmountOfCandidatesVotes() + getAmountOfPartyVotes();
	}

}
