class Solution {
public:
    int solve(int i, int n, int prev1, int prev2, int prev3,int mod,vector<vector<vector<vector<int>>>>&dp){
        if(i==n) return 1;
        if(dp[i][prev1][prev2][prev3]!=-1) return dp[i][prev1][prev2][prev3];
        int ans=0;
        for(int col1=1;col1<=3;col1++){
            if(col1==prev1) continue;
            for(int col2=1;col2<=3;col2++){
                if(col2==prev2 || col1==col2) continue;
                for(int col3=1;col3<=3;col3++){
                    if(col3==prev3 || col2==col3)continue;
                    ans=(ans+solve(i+1,n,col1,col2,col3,mod,dp))%mod;
                }
            }
        }
        return dp[i][prev1][prev2][prev3]=ans;
    }
    int numOfWays(int n) {
        int mod=1e9+7;
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        return solve(0,n,0,0,0,mod,dp);
    }
};

// We are painting a grid row by row, where each row has 3 cells and 3 possible colors.

// At any row, the only thing that matters for future rows is:

// What colors were used in the previous row’s 3 columns
// → so we keep (prev1, prev2, prev3) as state.

// For the current row:

// We try all valid color triples (col1, col2, col3) such that:

// No column repeats its previous row color
// col1 ≠ prev1, col2 ≠ prev2, col3 ≠ prev3

// No two adjacent columns in the same row have the same color
// col1 ≠ col2 and col2 ≠ col3

// For every valid triple, we move to the next row and add its ways.