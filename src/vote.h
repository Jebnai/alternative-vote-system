#ifndef ALTERNATIVE_VOTE_SYSTEM_VOTE_H
#define ALTERNATIVE_VOTE_SYSTEM_VOTE_H

#include <iostream>
#include <vector>
class vote{
private:
    typedef unsigned int candidate;
    std::vector<candidate> preference;
public:
    vote(const std::vector<candidate> &prefs);

    bool spent() const;

    candidate first_preference() const;

    void discard(candidate c);

    std::vector<unsigned int> getVote() const;
};

#endif //ALTERNATIVE_VOTE_SYSTEM_VOTE_H
