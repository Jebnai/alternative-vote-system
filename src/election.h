#ifndef ALTERNATIVE_VOTE_SYSTEM_ELECTION_H
#define ALTERNATIVE_VOTE_SYSTEM_ELECTION_H

#include <vector>
#include <iostream>
#include "vote.h"

class election{
private:
    typedef unsigned int candidate;
    std::vector<std::vector<candidate>> votes;
public:
    election();

    void add_vote(const vote &v);

    int vote_count() const;

    void eliminate(candidate c);

    std::vector<std::pair<candidate, int>> ranked_candidates() const;

    std::vector<std::vector<candidate>> getVotes() const;
};

election read_votes(std::istream &in);

#endif //ALTERNATIVE_VOTE_SYSTEM_ELECTION_H
