#include <iostream>
#include "votes/Vote.h"
#include <vector>

int main() {
    std::vector<unsigned int> prefs;
    Vote vote(prefs);
    if(vote.spent()){
        std::cout << "No preferences left." << std::endl;
    }else{
        std::cout << vote.first_preference();
    }
    return 0;
}