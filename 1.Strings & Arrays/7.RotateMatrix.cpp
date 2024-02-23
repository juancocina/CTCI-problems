/*
    1.7: Given an image represented by an NxN Matrix, where
    each pirxel in the image is represented by an integer, 
    write a method to rotate an image by 90 degrees.
    Can you do this in place?
*/
#include <iostream>
#include <vector>
using namespace std; // tired of typing this out :/

void printMatrix(vector<vector<int>>& p){
    for(int i = 0; i < p.size(); i++){
        for(int j = 0; j < p.size(); j++){
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotateMatrix(vector<vector<int>>& m){
    int n = m.size();
    if(n < 2 || m[0].size() < 2 || n != m[0].size()) {
        cout << "Rotation not possible";
        return;
    }

    int p = 0;
    int k = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n -1 -i; j++){
            p = m[i][j];
            k = m[j][n-1-i];
            m[j][n-1-i] = p;
            
            p = k;
            k = m[n-1-i][n-1-j];
            m[n-1-i][n-1-j] = p;

            p = k;
            k = m[n-1-j][i];
            m[n-1-j][i] = p;
            p = k;
            m[i][j] = k;
        }
        p = 0;
        k = 0;
    }
    printMatrix(m);
} //Space O(1), Time O (O(N^2))

int main() {
    vector<vector<int>> m = { {1,2,3,4}, 
                              {5,6,7,8},
                              {9,10,11,12},
                              {13,14,15,16}};

    vector<vector<int>> n = { {1,2,3},
                              {4,5,6},
                              {7,8,9}};
    
    vector<vector<int>> p = { {1,2}, {3,4}};
    
    // this is not an NxN matrix, testing anyway
    vector<vector<int>> q = { {1}, {2} }; 

    rotateMatrix(m);
    rotateMatrix(n);
    rotateMatrix(p);
    rotateMatrix(q);

    return 0;
}

/*
    Before I take a look at the answer in the book..

    This problem took me about 8 hours (total time over the span of about 3 days 
    spread out against two and a half weeks) to do.
    I did take a little hint from a youtube video, not for the algorithm,
    just to see the kind of vizualization of the rotation.
    That hint gave me all I needed to figure the rest out on my own.

    This may have been the hardest problem I've done from the book, simply
    because I feel like I didn't give up. I didn't try to cheat. I didn't 
    look up the answer too early. I stuck with it until I solved it.
    I'm really happy and proud of myself because I chose to do it that way.

    Now time to look at the solution and see whats what!
    Okay, first things first, I forgot to check the edge case where its not NxN
    // added that
    Second, their code is definitely cleaner and more understandable, i think,
    because they use good variable names in their code
    Third, I got the time complexity wrong..
        I thought that because the iterators only move through the matrix
        in a diagonal motion, that the work is cut in half.
        The truth is that each index gets touched anyway. Making it O(N^2)
        // made the correction above.
    
    
*/