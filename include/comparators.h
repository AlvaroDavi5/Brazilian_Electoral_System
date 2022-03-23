#ifndef COMPARATORS_H

	#define COMPARATORS_H

	#include <iostream>
	#include "./candidate.h"
	#include "./party.h"
	#include "./utils.h"

	using namespace std;


	class Comparator {
		public:
			// ? Member Functions
			static bool CandidatesVotesComparator(Candidate &c1, Candidate &c2) {
				if (c2.getVotes() == c1.getVotes())
				{
					Utils util = Utils();

					if (util.olderThan(c2.getBirthDate(), c1.getBirthDate()) > 0) {
						return true;
					}
					else if (util.olderThan(c2.getBirthDate(), c1.getBirthDate()) == 0) {
						if (c2.getNumber() <= c1.getNumber()) {
							return true;
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}

				return (c2.getVotes() > c1.getVotes());
			}

			static bool PartiesCandidateVotesComparator(Party &p1, Party &p2) {
				int p1FirstCandidateVotes = p1.getCandidates()[0]->getVotes();
				int p2FirstCandidateVotes = p2.getCandidates()[0]->getVotes();

				for (Candidate* candidate : p1.getCandidates()) {
					if (candidate->getVotesDestiny() == "Válido") {
						p1FirstCandidateVotes = candidate->getVotes();
						break;
					}
				}
				for (Candidate* candidate : p2.getCandidates()) {
					if (candidate->getVotesDestiny() == "Válido") {
						p2FirstCandidateVotes = candidate->getVotes();
						break;
					}
				}

				if(p2FirstCandidateVotes == p1FirstCandidateVotes) {
					if (p2.getNumber() < p1.getNumber()) {
						return true;
					}
					else {
						return false;
					}
				}

				return (p2FirstCandidateVotes > p1FirstCandidateVotes);
			}

			static bool PartiesPartyVotesComparator(Party &p1, Party &p2) {
				if(p2.getPartyVotes() == p1.getPartyVotes()) {
					int p1CandidatesVotes = p1.getTotalVotes() - p1.getPartyVotes();
					int p2CandidatesVotes = p2.getTotalVotes() - p2.getPartyVotes();

					if (p2CandidatesVotes > p1CandidatesVotes) {
						return true;
					}
					else if (p2CandidatesVotes == p1CandidatesVotes) {
						if (p2.getNumber() <= p1.getNumber()) {
							return true;
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}

				return (p2.getPartyVotes() > p1.getPartyVotes());
			}

			static bool PartiesTotalVotesComparator(Party &p1, Party &p2) {
				if (p2.getTotalVotes() == p1.getTotalVotes()) {
					if (p2.getNumber() < p1.getNumber()) {
						return true;
					}
					else {
						return false;
					}
				}

				return (p2.getTotalVotes() > p1.getTotalVotes());
			}
	};

#endif // COMPARATORS_H
