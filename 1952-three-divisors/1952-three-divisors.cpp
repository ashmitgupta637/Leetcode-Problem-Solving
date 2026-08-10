class Solution {
public:
    bool isThree(int n) {
        int cnt = 1 ; 

        for(int i = 2  ; i <= sqrt(n) ; i++){
            if(n%i == 0){
                int div2 = n/i ; 
                cnt++ ; 
                if(div2 != i) {
                    cnt++ ; 
                }
            }
        }
        cnt++ ; 

        if(cnt == 3 ) return true ; 
        return false ; 
    }
};