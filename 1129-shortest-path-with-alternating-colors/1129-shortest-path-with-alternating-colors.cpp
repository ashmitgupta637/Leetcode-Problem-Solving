class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, 
                                        vector<vector<int>>& redEdges, 
                                        vector<vector<int>>& blueEdges) {

        vector<vector<int>> redAdj(n), blueAdj(n);

        for(auto& edge : redEdges) {
            redAdj[edge[0]].push_back(edge[1]);
        }

        for(auto& edge : blueEdges) {
            blueAdj[edge[0]].push_back(edge[1]);
        }

        queue<pair<int, int>> q;

        vector<vector<int>> dist(n, vector<int>(2, -1));

        q.push({0, 0});
        q.push({0, 1});

        dist[0][0] = 0;
        dist[0][1] = 0;

        while(!q.empty()) {

            auto [node, col] = q.front();
            q.pop();

            if(col == 0) {

                for(auto iter : blueAdj[node]) {

                    if(dist[iter][1] == -1) {

                        dist[iter][1] = dist[node][0] + 1;

                        q.push({iter, 1});
                    }
                }
            }

            else {

                for(auto iter : redAdj[node]) {

                    if(dist[iter][0] == -1) {

                        dist[iter][0] = dist[node][1] + 1;

                        q.push({iter, 0});
                    }
                }
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            int redDist = dist[i][0];
            int blueDist = dist[i][1];

            if(redDist == -1 && blueDist == -1) {
                ans[i] = -1;
            }
            else if(redDist == -1) {
                ans[i] = blueDist;
            }
            else if(blueDist == -1) {
                ans[i] = redDist;
            }
            else {
                ans[i] = min(redDist, blueDist);
            }
        }

        return ans;
    }
};