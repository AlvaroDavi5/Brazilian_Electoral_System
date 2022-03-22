#ifndef COMPARATORS_H

	#define COMPARATORS_H

	#include <iostream>
	#include "./candidate.h"
	#include "./party.h"
	#include "./utils.h"

	using namespace std;


	// ? Functions
	const bool CandidatesVotesComparator(const Candidate &c1, const Candidate &c2);
	const bool PartiesCandidateVotesComparator(const Party &p1, const Party &p2);
	const bool PartiesPartyVotesComparator(const Party &p1, const Party &p2);
	const bool PartiesTotalVotesComparator(const Party &p1, const Party &p2);

#endif // COMPARATORS_H
