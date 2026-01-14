class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int caught=0;
        vector<int>police,thief;
        for(int i=0;i<n;i++){
            if(arr[i]=='T')thief.push_back(i);
            else police.push_back(i);
        }
        int p=0,t=0;
        while(p<police.size() && t<thief.size()){
            if(abs(police[p]-thief[t])<=k){
                caught++;
                p++;
                t++;
            }
            else if(thief[t]<police[p])t++;
            else p++;
        }
        return caught;
    }
};

// Use two pointers to traverse police and thief positions
// If the current police and thief can be matched (within distance k), increment caught count and both pointers
// If the thief is before the police, move thief pointer forward
// If the police is before the thief, move police pointer forward
// Return total caught count