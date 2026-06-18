class Solution {
public:
    int solve(int i, int j, string t1, string t2, vector<vector<int>>& dp){
        if(i < 0 || j < 0)
            return 0;

        if(t1[i] == t2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, t1, t2, dp);
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int choice1 = solve(i-1, j, t1, t2, dp);
        int choice2 = solve(i, j-1, t1, t2, dp);

        return dp[i][j] = max(choice1, choice2);
    }

    int lcsTab(string t1, string t2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t1[i-1] == t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, text1, text2, dp);
        return lcsTab(text1, text2, n, m);
    }
};
