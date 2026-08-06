class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true) {
            int num = n ; 
            int prod = 1 ; 
            while(num != 0 ){
                int digit = num%10 ; 
                num = num/10 ; 
                prod = prod* digit ; 
            }
            if(prod% t ==0 ) {
                return n ; 
            }else{ 
                n++ ; 
            }

        }
        


    }
};