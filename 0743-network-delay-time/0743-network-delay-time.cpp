class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dis(n+1,1e9);
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q; 
        q.push({0, k});
        dis[k] = 0 ;
        
        while(!q.empty()){
            auto it = q.top();
            int node = it.second;
            int t = it.first;
            q.pop();
            if(t>dis[node]) continue;            for(auto iter : adj[node]){
                int adjnode = iter.first;
                int edw = iter.second;
                
                if(edw+t < dis[adjnode]){
                    dis[adjnode] = edw + t; 
                    q.push({dis[adjnode], adjnode});
                }
            }
            
        }
    
    int maxi =0;
    for(int i =1; i <=n ; i++){
        if(dis[i] == 1e9) return -1;
        maxi = max(maxi, dis[i]);
    }
    
    return maxi ;
    }
};