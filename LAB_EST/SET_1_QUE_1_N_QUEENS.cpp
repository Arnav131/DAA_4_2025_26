// this is problem of n queens

#include<bits/stdc++.h>
using namespace std;


class Solutions{
    public:
        vector<vector<string>> result;
        vector<string> board;
        int n;


    bool is_safe(int row , int col){
        for(int i = 0 ; i<n ; i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        for(int i = row -1 , j = col -1 ; i>=0 && j<n ; i-- , j++){
            if(board[i][j]=='Q'){
                return false;
            }
            return true;
        }
    }

    void solve(int row){
        if(row==n){
            result.push_back(board);
            return;
        }
        for(int col = 0 ; col<n ; col++){
            if(is_safe(row,col)){
                board[row][col]='Q';
                solve(row+1);
                board[row][col]='.';
            }
        }
    }


    vector<vector<string>> solveNquenns(int n){
        this->n = n;
        board = vector<string>(n,string(n,'.'));
        solve(0);
        return result;
    }
};


int main(){
    Solutions s;
    s.solveNquenns(4);
    return 0;
}
