/*
    Problem 1.2 Check Permutation:
    Given two strings, write a method to decide if one
    is a permutation of the other.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility> //for pair & make_pair

// My solution
void createHash(std::string s, std::unordered_map<char, int>& h) {
    for(int i = 0; i < s.size(); i++){
        h[s[i]]++;
    }
}

bool checkPerm(std::string s, std::unordered_map<char, int> h){
    for(int i = 0; i < s.size(); i++) {
        if(!h.count(s[i])) return false;
        if(h[s[i]] <= 0) return false;
        else h[s[i]]--;
    }
    return true;
}

bool isPermutation(std::string A, std::string B) {
    if(A.size() != B.size()) return false;

    std::unordered_map<char, int> hashA;
    std::unordered_map<char, int> hashB;

    createHash(A, hashA);
    createHash(B, hashB);

    if(checkPerm(A, hashB) && checkPerm(B, hashA)) return true;
    return false;
}

// Implementing the books solution using ascii values
bool isPermutationASCII(std::string A, std::string B){
    if(A.size() != B.size()) return false;

    //create hashmap for ASCII values
    std::unordered_map<int, int> values;

    //insert string A values into our hashmap
    for(int i = 0; i < A.size(); i++){
       values[int(A[i])]++;
    }

    //check for equivalent values of string B and subtract 
    for(int i = 0; i < B.size(); i++){
       if( !values.count(int(B[i])) ) return false;
       if( values[int(B[i])] < 0 )  return false;
       else values[int(B[i])]--;
    }
    return true;
}

// Implementing the book solution using ascii values AND a vector
bool iPV(std::string A, std::string B){
    if(A.size() != B.size()) return false;

    //assumption ASCII
    std::vector<int> values(128, 0);

    //insert string A values into our array
    for(int i = 0; i < A.size(); i++){
        values[int(A[i])]++;
    }
    for(int i = 0; i < B.size(); i++){
        values[int(B[i])]--;
        if(values[int(B[i])] < 0 ) return false;
    }

    return true;
}

int main() {
    // tests
    std::vector<std::pair<std::string, std::string>> tests;
    //these first few tests will be testing purely for english words
    tests.push_back(std::make_pair("kappa", "keepo")); // #0 false
    tests.push_back(std::make_pair("kappa", "apapk")); // #1 true
    tests.push_back(std::make_pair("foo", "bar")); // #2 false
    tests.push_back(std::make_pair("almost", "tomorrow")); // #3 false
    tests.push_back(std::make_pair("", "")); // #4 I would say true
    tests.push_back(std::make_pair("just for fun", "nuf rof tsuj")); //#5 true
    
    // int i = 0;
    // for(const auto& pair : tests){
    //     if(isPermutation(pair.first, pair.second)) {
    //         std::cout << "Test #" << i << " = permutation" << std::endl;
    //     }
    //     else {
    //         std::cout << "Test #" << i << " != permutation" << std::endl;
    //     }
    //     i++;
    // }

    int j = 0;
    for(const auto& pair : tests) {
        if(iPV(pair.first, pair.second)) {
            std::cout << "Test #" << j << " = permutation" << std::endl;
        }
        else {
            std::cout << "Test #" << j << " != permutation" << std::endl;
        }
        j++;
    }
    return 0;    
}
/*
    Some after thoughts...
    Again the book makes it clear to ask what type of character will be
    in the strings. The book clarifies that we will be using ASCII values, 
    and that white space matters AND that capital letters matter (though i think
    the capital letters get cleared up with the ASCII values).
    Ex: "God      " is not the same as "dog".

    Going through the solutions that the book gives, 
    One solution is to sort the string before hand, but doesn't really SHOW
    a sorting algorithm, it uses the standard java one (O(n log n)).

    The second solution is using a hashmap like array.
    In C++, i think it would be created as unordered_map<int, int> hashmap;
    I thought you could initialize it with a certain size, but it seems like
    the values will be inserted as it goes. When it comes to grabbing the ASCII 
    value, i think I can just use int(s[i])

    I also think (thought i'm not sure), you could do
    vector<int> values = new int[128];

    Or: h[int(s[i])]++;
    i should come back in here and add more tests 

    == Final Thoughts
    I think for the next set of questions I do,
    I REALLY need to take into account the input values,
    I know they're gonna be strings, but what are the strings MADE OF
*/

/*
    I don't have time to code the whole thing and test, but I think it would
    look something like this

    bool isPerm(std::string A, std::string B){
        unordered_map<int,int> h;
        for(int i = 0; i < A.size(); i++){
            h[int(s[i])]++;
        }

        for(int i = B.size() -1; i >= 0; i--){
            if(h[int(s[i])] < 0) return false;
        }
        return true;
    }
*/