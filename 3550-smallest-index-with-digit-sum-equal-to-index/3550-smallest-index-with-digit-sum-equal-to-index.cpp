class Solution {
public:
    int smallestIndex(vector<int>& nums) {
       

        for(int i = 0 ; i < nums.size() ; i++){
            int number = nums[i] ; 
            int sum = 0 ; 
            while(number != 0){
                int digit = number % 10 ; 
                number = number /10  ; 
                sum += digit ; 
            }
            if(sum == i) return i ; 
        }


        return -1 ;
    }
};