#include <vector>
#include <iostream>
#include "vote.h"
#include "election.h"

election::election()= default;

//adds a vote to the collection.
void election::add_vote(const vote &v) {
    votes.push_back(v.getVote());
}

//returns the number of votes currently left.
int election::vote_count() const {
    return votes.size();
}

//removes any occurrence of the named candidate from each vote.
void election::eliminate(election::candidate c){
    for(auto & i : votes){
        int j = 0;
        while(j < i.size()){
            std::vector<election::candidate> vote = i;
            if(i[j] == c){
                vote.erase(vote.begin() + j);
                i = vote;
            }else{
                ++j;
            }
        }
    }
}

//returns a collection of candidates left paired with the number of firsts each vote has in decreasing order.
std::vector<std::pair<election::candidate, int>> election::ranked_candidates() const {

}

election read_votes(std::istream &in){

}

std::vector<std::vector<election::candidate>>election::getVotes() const {
    return votes;
}
