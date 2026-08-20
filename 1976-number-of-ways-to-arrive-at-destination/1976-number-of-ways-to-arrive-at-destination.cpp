#include <bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n] ; 

        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]}) ; 
            adj[it[1]].push_back({it[0] , it[2]}) ; 

        }

        priority_queue<pair<long long, int> , vector<pair<long long , int>> , greater<pair<long long, int>>> pq  ; 
        pq.push({0, 0}) ; 
        vector<long long> dis(n , LLONG_MAX)  ; 
        vector<int>  ways(n  ,0) ; 
        ways[0] = 1 ; 
        dis[0] = 0 ; 
        int mod = (int)(1e9+7) ; 

        while(!pq.empty()){
            int node = pq.top().second; 
            long long d  = pq.top().first; 

            pq.pop() ; 
            if(d > dis[node]) continue;
            for(auto it: adj[node]){
                int adjnode  = it.first ; 
                int edw = it.second ; 

                if(d+edw < dis[adjnode]){
                    dis[adjnode] = d+ edw ; 
                    pq.push({d+edw , adjnode}) ; 
                    ways[adjnode] = ways[node] ; 
                }
                else if(d+ edw == dis[adjnode]){
                    ways[adjnode] = (ways[node] + ways[adjnode]) %mod ; 
                }
            }
        }

        return ways[n-1] %mod ; 
    }
};