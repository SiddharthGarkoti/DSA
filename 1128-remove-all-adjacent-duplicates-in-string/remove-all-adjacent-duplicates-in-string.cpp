class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(int i=s.size()-1;i>=0;i--){
            if(!st.empty() && st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};