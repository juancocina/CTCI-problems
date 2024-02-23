/*
    1.9 String Rotation: Assume you have a method isSubstring
    which checks if one word is a substring of another. Given two strings
    s1 and s2, write code to check if s2 is a rotation of s1 using only
    one call to isSubstring (e.g "waterbottle" is a rotation of "erbottlewat")
*/
#include <iostream>
#include <string>
using namespace std;

bool isSubstring (string s1, string s2);

bool isRotated(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    if(s1.size() == 0 || s2.size() == 0) return false;

    if(isSubstring(s1+s1, s2)) return true;
    return false;
}


int main(){

    return 0;
}

/*
    I weirdly spent a lot of time on this one, for some reason I felt like
    I was being tricked
    
    I got to a solution fairly quickly, the hints gave it all away,
    but I stayed on it a bit longer because it felt TOO easy
 */