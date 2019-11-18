#include <vector>
#include <iostream>
#include <algorithm>
#include "vote.h"
#include "election.h"
#include <sstream>

election::election()= default;

//adds a vote to the collection.
void election::add_vote(const vote &v) {
    votes.push_back(v);
}

//returns the number of votes currently left.
int election::vote_count() const {
    return votes.size();
}

//removes any occurrence of the named candidate from each vote.
void election::eliminate(election::candidate c){
    int i = 0;
    while (i < votes.size()) {
        votes[i].discard(c);
        if (votes[i].spent()) {
            votes.erase(votes.cbegin() + i);
        }else {
            i++;
        }
    }
}

//returns a collection of candidates left paired with the number of firsts each vote has in decreasing order.
std::vector<std::pair<election::candidate, int>> election::ranked_candidates() const {
    std::vector<std::pair<election::candidate , int>> votePair;
    std::vector<election::candidate> firstCandidate;
    std::vector<int> preferenceNumber;
    for(int i = 0; i < votes.size(); i++){
        int j = 0;
        if(firstCandidate.empty()){
            firstCandidate.push_back(votes[i].first_preference());
            preferenceNumber.push_back(1);
        }else{
            for(j = 0; j < votes.size(); j++){
                if(!votes[i].spent()){
                    if(firstCandidate[j] == votes[i].first_preference()){
                        preferenceNumber[j] += 1;
                        break;
                    }else if(j==firstCandidate.size()-1){
                        firstCandidate.push_back(votes[i].first_preference());
                        preferenceNumber.push_back(1);
                        break;
                    }
                }
            }
        }
    }
    int n = firstCandidate.size();
    for(int i = 0; i < n; i++){
        votePair.emplace_back(firstCandidate[i], preferenceNumber[i]);
    }
    //sorting the pair
    std::sort(votePair.begin(), votePair.end(),
              [](const pair& x, const pair& y) {
                  // compare second value
                  if (x.second != y.second)
                      return x.second > y.second;

                  // compare first only if second value is equal
                  return x.first > y.first;
              });
    return votePair;
}

//reads votes from a text file
election read_votes(std::istream &in){
    std::string line;
    election e;
    while(getline(in, line)){
        std::stringstream s(line);
        int num;
        std::vector<unsigned int> cand;
        while(s >> num){
            cand.push_back(num);
        }
        vote v(cand);
        e.add_vote(v);
    }
    return e;
}


