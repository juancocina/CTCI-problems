/*
    5.2 Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
    print the binary representation. If the number cannot be represented
    accurately in binary with at most 32 characters, print "ERROR"

    I tried my own attempt at the problem, but didn't come to a good approach
    I decided to look at the books solution after about an hour or so
*/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void decToBinary(int n) {
    if(n/2 != 0) 
        decToBinary(n/2);

    std::cout << n % 2;
}

// my solution (does not work)
string binaryToString(double bin) {
    if(bin > 1 || bin < 0) return "ERROR";
    string res = "";
    while(bin > 0) {
        bin *= 2;
        if(bin >= 1) {
            res += "1";
            bin -= 1;
        }
        else 
            res += "0";
    }
    return res.size() > 32 ? "ERROR" : res;
}

// book solution (returns ERROR for everything)
string printBinary(double num) {
    if(num > 1 || num < 0) return "ERROR";

    string res = "";
    while(num > 0) {
        if(res.size() > 32) return "ERROR";

        double r = num * 2;
        if(r >= 1) {
            res += "1";
            num = r-1;
        } else {
            res += "0";
            num = r;
        }
    }

    return res;
}

// online soluition that works, but still kind of wonky
string bToS(double num) {
    if (num <= 0 || num >= 1) return "ERROR";

    stringstream ss;
    ss << "0.";

    // up to 30 because '0.' takes two slots
    for(int i = 0; i < 30; i++) {
        num *= 2;
        if(num >= 1) {
            ss << "1";
            num -= 1;
        }
        else ss << "0";
    }
    if(num != 0) return "ERROR";
    return ss.str();
}

int main() {
    cout << bToS(0.625);
    return 0;
}