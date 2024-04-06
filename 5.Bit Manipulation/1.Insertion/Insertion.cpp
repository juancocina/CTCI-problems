/*
    5.1 Insertion: You are given two 32-bit numbers, N and M, and two bit positions,
    i and j. Write a method to insert M into N such that M starts at bit j and ends 
    at bit i. You can assume that the bits j through i have enough space to 
    fit all of M. That is, if M = 1011, you can assume that there are at least 5 bits
    between j and i. You would not, for example, have j = 3 and i = 2, because M could not 
    fully fit between bit 3 and bit 2

    Example
    Input: 
        N = 10000000000, M = 10011, i = 2, j = 6
    
    Output:
        N - 10001001100
*/

#include <iostream>

// my solution
int insertion(int N, int M, int i, int j) {
    int changedM = (M << i);
    int mask = (-1 << (j+1));
    int mask2 = ((1 << i) - 1);
    mask = mask+mask2;
    N = N & mask;

    return N + changedM;
}

// books solution
int updateBits(int n, int m, int i, int j) {
    if(i > j || i < 0 || j >= 32) return 0;

    // Create a mask to clear bits i through j in n
    int allOnes = ~0;

    // 1s before position j, then 0s;
    int left = j < 31 ? (allOnes << (j+1)) : 0;

    // 1s after position i
    int right = ((1 << i) - 1);

    // All 1s, except for 0s between i and j
    int mask = left | right;

    // clear bits j through i then put m in there
    int nCleared = n & mask;
    int m_shifted = m << 1;

    return nCleared | m_shifted;
}

int main() {
    int N = 1024; 
    int M = 19;
    int R = 1100;

    int results = insertion(N, M, 2, 4);
    int bookResults = updateBits(N, M, 2, 4);

    std::cout << "My Results: " << results << std::endl;
    std::cout << "Book Results: " << bookResults << std::endl;

    return 0;
}

/*
    So, my solution and the books solution appear to work out to the same answer

    However, there are some differences, 
    my algo returns a clearedN + shiftedM
    The books algo return clearedN | shiftedM

    In my initial testing, i made the mistake of using
    int N = 1000000...
    int M = 10011
*/