class Solution {
public:
    int atmost(string &s, int k) {
        int count = 0;
        vector<int> freq(26, 0);
        int distinct = 0;
        int left = 0, n = s.size();

        for (int right = 0; right < n; right++) {
            if (freq[s[right] - 'a'] == 0) distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }

    int countSubstr(string &s, int k) {
        return atmost(s, k) - atmost(s, k - 1);
    }
};

// calculate number of substrings with exactly k distinct characters
// use sliding window approach
// for each right pointer, move left pointer to maintain at most k distinct characters
// count number of valid substrings ending at right pointer
// return difference between number of substrings with at most k distinct characters and at most k-1 distinct characters
