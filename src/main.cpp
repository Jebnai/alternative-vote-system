#include <iostream>
#include <fstream>
#include <string>
#include "vote.h"
#include "election.h"
#include <vector>
#include <sstream>



//works out if a candidate has majority of the first preferences.
bool majority(election &e, std::vector<std::pair<unsigned int, int>> &rank){
    int sum = 0;
    for(int i = 1; i < rank.size(); i++){
        sum += rank[i].second;
    }
    return(rank[0].second > sum);
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
    std::vector<std::pair<unsigned int, int>> rank;
    //running the election
    while(election.ranked_candidates().size() > 1 ){
        rank = election.ranked_candidates();
        std::cout << "Round " << counter << ": " << election.vote_count() << " votes" << std::endl;
        std::cout << "First preferences:" << std::endl;
        for(int i = 0; i < rank.size(); i++){
            std::cout << "   Candidate " << rank[i].first << ": " << rank[i].second << std::endl;
        }
        //check to see if a candidate has majority of the votes
        if(majority(election, rank)){
            for(int i = 1; i < rank.size(); i++){
                election.eliminate(rank[i].first);
                std::cout << "Candidate " << rank[0].first << " is selected." << std::endl;
                break;
            }
            break;
        }else{
            std::cout << "Candidate " << rank[rank.size()-1].first << " is eliminated" << std::endl;
            election.eliminate(rank[rank.size()-1].first);
        }counter++;
    }

    return 0;
}
