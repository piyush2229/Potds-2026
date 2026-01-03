class Solution {
public:
    // Function to add 1 to a number represented as an array of digits
    // Example: [1,2,3] becomes [1,2,4], [9,9,9] becomes [1,0,0,0]
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the rightmost digit and move left
        for (int i = n - 1; i >= 0; i--) {
            // If digit is less than 9, simply increment it and return
            // No carry needed, we're done!
            if (digits[i] < 9) {
                digits[i]++; 
                return digits; 
            }
            // If digit is 9, set it to 0 (carry over to next position)
            digits[i] = 0;
        }
        
        // If we reach here, all digits were 9 (e.g., [9,9,9])
        // Insert 1 at the beginning for the extra digit (e.g., [1,0,0,0])
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Time Complexity: O(n) in the worst case when all digits are 9
// Space Complexity: O(1) if we don't count the space for the output array