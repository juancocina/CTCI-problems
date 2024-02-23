/*
    1.6 String Compression: Implement a method to perform
    basic string compression using the counts of repeated characters.
    For example, the string aabcccccaaa would become a2b1c5a3. 
    If the "compressed" string would not become smaller than the
    original string, your method should return the string. You can
    assume the string only has uppercase & lowercase letters (a-z).

*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

string stringCompression(string str) {
    int i = 0;
    int j = 0;
    int count = 0;
    string newS = "";
    
    while(j < str.size()){
        if(str[i] == str[j]){
            count++;
            j++;
        }
        else if(str[i] != str[j]){
            newS += str[i];
            newS += to_string(count);
            i = j; 
            count = 0;
        }
    }
    newS += str[i] + to_string(count);
    if(newS.size() < str.size()) return newS;
    return str;
}

int main() {
    vector<string> examples;

    examples.push_back("aabcccccaaa");
    examples.push_back("ssaassaass");
    examples.push_back("abcdefg");
    examples.push_back("AaaAAAaaAAA");
    examples.push_back("a");

    for(auto s : examples){
        cout << stringCompression(s) << endl;
    }
    return 0;
}

/*
    This problem took me a little bit longer than I though it would.
    I didn't look at the hints or the solutions BUT
    It did take me like an hour to come up with a solution 
    Which is O(n) time and i THINK O(n) space. O(n) time because as the input
    string grows, the runtime will increase. There really isn't a way to shorten
    that.
    O(n) space i'm unsure of simply because we add a number character after counting
    the characters in the string, but then again.. adding that number char is a
    constant action.
    its either O(1) or O(n). We also don't add one number for EACH index of the
    input string.. we only do so after we've counted them... But it still grows
    as the input string grows..
    Anyway..

    This one felt like a major success for me.
    I had written up the code on paper, and stepped away for a few days because of 
    work. So, coming back to the page, typing it up and have it immediately work
    felt incredible. A great challenge this was.

    (Update from a few days later)
    I decided to take a look at the answer in the book before moving onto
    the next question. Weird. 
    I don't feel as good about it anymore because I'm not sure if the runtime
    on my solution comes out to O(p + k^2)
    Even running it feels slow.. but I guess part of this job is finding
    bottlenecks like this an improving on them

*/