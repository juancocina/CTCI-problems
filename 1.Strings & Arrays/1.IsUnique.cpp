/*
    Problem 1.1 IsUnique:
    Implement an algorithm to determine if a stringhas all unique charactes.
    What if you cannot use additional data structures?

*/
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

bool isUnique(std::string s){ // my solution
    //size check
    if(s.size() == 0 || s.size() == 1) return true;
    
    std::unordered_map<char, int> hash; //create hashmap
    for(int i = 0; i < s.size(); i++){
        if(hash.count(s[i])) return false; //if exists, return false
        else hash[s[i]]++; //add to table and continue
    }

    return true;
} // Time = O(n), Space O(n)
/*
    This is the solution I came to, 
    if the tests were to ever include NUMBERS or ASCII values outside of the english
    alphabet, the code will fail...
    To fully account for this, the book recommends asking the interviewer if the 
    values that are to be checked are ASCII characters or Unicode characters.


*/

int main() {
    /* Tests */
    std::vector<std::string> strings;
    strings.push_back("ashfqubnwfa");
    strings.push_back("abcdefghijklmnop");
    strings.push_back("a");
    strings.push_back("ab");
    //print result
    for(int i = 0; i < strings.size(); i++){
        if(isUnique(strings[i])) std::cout << "true\n";
        if(!isUnique(strings[i])) std::cout << "false\n";
    }

    return 0;
}

/*
    What I learned from the problem:
    I partially knew the answer already, as it was a problem I had done on leetcode
    before. The important thing for me here was to start implementing their problem
    solving steps, and really taking the time to understand the algorithm before
    coding anything.

    It completely went over my head to check for ASCII values, as I just
    assumed that "string", meant anything with english letters. I limited
    my thinking to that.

    My first brute force solution was their (1) for solving without 
    any additional data structures, but it did not occur to me that 
    sorting the string then using two pointers to check neighboring chars 
    could also result in a viable solution.
*/