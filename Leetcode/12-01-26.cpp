class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int seconds=0;
        for(int i=1;i<n;i++){
            int x1=points[i-1][0];
            int y1=points[i-1][1];
            int x2=points[i][0];
            int y2=points[i][1];
            seconds+=max(abs(x2-x1),abs(y2-y1));
        }
        return seconds;
    }
};
// calculate time between consecutive points
// time is determined by the maximum of horizontal and vertical distances
// sum these times to get the total time to visit all points
// return the total time