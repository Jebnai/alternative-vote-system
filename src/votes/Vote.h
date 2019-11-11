#ifndef ALTERNATIVE_VOTE_SYSTEM_VOTE_H
#define ALTERNATIVE_VOTE_SYSTEM_VOTE_H

#include <iostream>
#include <vector>
class Vote{
private:
    typedef unsigned int candidate;
    std::vector<candidate> preference;
public:
    Vote(const std::vector<candidate> &prefs);

    bool spent() const;

    candidate first_preference() const;

    void discard(candidate c);
};

#endif //ALTERNATIVE_VOTE_SYSTEM_VOTE_H
