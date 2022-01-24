package source;
import java.util.LinkedList;


public class ElectionInfo {
	// attributes
	private String data = "";
	private char entity = '\0';
	private LinkedList<Candidate> candidates = new LinkedList<Candidate>();
	private LinkedList<Party> parties = new LinkedList<Party>();


	// methods
	public String getData()
	{
		return data;
	}
	public void setData(String newData)
	{
		this.data = newData;
	}
	public void addData(String newData)
	{
		this.data += newData + "\n";
	}

	public char getEntity()
	{
		return entity;
	}
	public void setEntity(char newEntity)
	{
		this.entity = newEntity;
	}

	public LinkedList<Candidate> getCandidates()
	{
		return candidates;
	}
	public void setCandidates(LinkedList<Candidate> newCandidates)
	{
		this.candidates = newCandidates;
	}
	public void addCandidate(Candidate newCandidate)
	{
		this.candidates.add(newCandidate);
	}

	public LinkedList<Party> getParties()
	{
		return parties;
	}
	public void setParties(LinkedList<Party> newParties)
	{
		this.parties = newParties;
	}
	public void addParty(Party newParty)
	{
		this.parties.add(newParty);
	}

}
