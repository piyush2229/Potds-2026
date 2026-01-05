class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int ans=0;
        int sum=0;
        int n=arr.size();
        int left=0;
        for(int right=0;right<n;right++){

            sum+=arr[right];
            if(right-left+1>=k){
                ans=max(ans,sum);
                sum-=arr[left];
                left++;
            }
        }
        return ans;
    }
};
//use two pointer approach to maintain a window of size k
// when the window size reaches k, update the maximum sum and slide the window by removing the leftmost element and incrementing the left pointer