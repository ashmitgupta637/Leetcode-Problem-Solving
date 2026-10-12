/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int n ; 
    int m ; 
    int dr[4] = {-1 , 0 , 1 ,0} ; 
    int dc[4] = {0 , 1 ,0 , -1} ; 

    bool isvalid(int r , int c , vector<vector<int>> &visited ,  vector<vector<int>>& grid){
        return r>= 0 && c>=0 && r< n  && c < m && visited[r][c] == 0 && grid[r][c] == 1 ; 
    }
    int bfs(int r , int c , vector<vector<int>> &visited ,  vector<vector<int>>& grid){
        queue<pair<int , int>> q; 
        q.push({r ,c}) ;
        int area  = 1 ; 
        visited[r][c] = 1 ; 
        while(!q.empty()){
            int x = q.front().first  ; 
            int y = q.front().second ; 
            q.pop() ; 
            for(int i = 0 ; i < 4  ; i++){
                int nx  = x + dr[i] ; 
                int ny = y+dc[i] ; 
                if(isvalid(nx ,ny , visited , grid)){
                    q.push({nx , ny}) ; 
                    area++ ; 
                    visited[nx][ny] = 1; 
                }
                

            }
        }

        return area ; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size() ; 
        m = grid[0].size() ; 

        vector<vector<int>> visited(n , vector<int> (m , 0)) ; 

        int area = 0  ; 
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j]&& grid[i][j] ==1 ){

                    area = max(area, bfs(i , j , visited , grid)) ; 
                }
            }
        }

        return area ; 
    }
};