class Solution {
public:
    vector<int>leftsmallest(vector<int>&height){
        stack<int>st;
        vector<int>left(height.size());
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(!st.empty())left[i]=st.top();
            else left[i]=-1;
            st.push(i);
        }
        return left;
    }
    vector<int>rightsmallest(vector<int>&height){
        stack<int>st;
        vector<int>right(height.size());
        for(int i=height.size()-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(!st.empty())right[i]=st.top();
            else right[i]=height.size();
            st.push(i);
        }
        return right;
    }
    int largestrectangle(vector<int>&height){
        int n=height.size();
        vector<int>left=leftsmallest(height);
        vector<int>right=rightsmallest(height);
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            maxarea=max(maxarea,width*height[i]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int n=matrix.size();
        int ans=0;
        int m=matrix[0].size();
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            ans=max(ans,largestrectangle(height));
        }
        return ans;
    }
};

// use dynamic programming to calculate largest rectangle of 1's in a binary matrix
// for each row, treat it as the base of a histogram where height of each bar is the number of consecutive 1's above it
// calculate largest rectangle in histogram for each row and update maximum area found
// return maximum area found after processing all rows