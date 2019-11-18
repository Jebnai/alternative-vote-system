#include <iostream>
#include <fstream>
#include <string>
#include "vote.h"
#include "election.h"
#include <vector>
#include <sstream>



//works out if a candidate has majority of the first preferences.
bool majority(election &e){
    int sum = 0;
    for(int i = 1; i < e.ranked_candidates().size(); i++){
        sum += e.ranked_candidates()[i].second;
    }
    return(e.ranked_candidates()[0].second > sum);
}

int main() {
    //initializing an election
    election election;
    int counter = 1;
    //reading from text file
    std::fstream in;
    in.open("tests/input4.txt");
    if(in.fail()){
        std::cerr << "Error reading file" << std::endl;
        exit(1);
    }else{
        election = read_votes(in);
    }
    in.close();

    //running the election
    while(election.ranked_candidates().size() > 1 ){
        std::cout << "Round " << counter << ": " << election.vote_count() << " votes" << std::endl;
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
            break;
        }else{
            std::cout << "Candidate " << election.ranked_candidates()[election.ranked_candidates().size()-1].first << " is eliminated" << std::endl;
            election.eliminate(election.ranked_candidates()[election.ranked_candidates().size()-1].first);
        }counter++;
    }

    return 0;
}

