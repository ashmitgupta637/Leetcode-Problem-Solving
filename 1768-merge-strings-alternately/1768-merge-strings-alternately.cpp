class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 =  word1.size() ; 
        int n2 =  word2.size() ; 
        int left =  0 ; 
        int right = 0 ;  
        string news = "" ; 
        bool turn = false  ; //left 
        while(left < n1 && right < n2 ) {
            if(turn ==false){
                news+= word1[left] ;  
                left++ ; 
                turn = true ; 
            }else{
                news += word2[right] ; 
                right++ ; 
                turn = false ; 
            }
        }
        if(left  < n1 ){
            string   k =  word1.substr(left , n1-left+1)  ; 
            news += k ; 
        }else if(right < n2){
            news += word2.substr(right, n2-right+1)  ; 
        }
        return news ; 
    }
};