/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size() ; 
        int m = maze[0].size() ; 
        queue<tuple<int , int, int>> q ; 
        q.push(make_tuple(entrance[0] , entrance[1] , 0)) ; 
        int dr[4] = {-1 , 0 , 1 , 0} ; 
        int dc[4] = {0  , 1 , 0 , -1} ; 

        vector<vector<int>> visited(n  , vector<int> (m , 0)) ; 
        while(!q.empty()){
            auto it = q.front() ; 
            int r = get<0> (it) ; 
            int c = get<1> (it) ; 
            int d =  get<2> (it) ; 
            q.pop() ; 
            if((r == 0 || r == n-1 || c == 0 || c == m-1) &&
                !(r == entrance[0] && c == entrance[1])){
                return  d ;
            }
            for(int i= 0 ; i < 4 ; i++){
                int nr = r + dr[i] ; 
                int nc = c + dc[i] ; 
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && maze[nr][nc] == '.' && !visited[nr][nc]){
                    visited[nr][nc] = 1  ; 
                    q.push(make_tuple(nr , nc , d+1 )) ; 

                }
            }
        }
        return -1 ; 
    }
};