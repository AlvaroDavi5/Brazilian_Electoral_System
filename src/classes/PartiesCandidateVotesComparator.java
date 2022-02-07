package src.classes;
import java.util.Comparator;


public class PartiesCandidateVotesComparator implements Comparator<Party> {

	// overrides method
	@Override
	public int compare(Party p1, Party p2) {
		int p1FirstCandidateVotes = p1.getCandidates().get(0).getVotes();
		int p2FirstCandidateVotes = p2.getCandidates().get(0).getVotes();

		for (Candidate candidate : p1.getCandidates()) {
			if (candidate.getVotesDestiny().equals("Válido")) {
				p1FirstCandidateVotes = candidate.getVotes();
				break;
			}
		}
		for (Candidate candidate : p2.getCandidates()) {
			if (candidate.getVotesDestiny().equals("Válido")) {
				p2FirstCandidateVotes = candidate.getVotes();
				break;
			}
		}

		if(p2FirstCandidateVotes == p1FirstCandidateVotes) {
			if (p2.getNumber() < p1.getNumber()) {
				return 1;
			}
			else {
				return -1;
			}
		}

		return (p2FirstCandidateVotes - p1FirstCandidateVotes);
	}

}
