#include <iostream>
using namespace std;
#define BLOCK 9
#define SUBBLOCK 3
#define CELLS (BLOCK*BLOCK)

bool placeNum(int n , int sudoku[BLOCK][BLOCK]){
    // if cells are full
    if(n==CELLS){
        for (int i = 0; i < BLOCK;i++){
            for (int j = 0; j < BLOCK;j++){
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // test
    int row = n / BLOCK;
    int col = n % BLOCK;
    // if the cell has data
    if(sudoku[row][col]!=0)
        return placeNum(n + 1, sudoku);

    for (int t = 1; t <= BLOCK;t++){
        bool conflict = false;
        for (int i = 0; i < BLOCK && !conflict;i++){
            // check the target row and col
            if(((col!=i)&&(sudoku[row][i]==t)) || ((row!=i)&&(sudoku[i][col]==t)))
                conflict = true;
        }
        if(!conflict){
            int blockRow = row / SUBBLOCK;
            int blockCol = col / SUBBLOCK;
            for (int i = 0; i < SUBBLOCK && !conflict;i++){
                for (int j = 0; j < SUBBLOCK && !conflict;j++){
                    // check the 3*3 block
                    if(sudoku[SUBBLOCK*blockRow+i][SUBBLOCK*blockCol+j]==t)
                        conflict = true;
                }
            }
            if(!conflict){
                sudoku[row][col] = t;
                if(placeNum(n+1,sudoku))
                    return true;
            }
        }
    }
    sudoku[row][col] = 0;
    return false;
}

int main(){
    int sudoku[BLOCK][BLOCK];
    for (int i = 0; i < BLOCK;i++){
        for (int j = 0; j < BLOCK;j++)
            cin >> sudoku[i][j];
    }
    cout << "ans:\n";
    placeNum(0, sudoku);
    return 0;
}