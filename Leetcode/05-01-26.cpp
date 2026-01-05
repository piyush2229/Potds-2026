class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minval=INT_MAX;
        long long sum=0;
        int n=matrix.size();
        int negcount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    negcount++;
                }
                int absval=abs(matrix[i][j]);
                minval=min(minval,absval);
                sum+=absval;
            }
        }
        if(negcount%2==0){
            return sum;
        }
        return sum-2*minval;
    }
};

//check the parity of negative no
//if even return sum of absolute values
//if odd return sum of absolute values - 2*minimum absolute value