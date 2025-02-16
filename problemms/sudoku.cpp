#include <bits/stdc++.h>

bool isSafe(int i,int j,vector<vector<int>> &board,int val,int n){

    for(int k=0;k<n;k++){
        //coloum check
        if(board[i][k]==val){
            return false;
        }
        //row check
        if(board[k][j]==val){
            return false;
        }
        // 3x3 check
        if(board[3*(i/3)+k/3][3*(j/3)+k%3]==val){
            return false;
        }
    }
    return true;

}


bool solve(vector<vector<int>>& board){
    int n=board.size();

    //looping
    //i=row and j=coloum
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(i,j,board,val,n)){
                        board[i][j]=val;
                        //recursion
                        bool solution=solve(board);
                        if(solution){
                            return true;
                        }
                        else{
                            //backtracking
                            board[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}