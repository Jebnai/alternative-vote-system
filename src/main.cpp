#include <iostream>
#include <fstream>
#include <string>
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

bool majority(election &e){
    int sum = 0;
    for(int i = 1; i < e.ranked_candidates().size(); i++){
        sum += e.ranked_candidates()[i].second;
    }
    return(e.ranked_candidates()[0].second > sum);
}

int returnEmpty(election &e){
    int empty = 0;
    for(int i = 0; i < e.getVotes().size(); i++){
        if(e.getVotes()[i].empty()){
            empty++;
        }
    }
    return empty;
}
int main() {
    //initializing an election
    election election;
    int counter = 1;
    //reading from text file
    std::fstream in;
    in.open("votes.txt");
    if(in.fail()){
        std::cerr << "Error reading file" << std::endl;
        exit(1);
    }else{
        election = read_votes(in);
    }
    in.close();

    //running the election
    while(election.ranked_candidates().size() > 1){
        std::cout << "Round " << counter << ": " << election.vote_count()-returnEmpty(election) << " votes" << std::endl;
        std::cout << "First preferences:" << std::endl;
        for(int i = 0; i < election.ranked_candidates().size(); i++){
            std::cout << "   Candidate " << election.ranked_candidates()[i].first << ": " << election.ranked_candidates()[i].second << std::endl;
        }
        //check to see if a candidate has majority of the votes
        if(majority(election)){
            for(int i = 1; i < election.ranked_candidates().size(); i++){
                election.eliminate(election.ranked_candidates()[i].first);
                std::cout << "Candidate " << election.ranked_candidates()[0].first << " is selected." << std::endl;
                break;
            }
        }else{
            std::cout << "Candidate " << election.ranked_candidates()[election.ranked_candidates().size()-1].first << " is eliminated" << std::endl;
            election.eliminate(election.ranked_candidates()[election.ranked_candidates().size()-1].first);
        }counter++;
    }

    return 0;
}

