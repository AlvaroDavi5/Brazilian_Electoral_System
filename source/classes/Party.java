package source.classes;


public class Party {
	// attributes
	private int number = 0;
	private String name = "";
	private String alias = "";
	private int votes = 0;


	// constructor method
	public Party(String alias) {
		this.alias = alias;
	}


	// methods
	public void displayPartyInfo() {
		System.out.println("Party alias: " + alias);
		System.out.println("Party number: " + number);
		System.out.println("Party name: " + name);
		System.out.println("Party votes: " + votes);
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

	public int getVotes() {
		return votes;
	}
	public void setVotes(int votes) {
		this.votes = votes;
	}
}
