#include <vector>
#include <iostream>
#include "Vote.h"

//sets up a vote with a sequence of candidates in preference order.
vote::vote(const std::vector<candidate> &prefs): preference(prefs) {
    unsigned int x;
    while(std::cin >> x){
        preference.push_back(x);
    }
}

//returns true if the vote has no preferences left.
bool vote::spent() const{
    return (preference.empty());
}

//returns the current first preference of the vote.
vote::candidate vote::first_preference() const {
    if(!spent()){
        return preference[0];
    }
}

//removes any occurrence of the named candidate from the vote.
void vote::discard(vote::candidate c){
    int i = 0;
    while(i < preference.size()){
        if(preference[i] == c){
            preference.erase(preference.cbegin() + i);
        }else{
            ++i;
        }
    }
}

std::vector<unsigned int> vote::getVote() const{
    return preference;
}