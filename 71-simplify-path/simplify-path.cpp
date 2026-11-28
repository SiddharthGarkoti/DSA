class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        stack<string> st;
 
        while(i<path.size()){
            if(path[i]=='/'){
                while(i<path.size() && path[i]=='/'){
                    i++;
                }
            }
            else if(path[i]=='.'){
                string sh="";
                int count=0;
                while(i<path.size() && path[i]!='/'){
                    if(path[i]=='.') count++;
                    sh+=path[i];
                    i++;
                }
                if(count==2 && sh.size()==2){
                    if(!st.empty()) st.pop();
                }
                else if(count==1 && sh.size()==1){
                    continue;
                }
                else st.push(sh);
            }
            else{
                string sh="";
                while(i<path.size() && path[i]!='/'){
                    sh+=path[i];
                    i++;
                }
                st.push(sh);
            }
        }
        string res="";
        stack<string> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            res+='/';
            res+=temp.top();
            temp.pop();
        }
        if(res.empty()) return "/";
        return res;
    }
};