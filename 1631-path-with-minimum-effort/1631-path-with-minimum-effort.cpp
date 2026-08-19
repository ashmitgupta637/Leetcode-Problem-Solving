#include <bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() ; 
        int m = heights[0].size() ; 
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> diff(n , vector<int> (m , 1e9)); 
         
        pq.push({0 , {0, 0} }) ; 

        int dr[] = {-1, 0 , 1 ,0} ; 
        int dc[] = {0 , 1 , 0 , -1} ; 
        diff[0][0] = 0 ; 
        
        
        vector<vector<pair<int,int>>> parent(
    n, vector<pair<int,int>>(m, {-1, -1})
);
       
        while(!pq.empty()){
            int r = pq.top().second.first ; 
            int c = pq.top().second.second ; 
            int effort = pq.top().first ; 
            pq.pop() ; 

            if(r == n-1 && c == m-1) break ; 
            for(int i= 0 ; i< 4 ; i++){
                int nr = r +dr[i] ; 
                int nc = c + dc[i] ;
                 
                if(nr >=0 && nr < n && nc >=0 && nc <m){
                    int jump = abs(heights[r][c]- heights[nr][nc]) ;
                    int newEffort = max(effort, jump);

                    if (newEffort < diff[nr][nc]){
                        diff[nr][nc] = newEffort;

                        parent[nr][nc] = {r, c};

                        pq.push({newEffort , {nr , nc}}) ; 
                    }
                }
                
                    
                

            }

        }
        vector<pair<int,int>> path;

        int r = n - 1;
        int c = m - 1;
            
        while(r != -1 && c != -1) {
            path.push_back({r, c});

            auto it = parent[r][c];

            int pr = it.first;
            int pc = it.second;

            r = pr;
            c = pc;
        }
        
        reverse(path.begin(), path.end());
        return diff[n-1][m-1];
    }
};