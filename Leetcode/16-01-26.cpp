class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hfences, vector<int>& vfences) {
        hfences.push_back(1);
        hfences.push_back(m);
        vfences.push_back(1);
        vfences.push_back(n);
        sort(hfences.begin(),hfences.end());
        sort(vfences.begin(),vfences.end());
        unordered_set<int>ss;
        for(int i=0;i<hfences.size();i++){
            for(int j=i+1;j<hfences.size();j++){
                ss.insert(hfences[j]-hfences[i]);
            }
        }
        int len=-1;
        for(int i=0;i<vfences.size();i++){
            for(int j=i+1;j<vfences.size();j++){
                if(ss.count(vfences[j]-vfences[i])){
                    len=max(len,vfences[j]-vfences[i]);
                }
            }
        }
        if(len==-1) return -1;
        return (len * 1LL * len) % 1000000007;

    }
};

// Add boundary fences at positions 1 and m for horizontal, 1 and n for vertical
// Sort the fence positions
// Use a set to store all possible lengths between horizontal fences
// Iterate through vertical fences to find the maximum square side length that matches a horizontal length
// If no such length exists, return -1