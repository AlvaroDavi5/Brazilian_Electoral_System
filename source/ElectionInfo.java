package source;
import java.util.Date;
import java.util.LinkedList;
import java.text.SimpleDateFormat;
import java.text.ParseException;


public class ElectionInfo {
	// attributes
	private String data = "";
	private char entity = '\0';
	private LinkedList<Candidate> candidates = new LinkedList<Candidate>();
	private LinkedList<Party> parties = new LinkedList<Party>();


	// methods
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

	public LinkedList<Candidate> getCandidates() {
		return candidates;
	}
	public void setCandidates(LinkedList<Candidate> newCandidates) {
		this.candidates = newCandidates;
	}
	public void addCandidate(Candidate newCandidate) {
		this.candidates.add(newCandidate);
	}

	public LinkedList<Party> getParties() {
		return parties;
	}
	public void setParties(LinkedList<Party> newParties) {
		this.parties = newParties;
	}
	public void addParty(Party newParty) {
		this.parties.add(newParty);
	}

	public boolean loadEntitiesFromData() {
		boolean success = false;
		String[] lines = data.split("\n");

		for (int i = 0; i < lines.length; i++) {
			String lineData = lines[i];

			if (lineData != "") {
				String[] splitedLineData = lineData.split(",");

				for (int j = 0; j < splitedLineData.length; j++) {
					splitedLineData[j] = splitedLineData[j].trim();
				}

				if (entity == 'c') {
					Candidate candidate = new Candidate(splitedLineData[4]);
					candidate.setNumber(Integer.parseInt(splitedLineData[0]));
					candidate.setVotes(Integer.parseInt(splitedLineData[1]));
					candidate.setSituation(splitedLineData[2]);
					candidate.setName(splitedLineData[3]);
					candidate.setGender((char) splitedLineData[5].charAt(0));
					try {
						SimpleDateFormat dateFormatter = new SimpleDateFormat("dd/MM/yyyy");
						Date birthDate = dateFormatter.parse(splitedLineData[6]);
						candidate.setBirthDate(birthDate);
					}
					catch (ParseException exception) {
						candidate.setBirthDate(null);
					}
					candidate.setVotesDestiny(splitedLineData[7]);
					candidate.setPoliticalPartyNumber(Integer.parseInt(splitedLineData[8]));

					addCandidate(candidate);

					success = true;
				}
				else if (entity == 'p') {
					Party party = new Party(splitedLineData[3]);
					party.setNumber(Integer.parseInt(splitedLineData[0]));
					party.setVotes(Integer.parseInt(splitedLineData[1]));
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

		return success;
	}

}
