#include <vector>
#include <iostream>
#include "vote.h"
#include "election.h"

election::election(){
}

//adds a vote to the collection.
void election::add_vote(const vote &v) {
    votes.push_back(v.getVote());
}

//returns the number of votes currently left.
int election::vote_count() const {

}

//removes any occurrence of the named candidate from each vote.
void election::eliminate(unsigned int c) {

}

//returns a collection of candidates left paired with the number of firsts each vote has in decreasing order.
std::vector<std::pair<unsigned int, int>> election::ranked_candidates() const {

}

election read_votes(std::istream &in){

}
