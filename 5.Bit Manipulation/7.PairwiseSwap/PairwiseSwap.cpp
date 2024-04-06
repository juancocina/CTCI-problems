/*
    5.7 Pairwise Swap: Write a program to swap off and even bits in an integer with as few instructions
    as possible
    (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on)
*/
#include<iostream>
#include<stack>

void manualEvenOddBits(int n) {
    int evenMask = 0;
    int oddMask = 0;
    int original = n;

    // how do we make alternate 1 and 0 for masks?
    for(int i = 30; i >= 0; i--) { // we skip bit 31 to avoid creating a negative number
        int m;
        if(i %2 == 0) { // this makes an oddMask
            m = (1 << i);
            oddMask |= m;
        }
        else { // this makes an evenMask
            m = (1 << i);
            evenMask |= m;
        } 
    }

    while(evenMask != 0) {
        if(evenMask & 1) std::cout << "1 ";
        else std::cout << "0 ";
        oddMask >>= 1;
    }
    std::cout << std::endl;
    while(oddMask != 0) {
        if(oddMask & 1) std::cout << "1 ";
        else std::cout << "0 ";
        oddMask >>= 1;
    }
    std::cout << std::endl;
}

void pairwiseSwap(int n) {
    int evenMask = 0xaaaaaaaa;
    int oddMask = 0x55555555;
    int original = n;
    
    // set the appropriate bits on the masks
    evenMask &= original;
    oddMask &= original;

    // shift masks (even right, odd left)
    evenMask >>= 1;
    oddMask <<= 1;

    int result = oddMask | evenMask;

    // above is the solution, Time: O(1) Space: O(1)
    // below is code to display the results for my own sake
    std::cout << "Resulting in: " << result << std::endl;
    std::cout << "As binary: ";
    std::stack<int> st;
    while(result != 0) {
        if(result & 1) st.push(1);
        else st.push(0);
        result >>= 1;
    }
    while(!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }

    std::cout << std::endl;
}

int main() {
    int one = 110;
    int two = 618;
    int three = 1979;

    std::cout << "Initial int: " << one << " & ";
    pairwiseSwap(one);

    std::cout << "Initial int: " << two << " & ";
    pairwiseSwap(two);

    std::cout << "Initial int: " << three << " & ";
    pairwiseSwap(three);

    return 0;
}   