#include <bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m =  board.size() ; 
        int n = board[0].size() ; 
        queue<pair<int , int>> q  ;
        vector<vector<int>> visited(m , vector<int> (n  ,0))  ; 
        for(int i = 0 ; i < m ; i++ ){
            if(i == 0 || i == m-1){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j] == 'O'){
                        q.push({i , j }) ; 
                        visited[i][j] = 1 ; 
                    }
                }
            }else{
                if(board[i][0] == 'O'){
                    q.push({i, 0}) ; 
                    visited[i][0] =1  ; 
                }

                if(board[i][n-1] == 'O'){
                    q.push({i , n-1}) ; 
                    visited[i][n-1] = 1 ; 
                }

            }
        }

        int delrow[] = {-1, 0 , 1 , 0}  ; 
        int delcol[] = {0 , 1 , 0 , -1} ; 
        while (!q.empty())
        {
            int r = q.front().first ; 
            int c = q.front().second ; 
            q.pop() ;

            for(int i = 0 ; i < 4 ; i++){
                int nrow = r+ delrow[i] ; 
                int ncol = c+ delcol[i] ; 
                if(nrow>=0 && nrow < m && ncol >=0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol]  == 'O'){
                    visited[nrow][ncol] =1 ; 
                    q.push({nrow , ncol}) ; 
                }
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j =0; j < n  ; j++){
                if(visited[i][j] != 1 && board[i][j] == 'O' ){
                    board[i][j] = 'X' ; 
                }
            }
        }
        




    }
};