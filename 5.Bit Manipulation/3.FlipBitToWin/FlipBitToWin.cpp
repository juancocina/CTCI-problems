/*
    You have an integer and you can flip exactly one bit from 0 to a 1.
    Write code to find the length of the longest sequence of 1s you could create

    Example 
        Input: 1775 (or : 11011101111)
        Output: 8
*/
#include<iostream>
#include<cstdlib>

// Counting bits set, Brian Kernighan's way
int countBits(int n) {
    int num = n;
    int count;
    for(count = 0; num; count++){
        num &= num -1;
    }
    return count;
}
/*
    Brian Kernighan's method goes through as many iterations as there are set bits.
    So if we have a 32-bit variable with only the high bit set, then it will only go once 
    through the loop
*/

// counting bits set, the naive way
int countingBits (int n) {
    int num = n;
    int count;
    for(count = 0; num; num >>=1){ // so this shifts bits right by one for each iteration, until num no longer exists
        count += num & 1; // add 1 or 0, depending on whether: (0) & 1 or (1) & 1;
    }

    return count;
} // we're essentially, shifting right, and checking if the last bit is 1 or 0;
/*
    Okay, both of these methods count the set bits, output is 9 for th 9 bits set out of the 11
    in the integer 1775;
*/

int flipBitToWin(int n) {
    int count;
    int num = n;
    int max = 0;
    bool zeroFound = false;
    for(count = 0; num; num >>= 1) {
        if(num & 1) {
            count += num & 1;
        }
        else if(!(num & 1) && !zeroFound) {
            count++;
            zeroFound = true;
        }
        else if(!(num & 1) && zeroFound) {
            count = 0;
            zeroFound = false;
        }
        if(count > max) max = count;
    }
    return max;
}

int main() {
    int result = 0;
    result = flipBitToWin(1775);
    std::cout << result << std::endl;

    return 0;
}

/*
    Be careful how you express runtime. For example, if you say the runtime is O(N), what is N?
    It is not correct to sayt that this algorithm is O(value of the integer).
    This algorithm is O(number of bits). For this reason, when you have potential ambiguity in what
    it might mean, it's best not to use N. This way neither you nor the interviewer are confused.
    Instread, pick a different variable name.

    We used "b" for the number of bits. Something logical works well.
*/