/*
    Going over the explanation of Sieve of Erastothenes in the book
    and implementing it in c++

    1. Cross off all the numbers divisble by 2
    2. Look for the next prime (the next non-crossed off number) and
       cross off all numbers divisible by it

*/

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// extra function to check if a number is prime
bool isPrime(int n) 
{
    if(n < 2) return false;
    
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return true;
}

void crossOff(vector<bool>& flags, int& prime) 
{
    for(int i = prime*prime; i < flags.size(); i+=prime)
        flags[i] = false;
}

int getNextPrime(vector<bool>& flags, int prime)
{
    int next = prime+1;

    // while next is less than the vectors size and the index at next is false, inc next
    while(next < flags.size() && flags[next] != false)
        next++;

    return next;
}

vector<bool> sieveOfErastothenes(int max)
{
    // create the vector and set the flags to true
    vector<bool> flags(max+1, true);
    int count = 0;

    // set the prime number
    int prime = 2;

    // 0 and 1 are false by default
    flags[0] = false;
    flags[1] = false;

    while(prime <= sqrt(max))
    {
        // cross off multiple of prime
        crossOff(flags, prime);
        // get the next prime
        prime = getNextPrime(flags, prime);
    }

    return flags;
}

int main() {
    int max = 54;
    vector<bool> result = sieveOfErastothenes(max);

    for(int i = 0; i < result.size(); i++){
        if(result[i] == true) cout << i << " ";
    }
    cout << endl;

    // checking if a number is prime
    if(isPrime(17)) cout << 17 << " is prime\n";

    return 0;
}