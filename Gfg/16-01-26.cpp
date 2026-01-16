class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<pair<int,int>>intervals;
        for(int i=0;i<n;i++){
            int l=max(0,i-arr[i]);
            int r=min(n-1,i+arr[i]);
            intervals.push_back({l,r});
        }
        if(intervals.size()==0) return -1;
        sort(intervals.begin(),intervals.end());
        int count=0;
        int curr=0;
        int i=0;
        while(curr<n){
            int far=-1;
            while(i<intervals.size() && intervals[i].first<=curr){
                far=max(far,intervals[i].second);
                i++;
            }
            if(far<curr) return -1;
            count++;
            curr=far+1;
        }
        return count;
    }
};

// Find the minimum number of men needed to cover the entire range from 0 to n-1
// Create intervals based on each man's position and range
// Sort intervals by their starting point
// Use a greedy approach to select the minimum number of intervals that cover the entire range
// Return -1 if it's not possible to cover the entire range