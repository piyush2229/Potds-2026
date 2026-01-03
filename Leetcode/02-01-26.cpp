class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int twon=nums.size();
        int n=twon/2;
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        for(auto it:mpp){
            if(it.second==n){
                return it.first;
            }
        }
        return 0;
    }
};

//first find the half of the array size
//then store the frequency of each element in a map
//then traverse the map to find the element with frequency equal to half of the array size