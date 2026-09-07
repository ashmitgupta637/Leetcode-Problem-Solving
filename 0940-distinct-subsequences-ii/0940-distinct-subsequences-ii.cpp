class Solution {
    
    #define MOD 1000000007
public:
    int distinctSubseqII(string s) {
        int lastOcc[26];
        memset(lastOcc, -1, sizeof(lastOcc));
        int n=s.size();
        vector<long long> dp(n+1, -1);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            if(lastOcc[s[i-1]-'a']!=-1){
                dp[i]=((2*(dp[i-1]%MOD)%MOD)-dp[lastOcc[s[i-1]-'a']]%MOD + MOD)%MOD;
                
            }else{
                dp[i]=(2*(dp[i-1]%MOD)%MOD);
                
            }
            lastOcc[s[i-1]-'a']=i-1;
        }

        return (dp[n]-1+MOD)%MOD;
    }
};