package src.classes;
import java.util.Comparator;


public class CandidatesVotesComparator implements Comparator<Candidate> {

	// overrides method
	@Override
	public int compare(Candidate c1, Candidate c2) {

		if(c2.getVotes() == c1.getVotes()) {
			Utils util = new Utils();

			if (util.olderThan(c2.getBirthDate(), c1.getBirthDate()) > 0) {
				return 1;
			}
			else if (util.olderThan(c2.getBirthDate(), c1.getBirthDate()) == 0) {
				if (c2.getNumber() <= c1.getNumber()) {
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

		return (c2.getVotes() - c1.getVotes());
	}

}
