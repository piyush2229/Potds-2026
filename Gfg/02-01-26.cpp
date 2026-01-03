class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};
/*
EXPLANATION (Sort 0, 1, 2s - Dutch National Flag Algorithm):

This algorithm sorts an array containing only 0s, 1s, and 2s in-place in a single pass.

HOW IT WORKS:
- We maintain THREE pointers: low, mid, and high
- low: boundary where 0s should be placed
- mid: current element being checked
- high: boundary where 2s should be placed

STEPS:
1. If arr[mid] == 0: Swap with low, move both low and mid forward
2. If arr[mid] == 1: Just move mid forward (it's in correct position)
3. If arr[mid] == 2: Swap with high, move high backward (don't move mid, need to check swapped element)

EXAMPLE: [0, 1, 2, 0, 1, 2]
Step 1: [0, 1, 2, 0, 1, 2] - arr[0]=0, swap with low=0, low++, mid++
Step 2: [0, 1, 2, 0, 1, 2] - arr[1]=1, just mid++
Step 3: [0, 1, 2, 0, 1, 2] - arr[2]=2, swap with high, high--
... and so on until sorted: [0, 0, 1, 1, 2, 2]

TIME COMPLEXITY: O(n) - Single pass through array
SPACE COMPLEXITY: O(1) - Only uses constant extra space
*/