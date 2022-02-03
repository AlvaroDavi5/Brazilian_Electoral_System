package src.classes;
import java.util.Comparator;


public class PartiesTotalVotesComparator implements Comparator<Party> {

	// overrides method
	@Override
	public int compare(Party p1, Party p2) {

		if(p2.getTotalVotes() == p1.getTotalVotes()) {
			if (p2.getNumber() < p1.getNumber()) {
				return 1;
			}
			else {
				return -1;
			}
		}

		return (p2.getTotalVotes() - p1.getTotalVotes());
	}

}
