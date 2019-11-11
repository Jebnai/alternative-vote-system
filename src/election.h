#ifndef ALTERNATIVE_VOTE_SYSTEM_ELECTION_H
#define ALTERNATIVE_VOTE_SYSTEM_ELECTION_H

#include <vector>
#include <iostream>
#include "vote.h"

class election{
private:
    std::vector<std::vector<unsigned int>> votes;
public:
    election();

    void add_vote(const vote &v);

    int vote_count() const;

    void eliminate(unsigned int c);

    std::vector<std::pair<unsigned int, int>> ranked_candidates() const;
};

election read_votes(std::istream &in);

#endif //ALTERNATIVE_VOTE_SYSTEM_ELECTION_H
