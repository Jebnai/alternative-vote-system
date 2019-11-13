#include <utility>
#include <vector>
#include <iostream>
#include "vote.h"

//sets up a vote with a sequence of candidates in preference order.
vote::vote(std::vector<candidate> prefs): preference(std::move(prefs)) {}

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

std::vector<vote::candidate> vote::getVote() const{
    return preference;
}