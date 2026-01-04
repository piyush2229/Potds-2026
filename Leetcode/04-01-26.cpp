class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i:nums){
            int sum=0;
            int cnt=0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    cnt++;
                    sum+=j;
                    if(j!=i/j){
                        cnt++;
                        sum+=i/j;
                    }
                }
                if(cnt>4)break;
            }
            if(cnt==4)ans+=sum;
        }
        return ans;
    }
};

// Time Complexity: O(N * sqrt(M)) where N is the number of elements in nums and M is the maximum element in nums
// Space Complexity: O(1)
//run the loop till sqrt of the number to find divisors
// for each divisor found, increment the count and add both divisors to the sum
// then check if the count of divisors is 4, if yes add the sum of divisors to the answer