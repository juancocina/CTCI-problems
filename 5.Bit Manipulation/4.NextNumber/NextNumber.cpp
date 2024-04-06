/*
    5.4 Next Number: Given a positive interger, print the next smallest & the
    next largest numebr that have the same number of 1 bits in their binary representation.

    ===
    I have the steps to solving this problem written down in my notebook. I don't have 
    the code written down, just the logic behind it


*/

#include<iostream>

void getNextLargest(int n) {
    int t = n;
    int c1 = 0;
    int c0 = 0;
    int p = 0;
    bool trailingZero = true;

    // find p
    for(; t; t >>= 1) {
        if(t & 1) {
            trailingZero = true;
            c1++;
        }
        else if(trailingZero == true && (t&1) == 0) {
            c0++;
        }
        else if(trailingZero == false && (t&1) == 0) {
            break;
        }
    }

    p = c1 + c0;
    
    // flip the appropriate bit
    t = n;
    t |= 1 << p;

    // clear bits from 0 to p
    int clearBits = ~0;
    clearBits <<= p;
    t &= clearBits;

    // create a new mask that contains c0 0's to the right of p and c1 1's to right of the 0's
    int setBits = 1<<(c1-1);
    setBits -= 1;
    t |= setBits;

    std::cout << "Next Largest Number: " << t << std::endl;

}

void getNextSmallest(int n) {
    // calculate p
    int t = n;
    int c0 = 0, c1 = 0;
    int p = 0;

    while((t&1) && t != 0) {
        c1++;
        t >>= 1;
    }
    while((t&1) == 0) {
        c0++;
        t>>=1;
    }

    p = c1+c0;

    // flip the appropriate bit
    t = n;
    t &= ~(1<<p);

    // clear all bits to the right of p
    int a = ~0;
    a = a << p;
    t &= a;

    // insert c1+1 1s to the right of p
    int b = 1<<(c1+1);
    b -= 1;
    b <<= c0-1;
    t |= b;

    std::cout << "Next Smallest Number" << t << std::endl;
}

int main() {
    int num = 119;
    getNextLargest(num);
    getNextSmallest(num);

    return 0;
}

/*
    Theres definitely a lot to this problem. I think i've learned the most about accessing bits,
    counting bits, and creating masks through this problem. I did have to look at the books logic,
    but it was good practice

    Time: O(b)
    Space: O(1);
    
    the important parts about this problem involve the way to track bits which is by rightshifting
    and thenusing operator & to check whether or not it is a 1 or a 0;
    This is going to important in the future. Creating masks is getting easier to visualize
*/