class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double minY = 1e9, maxY = -1e9;

        // Step 1: compute total area and bounds
        for (auto &sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            totalArea += (double)l * l;
            minY = min(minY, (double)y);
            maxY = max(maxY, (double)(y + l));
        }

        double target = totalArea / 2.0;
        double lo = minY, hi = maxY;

        // Step 2: binary search
        for (int iter = 0; iter < 100; iter++) { // enough for precision
            double mid = (lo + hi) / 2.0;
            double below = 0.0;

            // Step 3: compute area below mid
            for (auto &sq : squares) {
                int y = sq[1], l = sq[2];
                if (mid <= y) continue;
                else if (mid >= y + l) below += (double)l * l;
                else below += (mid - y) * l;
            }

            if (below < target) lo = mid;
            else hi = mid;
        }

        return (lo + hi) / 2.0;
    }
};


// Calculate total area of squares and vertical bounds
// Use binary search to find the horizontal line that divides the area in half
// For each mid value in binary search, calculate area below that line
// Adjust search bounds based on whether area below mid is less than or greater than half the total area
// Return the mid value when the search converges
// Time Complexity: O(N log M) where N is number of squares and M is the range of y-coordinates