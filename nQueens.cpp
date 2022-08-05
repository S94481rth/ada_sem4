#include<bits/stdc++.h>
using namespace std;

int isSafe(int row,int col,vector<vector<int>>& board,int size){
    int temp_row = row;
    int temp_col = col;
    while(col>=0){
        if(board[row][col] == 1)return 0;
        col--;
    }
    
    col = temp_col;
    
    while(col >=0 && row >=0){
        if(board[row][col] == 1)return 0;
        col--;
        row--;
    }
    
    col = temp_col;
    row = temp_row;
    
    while(col >=0 && row < size){
        if(board[row][col] == 1)return 0;
        col--;
        row++;
    }
    return 1;
}

void printBoard(vector<vector<int>>& board,int size){
    for(int r=0;r<size;r++){
        for(int c =0;c<size;c++){
            cout << board[r][c] << " ";
        }cout<<"\n";
    }
    cout<<"\n";
    return;
}

void solveNQueens(vector<vector<int>>& board,int col,int size){
    if(col == size){
        printBoard(board,size);
        return;
    }
    //printBoard(board,size);
    int c = col;
        for(int r = 0;r < size;r++){
            if(isSafe(r,c,board,size)){
                board[r][c] = 1;
                solveNQueens(board,c+1,size);
                board[r][c] = 0;
            }
        }
    
}

void nQueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    //printBoard(board,n);
    //vector<vector<int>> board = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    //int row=0;
    int col=0;
    solveNQueens(board,col,n);
}

int main(){
    int n;
    printf("Enter board size : ");
    cin>>n;
    nQueens(n);
    return 0;
}
