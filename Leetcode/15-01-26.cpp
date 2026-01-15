class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>candies(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        int total=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
            total+=candies[i];
        }
        total+=candies[n-1];
        return total;
    }
};

// First pass: left to right, ensure each child has more candy than left neighbor if rating is higher
// Second pass: right to left, ensure each child has more candy than right neighbor if rating
// Use max to keep the higher candy count from both passes is higher
// Sum up all candies to get the total required