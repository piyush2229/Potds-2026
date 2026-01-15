class Solution {
public:
    int longest(vector<int>&a){
        sort(a.begin(),a.end());
        int best=1;
        int curr=1;
        for(int i=1;i<a.size();i++){
            if(a[i]==(a[i-1]+1))curr++;
            else curr=1;
            best=max(best,curr);
        }
        return best+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {
        int h=longest(vbars);
        int v=longest(hbars);
        int side=min(h,v);
        return side*side;
    }
};
// Find the longest consecutive segment between horizontal and vertical bars
// The maximum square hole area is determined by the smaller of the two longest segments
// Return the area as side*side