class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int ans=0;
        int n=arr.size();
        int left=0;
        unordered_map<int,int>ss;
        for(int right=0;right<n;right++){
            ss[arr[right]]++;
            while(ss.size()>k){
                ss[arr[left]]--;
                if(ss[arr[left]]==0)ss.erase(arr[left]);
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
};
// calculate number of subarrays with at most k distinct elements
// use sliding window approach
// for each right pointer, move left pointer to maintain at most k distinct elements
// count number of valid subarrays ending at right pointer
// return total count of such subarrays
