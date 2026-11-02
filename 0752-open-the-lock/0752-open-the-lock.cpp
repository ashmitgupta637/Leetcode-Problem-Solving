class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        q.push({"0000" , 0}) ; 
        unordered_set<string> visited ; 

        for(int i = 0 ;i < deadends.size()  ; i++){
            visited.insert(deadends[i]) ; 

        }
        if(visited.find("0000") != visited.end()) {
            return -1;
        }
        visited.insert("0000") ; 
        char dir[10] = {'0' , '1' , '2'  , '3' , '4' , '5' , '6', '7' , '8', '9'};
        while(!q.empty()){
            string node = q.front().first ; 
            int d  = q.front().second ; 
            q.pop() ; 
            if(node == target ) return d ; 
            for(int i = 0 ; i < 4 ; i++){
                string next = node ;
                string prev = node ; 
                //i th wheel 
                char forward ; 
                if(node[i] == '9'){
                    forward = '0' ; 
                    next[i] = forward  ; 
                }else{
                    forward  =  node[i] + 1 ; 
                    next[i] = forward; 
                } 
                char back ; 
                if(node[i] == '0'){
                    back = '9' ;
                    prev[i] = back ; 
                }else {
                    back = node[i] - 1 ; 
                    prev[i] = back ; 
                }
                if(visited.find(next) == visited.end()){
                    q.push({next  , d+1}) ; 
                    visited.insert(next) ; 
                }
                if(visited.find(prev)  ==  visited.end()){
                    q.push({prev , d+1}) ; 
                    visited.insert(prev) ; 
                }
            }
        }
        return -1 ; 
    }
};