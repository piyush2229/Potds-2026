class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int>ans;
        int n=arr.size();
        int left=0;
        unordered_map<int,int>mpp;
        for(int right=0;right<n;right++){
            mpp[arr[right]]++;
            if(right-left+1==k){
                ans.push_back(mpp.size());
                mpp[arr[left]]--;
                if(mpp[arr[left]]==0)mpp.erase(arr[left]);
                left++;
            }
        }
        return ans;
    }
};
// sliding window of size k
// use hashmap to count frequency of elements in current window
// when window size reaches k, store size of hashmap (number of distinct elements) in answer
// slide the window by removing the leftmost element and incrementing the left pointer
// return the answer vector