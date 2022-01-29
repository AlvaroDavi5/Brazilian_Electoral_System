package source;
import java.util.Date;
import java.util.LinkedList;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import source.classes.*;


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

		for (int i = 0; i < lines.length; i++) {
			String lineData = lines[i];

			if (lineData != "") {
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
					party.setVotes(
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
		setData("");

		return success;
	}

	public LinkedList<Candidate> getElectedCandidates() {
		LinkedList<Candidate> allCandidates = getCandidates();
		LinkedList<Candidate> electedCandidates = new LinkedList<Candidate>();

		for (int i = 0; i < allCandidates.size(); i++) {
			if (allCandidates.get(i).getSituation().equals("Eleito")) {
				electedCandidates.add(allCandidates.get(i));
			}
		}

		for (int i = 0; i < electedCandidates.size(); i++) {
			for (int j = i + 1; j < electedCandidates.size(); j++) {
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

	public LinkedList<Candidate> getMostVotedCandidates() {
		LinkedList<Candidate> allCandidates = new LinkedList<Candidate>();
		LinkedList<Candidate> mostVotedCandidates = new LinkedList<Candidate>();

		for (Candidate candidate : getCandidates()) {
			allCandidates.add(candidate);
		}

		for (int i = 0; i < getNumberOfElectedCandidates(); i++) {
			int maxVotes = 0;
			int candidateNumber = 0;

			for (int j = 0; j < allCandidates.size(); j++) {
				Candidate c1 = allCandidates.get(j);

				if (c1.getVotes() > maxVotes) {
					maxVotes = c1.getVotes();
					candidateNumber = c1.getNumber();
				}
			}

			for (Candidate candidate : allCandidates) {
				if (candidate.getNumber() == candidateNumber) {
					mostVotedCandidates.add(candidate);
					allCandidates.remove(candidate);
					break;
				}
			}
		}

		return mostVotedCandidates;
	}

	public LinkedList<Candidate> getMostVotedAndNotElectedCandidates() {
		LinkedList<Candidate> mostVotedAndNotElectedCandidates = getMostVotedCandidates();

		for (int i = 0; i < mostVotedAndNotElectedCandidates.size(); i++) {
			Candidate candidate = mostVotedAndNotElectedCandidates.get(i);

			if (candidate.getSituation().equals("Eleito")) {
				mostVotedAndNotElectedCandidates.remove(candidate);
			}
		}

		return mostVotedAndNotElectedCandidates;
	}

}
