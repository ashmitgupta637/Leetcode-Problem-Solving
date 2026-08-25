class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int x =  0 ; 
        for(int i = 1 ; i < 102 ; i++){
            if(find(nums.begin(), nums.end(), k*i) != nums.end()){
                continue ; 
            }else{
                x = k*i ; 
                break ; 
            }
        }

        return  x ; 
    }
};