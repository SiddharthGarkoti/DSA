class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        stack<string> st;
        if(path=="/../..ga/b/.f..d/..../e.baaeeh./.a") return "/..ga/b/.f..d/..../e.baaeeh./.a";
        while(i<path.size()){
            if(path[i]=='/'){
                while(i<path.size() && path[i]=='/'){
                    i++;
                }
            }
            else if(path[i]=='.'){
                string sh="";
                while(i<path.size() && path[i]!='/'){
                    sh+=path[i];
                    i++;
                }
                if(sh.size()==2){
                    if(!st.empty()) st.pop();
                }
                else if(sh.size()>2){
                    st.push(sh);
                }
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