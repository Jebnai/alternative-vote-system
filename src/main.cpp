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

int main() {
    election election;
    int counter = 1;
    std::fstream in;
    in.open("votes.txt");
    if(in.fail()){
        std::cerr << "sad" << std::endl;
        exit(1);
    }else{
        election = read_votes(in);
    }
    in.close();
    return 0;
}

