class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=max(bottomLeft[i][0],bottomLeft[j][0]);
                int bottom=max(bottomLeft[i][1],bottomLeft[j][1]);
                int right=min(topRight[i][0],topRight[j][0]);
                int top=min(topRight[i][1],topRight[j][1]);
                if(left<right && top>bottom){
                    int width=right-left;
                    int height=top-bottom;
                    int side=min(height,width);
                    ans=max(ans,1LL*side*side);
                }
            }
        }
        return ans;
    }
};

// Check all pairs of rectangles to find overlapping area
// Calculate the overlapping rectangle's dimensions
// Determine the largest square that can fit in the overlapping area
// Update the maximum square area found and return it