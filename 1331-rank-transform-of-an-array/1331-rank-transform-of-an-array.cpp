class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr2 = arr ; 
        set<int> visited ;  
        sort(arr.begin(), arr.end())  ; 
        unordered_map<int , int> pos ;
        int rep = 0 ;
        int i = 0 ; 
        while(i < arr.size()) {
            if(visited.count(arr[i]) == 0 ){
                pos[arr[i]] = i+1 ; 
                visited.insert(arr[i]) ; 
                rep = i ; 
                
                
            }else{
                arr.erase(arr.begin()+i) ;
                i = rep ;  
            }
            i++  ;
            
        }
         

        for(int i = 0 ; i < arr2.size() ; i++) {
            arr2[i] = pos[arr2[i]]  ;

        }

        return arr2; 
    }
};