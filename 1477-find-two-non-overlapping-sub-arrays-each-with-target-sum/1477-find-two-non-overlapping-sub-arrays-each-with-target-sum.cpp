class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size() ; 

        int i = 0  ; 
        int j= 0 ; 

        int currsum = 0 ; 
        vector<int> minBestlenTill(n , INT_MAX) ; 

        int bestMinlen = INT_MAX ; 
        int result  = INT_MAX ; 

        while(j < n ) {
            currsum += arr[j] ; 

            while(i < j  && currsum > target) {
                currsum -= arr[i++] ; 
            }
            if(currsum == target) {
                int len = j- i + 1 ; 

                if( i  > 0 && minBestlenTill[i-1] != INT_MAX) {
                    result = min(result  , len + minBestlenTill[i-1]) ; 
                }
                
                bestMinlen = min(bestMinlen , len) ; 
            }

            minBestlenTill[j] = bestMinlen ; 

            j++ ; 
        }

        if(result == INT_MAX) {
            return -1 ; 
        }
        return result ; 

    }
};