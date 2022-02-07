package src.classes;
import java.util.Date;
import java.util.LinkedList;
import src.Election;


public class Candidate {
	// attributes
	private int number = 0;
	private int politicalPartyNumber = 0;
	private String name = "";
	private String ballotBoxAlias = "";
	private int votes = 0;
	private String votesDestiny = "";
	private String situation = "";
	private char gender = ' ';
	private Date birthDate = null;
	private int position = 0;


	// constructor method
	public Candidate(String ballotBoxAlias) {
		this.ballotBoxAlias = ballotBoxAlias;
	}


	// methods
	public void displayCandidateInfo() {
		System.out.println("Candidate alias: " + ballotBoxAlias);
		System.out.println("Candidate number: " + number);
		System.out.println("Candidate name: " + name);
		System.out.println("Candidate votes: " + votes);
		System.out.println("Candidate votes destiny: " + votesDestiny);
		System.out.println("Candidate situation: " + situation);
		System.out.println("Candidate political party number: " + politicalPartyNumber);
		System.out.println("Candidate gender: " + gender);
		Election info = new Election();
		System.out.println("Candidate birthdate: " + info.parseDateToString(birthDate));
		System.out.println("Candidate position: " + position);
		System.out.println();
	}

	public int getNumber() {
		return number;
	}
	public void setNumber(int number) {
		this.number = number;
	}

	public int getPoliticalPartyNumber() {
		return politicalPartyNumber;
	}
	public void setPoliticalPartyNumber(int politicalPartyNumber) {
		this.politicalPartyNumber = politicalPartyNumber;
	}
	public String getPoliticalPartyNameByNumber(LinkedList<Party> parties) {
		for (Party party : parties) {
			if (party.getNumber() == politicalPartyNumber) {
				return party.getName();
			}
		}
		return "";
	}
	public String getPoliticalPartyAliasByNumber(LinkedList<Party> parties) {
		for (Party party : parties) {
			if (party.getNumber() == politicalPartyNumber) {
				return party.getAlias();
			}
		}
		return "";
	}

	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}

	public String getBallotBoxAlias() {
		return ballotBoxAlias;
	}
	public void setBallotBoxAlias(String ballotBoxAlias) {
		this.ballotBoxAlias = ballotBoxAlias;
	}

	public int getVotes() {
		return votes;
	}
	public void setVotes(int votes) {
		this.votes = votes;
	}
	public void addVotes(int votes) {
		this.votes += votes;
	}

	public String getVotesDestiny() {
		return votesDestiny;
	}
	public void setVotesDestiny(String votesDestiny) {
		this.votesDestiny = votesDestiny;
	}

	public String getSituation() {
		return situation;
	}
	public void setSituation(String situation) {
		this.situation = situation;
	}

	public char getGender() {
		return gender;
	}
	public void setGender(char gender) {
		this.gender = gender;
	}

	public Date getBirthDate() {
		return birthDate;
	}
	public void setBirthDate(Date birthDate) {
		this.birthDate = birthDate;
	}

	public int getPosition() {
		return position;
	}
	public void setPosition(int position) {
		this.position = position;
	}
}
