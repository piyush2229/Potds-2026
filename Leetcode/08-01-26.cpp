class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,INT_MIN));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int prod=nums1[i]*nums2[j];
                dp[i][j]=prod;
                if(i>0 && j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+prod);
                if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[n1-1][n2-1];
    }
};
// use dynamic programming to calculate maximum dot product
// dp[i][j] represents maximum dot product using first i elements of nums1 and first j elements of nums2
// for each pair of elements, calculate product and update dp table considering three cases:
// 1. taking the product of current elements
// 2. adding product to previous maximum dot product
// 3. skipping current element from either nums1 or nums2
// return maximum dot product for all elements in both arrays
