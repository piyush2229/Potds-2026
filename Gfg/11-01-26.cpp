class Solution {
public:
    string minWindow(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        int i = 0;
        while (i < n1) {
            int j = 0;

            // Step 1: match s2 forward
            while (i < n1) {
                if (s1[i] == s2[j]) j++;
                if (j == n2) break;
                i++;
            }

            if (j < n2) break; // no more subsequence possible

            // Step 2: shrink window backward
            int end = i;
            j = n2 - 1;
            while (i >= 0) {
                if (s1[i] == s2[j]) j--;
                if (j < 0) break;
                i--;
            }

            // Update answer
            int len = end - i + 1;
            if (len < minLen) {
                minLen = len;
                start = i;
            }

            i = i + 1; // move forward for next window
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};

// use two pointers to find minimum window subsequence
// first pointer expands the window to include all characters of s2
// second pointer shrinks the window from the left to find the minimum length
