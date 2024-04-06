/*
    5.6 Conversion: Write a function to determine the number of bits you would
    need to flip to convert integer A into integer B
*/

#include<iostream>
int conversion(int A, int B) {
    int s = A ^ B;
    int results = 0;
    while(s != 0) {
        if(s & 1) results++;
        s >>= 1;
    }
    return results;
}

int main() {
    int A = 29;
    int B = 15;
    int results = conversion(A, B);
    std::cout << "To convert " << A << " into " << B << std::endl;
    std::cout << "Bits to flip: " << results << std::endl;
    return 0;
}