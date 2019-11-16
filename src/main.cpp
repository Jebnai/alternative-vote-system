#include <iostream>
#include "vote.h"
#include "election.h"
#include <vector>
#include <sstream>

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
    election.add_vote(vote(std::vector<unsigned int> {4, 1, 2, 3, 5}));
    election.add_vote(vote(std::vector<unsigned int> {5, 4, 1, 2, 3}));
    election.add_vote(vote(std::vector<unsigned int> {5, 1, 4, 2, 3}));
    election.add_vote(vote(std::vector<unsigned int> {2, 3, 4, 1, 5}));
    election.add_vote(vote(std::vector<unsigned int> {5, 3, 4, 1, 2}));
    printVotes(election);
    std::cout << "return how many first preferences candidates have" << std::endl;
    election.ranked_candidates();
    return 0;
}

