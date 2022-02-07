package src.classes;
import java.util.Comparator;


public class PartiesPartyVotesComparator implements Comparator<Party> {

	// overrides method
	@Override
	public int compare(Party p1, Party p2) {

		if(p2.getPartyVotes() == p1.getPartyVotes()) {
			int p1CandidatesVotes = p1.getTotalVotes() - p1.getPartyVotes();
			int p2CandidatesVotes = p2.getTotalVotes() - p2.getPartyVotes();

			if (p2CandidatesVotes > p1CandidatesVotes) {
				return 1;
			}
			else if (p2CandidatesVotes == p1CandidatesVotes) {
				if (p2.getNumber() <= p1.getNumber()) {
					return 1;
				}
				else {
					return -1;
				}
			}
			else {
				return -1;
			}
		}

		return (p2.getPartyVotes() - p1.getPartyVotes());
	}

}
