class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        int n=arr.size();
        map<int,int>mpp;
        int left=0;
        for(int right=0;right<n;right++){
            mpp[arr[right]]++;
            if(right-left+1==k){
                ans.push_back((--mpp.end())->first);
                mpp[arr[left]]--;
                if(mpp[arr[left]]==0)mpp.erase(arr[left]);
                left++;
            }
        }
        return ans;
    }
};
// use sliding window with map to keep track of frequencies
// when window size reaches k, record the maximum element from the map
// then slide the window by removing the leftmost element and adding the next element on the right
// continue until the end of the array is reached
// finally return the list of maximums for each subarray of size k