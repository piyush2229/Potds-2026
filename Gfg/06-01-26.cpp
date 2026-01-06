class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=0;
        int left=0;
        int curr=0;
        for(int right=0;right<n;right++){
            curr^=arr[right];
            if(right-left+1>=k){
                maxi=max(maxi,curr);
                curr^=arr[left];
                left++;
            }
        }
        return maxi;
    }
};

// sliding window of size k
// maintain current xor of window
// update maximum xor found
// return maximum xor