class Solution {
public:
    // int longestLenSubs(string text1, string text2, int i, int j, vector<vector<int>>&dp){
    //      if(i < 0 || j < 0){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) dp[i][j];
    //     if(text1[i] == text2[j]){
    //         return dp[i][j] = 1 + longestLenSubs(text1, text2, i-1,j-1,dp);
    //     }
    //     return dp[i][j] = 0 + max(longestLenSubs(text1, text2, i-1,j,dp),longestLenSubs(text1, text2, i,j-1,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                   dp[i][j] = 0 + max(dp[i][j-1],dp[i-1][j]);
                }
                
              }
           }
        return dp[n][m];
    }
};