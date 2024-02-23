/*
    1.4 Palinedrome Permutation: Given a string, a write a function to check if it
    is a permutation of a palindrome. A palindrome is a word or phrase that is
    the same forwards and backwards. A permutation is a rearrangment of letters.
    The palindrome does not need to be limited to just dicitonary words.
    You can ignore casing and non-letter characters.
*/
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

bool palindromePermutationCheck(std::string s){
    bool flag = false;
    std::unordered_map<char, int> hash;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ') hash[tolower(s[i])]++;
    }
    for(auto it : hash){
        if(it.second % 2 == 1){
            if(flag == false) flag = true;
            else if(flag == true) return false;
        }
    }
    return true;
}

int main(){
    // Example
    std::string ex = "Tact Cao";
    if(palindromePermutationCheck(ex) == true) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    return 0;
}

/*
    I don't think this problem should've taken me as long as it did
    The if statement at lines 21-24, or more specifically, the ones inside
    of that, confused me more than they should have.

    I wasn't sure when to check to see if the flag had been triggered already.
    If i checked before line 21, then there was a chance for a false negative.
    If i checked at line 23 without the else, there was a chance for a false
    negative. I spent way too much time on that.

    The other big thing that I missed during my initial breakdown of the problem,
    was checking for non-letter characters. More specifically, ignoring
    non-letter characters.

    When I wrote down my solution on paper, I simply went through the example
    and mentally skipped the space in "taco cao".
    I also did not take into account the casing.
    Mentally, I just assumed that characters would be inserted into the hash
    table with casing ignored.

    There were two things I got wrong about this problem, and it really did
    start at the beginning. I understood what the question was asking of me,
    which was to ignore casing and non-letter, but I did not take into 
    account that it's also something that should be implemented in code.
    The computer will not automatically do that for me.

    Originally, line 18 did not have the if(not space) and tolower.
    I simply did hash[s[i]]++ to insert the characters.
    In the example given, it created two buckets for T,
    one for 'T' and one for 't', which resulted in a false return.

    Those were the two corrections I made to my code after the fact...
*/