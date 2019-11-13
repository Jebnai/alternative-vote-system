#include <iostream>
#include "vote.h"
#include "election.h"
#include <vector>

void printVote(vote &v){
    for(int i = 0; i < v.getVote().size(); i++){
        std::cout << v.getVote()[i];
    }
    std::cout << "" << std::endl;
}

void printVotes(election &e){
    for(int i = 0; i < e.getVotes().size(); i++){
        for(int j = 0; j < e.getVotes()[i].size(); j++){
            std::cout << e.getVotes()[i][j];
        }
        std::cout << "" << std::endl;
    }
}

int main() {
    election election;
    election.add_vote(vote(std::vector<unsigned int> {1, 2, 3, 4}));
    election.add_vote(vote(std::vector<unsigned int> {1, 3, 2, 4}));
    printVotes(election);
    election.eliminate(1);
    std::cout << "Number 1 eliminated" << std::endl;
    printVotes(election);
    return 0;
}

