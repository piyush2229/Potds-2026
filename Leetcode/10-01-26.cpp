class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        for(int j=1;j<=n2;j++){
            dp[0][j]=dp[0][j-1]+s2[j-1];
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
// use dynamic programming to calculate minimum ASCII delete sum
// dp[i][j] represents minimum delete sum to make first i characters of s1 and first j characters of s2 equal
// if characters are equal, no deletion needed, carry forward previous value
// if characters are not equal, consider two cases:
// 1. delete character from s1 and add its ASCII value to the sum
// 2. delete character from s2 and add its ASCII value to the sum
// take the minimum of the two cases
// return minimum delete sum for all characters in both strings
