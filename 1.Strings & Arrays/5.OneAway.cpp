/*
    1.5 One Away: There are three types of edits that can be 
    performed on a string: insert a character, remvoe a character, or replace
    a character. Given two strings, write a function to check if they
    are one edit (or zero edits) away.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std; //im gonna get tired of writing this

bool checkSameSize(string s1, string s2) {
    int count = 0; //mismatch counter

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]) {
            count++;
            if(count > 1) return false;
        }
    }
    return true;
}

bool checkOneAway(string s1, string s2) {
    int i = 0;
    int count = 0;

    while(i < s2.size()) { //while we don't increment past smaller string size
        if(s1[i + count] == s2[i]) i++;
        else if(s1[i+count] != s2[i]){
            count++;
            if(count > 1) return false;
        }
    }
    return true;
}

bool oneAway(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    bool result;

    if((abs(n-m)) >= 2) return false; //not one or zero away

    //check equal size strings (replace a character)
    if(n == m) result = checkSameSize(s1, s2);
    //check size difference of 1 strins (insert or delete character)
    else if(n > m) result = checkOneAway(s1, s2);
    else result = checkOneAway(s2, s1);
    //the larger string goes first. It matters in checkOneAway...

    return result;
}

int main() {
    //strings for testing
    string s1 = "pale";
    string s2 = "ple"; //true

    string s3 = "pales";
    string s4 = "pale"; //true

    string s5 = "pale";
    string s6 = "bale"; //true

    string s7 = "pale";
    string s8 = "bake"; //false

    string s9 = "tomorrow";
    string s10 = "tomorr"; //false

    if(oneAway(s1, s2)) cout << "1. True" << endl;
    else cout << "1. False" << endl;

    if(oneAway(s3, s4)) cout << "2. True" << endl;
    else cout << "2. False" << endl;

    if(oneAway(s5, s6)) cout << "3. True" << endl;
    else cout << "3. False" << endl;

    if(oneAway(s7, s8)) cout << "4. True" << endl;
    else cout << "4. False" << endl;

    if(oneAway(s9, s10)) cout << "5. True" << endl;
    else cout << "5. False" << endl;

    return 0;
}

/*
    Afterthoughts...

    Initially, I really struggled with this problem. 
    It took me about a week to come back to it. It felt like a big roadblock
    in comparison to the other problems. Or maybe I just wasn't feeling it that
    day. I ended up caving and taking a look at a solution online.

    What REALLY took my head out of this problem was not understanding
    how I would traverse the strings. Part of me thought that I actually
    had to perform one of the three operations on the strings too.

    The if statement from lines 30 through 34 was what got me out of my rut.
    I didn't look at the code online, I just saw the psuedo code and thought 
    process behind it.
    The way the solution involves a mismatch counter to increment through one
    string, while maintaining a position on the other was practically genius
    I hope to remember that technique in the future.

    I don't consider this a fully successful problem for me, 
    since I had to get outside help. But I still consider it a win because
    it showed me some flaws in my logic, my mindset, and I also learned 
    a new technique...

    The book mentions a way to merge the solution into one pass,
    but to be honest I don't really want to do that. Onto the next...
*/