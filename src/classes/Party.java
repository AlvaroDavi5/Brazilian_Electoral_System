package src.classes;
import java.util.LinkedList;


public class Party {
	// attributes
	private int number = 0;
	private String name = "";
	private String alias = "";
	private int partyVotes = 0;
	private int totalVotes = 0;
	private LinkedList<Candidate> candidates = null;


	// constructor method
	public Party(String alias) {
		this.alias = alias;
	}


	// methods
	public void displayPartyInfo() {
		System.out.println("Party alias: " + alias);
		System.out.println("Party number: " + number);
		System.out.println("Party name: " + name);
		System.out.println("Party votes: " + partyVotes);
		System.out.println("Total votes: " + totalVotes);
		System.out.println();
	}

	public int getNumber() {
		return number;
	}
	public void setNumber(int number) {
		this.number = number;
	}

	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}

	public String getAlias() {
		return alias;
	}
	public void setAlias(String alias) {
		this.alias = alias;
	}

	public int getPartyVotes() {
		return partyVotes;
	}
	public void setPartyVotes(int votes) {
		this.partyVotes = votes;
	}

	public int getTotalVotes() {
		return totalVotes;
	}
	public void setTotalVotes(int votes) {
		this.totalVotes = votes;
	}

	public LinkedList<Candidate> getCandidates() {
		return candidates;
	}
	public void setCandidates(LinkedList<Candidate> candidates) {
		this.candidates = candidates;
	}
}
