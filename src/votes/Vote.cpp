#include <vector>
#include <iostream>
#include "Vote.h"

Vote::Vote(const std::vector<candidate> &prefs): preference(prefs) {
    unsigned int numberOfCandidates;
    std::cout << "Enter number of candidates" << std::endl;
    std::cin >> numberOfCandidates;
    for(int i = 1; i < numberOfCandidates + 1; i++){
        preference.push_back(i);
    }
    for(int x : preference){
        std::cout << x << " ";
    }
}

bool Vote::spent() const{
    return (preference.empty());
}

Vote::candidate Vote::first_preference() const {
    if(!spent()){
        return preference[0];
    }
}

void Vote::discard(Vote::candidate c){
    
}