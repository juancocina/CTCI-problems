/*
    1.8 Zero Matrix: Write an algorithm such that if an element
    in an M x N matrix is 0, its entire row & column are set to 0.
*/

#include <iostream>
#include <utility>
#include <vector>

void printMatrix(std::vector<std::vector<int>>& matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void zeroMatrix(std::vector<std::vector<int>>& matrix){
    std::vector<std::pair<int,int>> zeros;
    int M = matrix.size(), N = matrix[0].size();
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++){
            if(matrix[i][j] == 0){
                zeros.push_back(std::make_pair(i, 0));
                zeros.push_back(std::make_pair(0, j));
            }
        }
    } // create a list of rows and columns to zero based off any zeros in the matrix

    for(auto pair: zeros){
        if(pair.first == 0) { 
            int t = 0; 
            while (t < M){
                matrix[t][pair.second] = 0;
                t++;
            }
        }
        if(pair.second == 0) {
            int t = 0;
            while(t < N){
                matrix[pair.first][t] = 0;
                t++;
            }
        }
    } // run through the rows and columns and turn them to zeros..
} // O(N^2) time, O(N) space

//translating the books solution to c++
void nullifyRow(std::vector<std::vector<int>>& matrix, int row){
    for(int j = 0; j < matrix[0].size(); j++){
        matrix[row][j] = 0;
    }
}
void nullifyCol(std::vector<std::vector<int>>& matrix, int col){
    for(int i = 0; i < matrix.size(); i++){
        matrix[i][col] = 0;
    }
}
void setZeros(std::vector<std::vector<int>>& matrix){
    bool rowHasZero = false;
    bool colHasZero = false;

    //check if first row has a zero
    for(int j = 0; j < matrix[0].size(); j++){
        if(matrix[0][j] == 0) {
            rowHasZero = true;
            break;
        }
    }
    //check if first col has a zero
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] == 0){
            colHasZero = true;
            break;
        }
    }

    //check for zeros in the rest of the matrix
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix.size(); j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // nullify rows based on values in the first column
    for(int i = 1; i < matrix.size(); i++){
        if(matrix[i][0] == 0){
            nullifyRow(matrix, i);
        }
    }
    // nullify columns based on values in the first row
    for(int j = 1; j < matrix[0].size(); j++){
        if(matrix[0][j] == 0){
            nullifyCol(matrix, j);
        }
    }

    // nullify first row
    if(rowHasZero) nullifyRow(matrix, 0);
    // nullify first col
    if(colHasZero) nullifyCol(matrix, 0);
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4, 5},
                                            {6, 0, 8, 9, 10},
                                            {11, 12, 13, 0, 15},
                                            {16, 17, 18, 19, 20}};
                                            // 5 x 4 matrix
                                            // M = 5, N = 4
    
    printMatrix(matrix);
    //zeroMatrix(matrix); // my solution
    setZeros(matrix); // books solution
    printMatrix(matrix);
    return 0;
}

/*
    Given the example I came up with, I'd say this is a pretty successful 
    solution. I have not taken a look at the answer in the book yet, but 
    I'm glad I got this one on my own.
    It may not be the most efficient, but it's mine.

    It took me about 3 hours with some breaks in between but thats okay.

    I still had a little bit of trouble with the space, since I
    wasn't too sure how to calculate that.
    I do know that the more zeros we find, the greater our storage will be
    so worst case i think would be O(N)

    Having looked at the solution right now,
    Their way of solving it with constant space is pretty cool.

    They used the first row and column to keep track of whether or not
    there is a zero later down the matrix, then nullifing the matrix
    base on what is in the first rows and columns. Very cool.
    
    I'm gonna try to translate that code now.
*/