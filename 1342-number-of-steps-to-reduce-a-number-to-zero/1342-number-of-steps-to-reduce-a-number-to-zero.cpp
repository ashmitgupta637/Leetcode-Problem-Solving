class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0  ;
        if(num == 0 ) {
            return 0 ; 
        }
        if( num%2 == 0) {
            ans = num/2 ; 
        }else {
            ans = num -1 ; 

        }
        int cnt = 1 ; 

        while(ans != 0 ) {
            if(ans%2 == 0 ) {
                cnt++ ; 
                ans = ans/2 ; 
            }else {
                cnt++ ; 
                ans = ans-1 ; 
            }
        }
        return cnt ; 
    }
};