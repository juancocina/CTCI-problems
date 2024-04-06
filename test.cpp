#include<iostream>
#include<string>
using namespace std;

string ans(int n) {
    string num = to_string(n);
    string results;
    int count = 0;
    for(int i = num.size(); i >= 0; i--){
        if(count == 2) {
            string k = "."+ num[i];

        }else count++;
    }

    return results;
}

int main() {
    string number = "1234";
    string k = "";
    k += ".";
    k += number[2];

    cout << k << endl;
    //std::cout << ans(1234) << std::endl;
    return 0;
}