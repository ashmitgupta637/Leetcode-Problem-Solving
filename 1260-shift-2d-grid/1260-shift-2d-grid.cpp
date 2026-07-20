class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr ;
        for(int idx = 0 ; idx < grid.size()*grid[0].size() ; idx++) {
            int i = idx/(grid[0].size()) ; 
            int j = idx % grid[0].size() ; 
            arr.push_back(grid[i][j]) ; 

        }

        k = k% (grid.size()*grid[0].size()) ; 
        if(k== 0 ) return grid ; 
        reverse(arr.begin() , arr.end()) ; 
        reverse(arr.begin() , arr.begin()+k ) ; 
        reverse(arr.begin() +k , arr.end()) ; 
        vector<vector<int>> grid2(grid.size() , vector<int>(grid[0].size()))  ; 
        int idx = 0 ; 
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                grid2[i][j] = arr[idx++] ; 
            }
        }
        return grid2 ; 
    }
};