class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char>st;
        for(char c:s){
            if(c!=')'){
                st.push(c);
            }
            else{
                int cnt=0;
                while(!st.empty() && st.top()!='('){
                    char el=st.top();
                    if(el=='+' || el=='-' || el=='/' || el=='*')cnt++;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                if(cnt==0) return true;
            }
        }
        return false;
    }
};


// Use a stack to track characters in the expression
// When encountering a closing parenthesis, check for operators inside the parentheses
// If no operators are found, the parentheses are redundant
// Return true if redundancy is detected, otherwise return false
