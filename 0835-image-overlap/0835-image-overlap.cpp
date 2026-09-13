class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // 2D cross correlation  =  translation + maximum overlap 
        // c(dx , dy) = Σ(Σ(i1(x, y ) * i2(x - dx  , y - dy))) ; 

        // ans= max( c(dx  , dy)) ; 
        int n = img1.size() ; 
        
        int ans = 0;

        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            for (int dy = -(n - 1); dy <= n - 1; dy++) {

                int overlap = 0;

                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {

                        int nx = x - dx;
                        int ny = y - dy;

                      
                        if (nx >= 0 && nx < n &&
                            ny >= 0 && ny < n) {

                            overlap += img1[x][y] * img2[nx][ny];
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};