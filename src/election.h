#ifndef ALTERNATIVE_VOTE_SYSTEM_ELECTION_H
#define ALTERNATIVE_VOTE_SYSTEM_ELECTION_H

#include <vector>
#include <iostream>
#include "vote.h"
#include <bits/stdc++.h>
#include <sstream>

class election{
private:
    typedef unsigned int candidate;
    typedef std::pair<candidate, int> pair;
    //std::vector<std::vector<candidate>> votes;
    std::vector<vote> votes;
    static std::stringstream s;
public:
    election();

    void add_vote(const vote &v);

    int vote_count() const;

    void eliminate(candidate c);

    std::vector<std::pair<candidate, int>> ranked_candidates() const;
    
};

election read_votes(std::istream &in);



#endif //ALTERNATIVE_VOTE_SYSTEM_ELECTION_H
