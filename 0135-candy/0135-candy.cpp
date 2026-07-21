class Solution {
public:
    int candy(vector<int>& ratings) {
        int left = 0 ; 
        int right = 1 ; 
        int ans = 0 ;
        int n = ratings.size() ; 
        vector<int> candies(n , 1 )  ; 

        while(right < ratings.size()) {
            if(ratings[left]< ratings[right]){
                candies[right] = candies[left]+1 ; 
            }
            left++ ; 
            right++ ;
        }
        left = n-2 ; 
        right = n-1 ; 
        while(left >= 0 ) {
            if(ratings[left] > ratings[right]){
                candies[left] = max(candies[left] , candies[right]+1) ; 
            }
            left-- ; 
            right-- ; 
        }

        for(int i = 0 ; i < candies.size() ; i++) {
            ans  += candies[i] ; 
        }
        return ans ; 
        
    }
};