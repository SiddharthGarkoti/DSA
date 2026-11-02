class Solution {
public:
    bool isValid(string s) {
        if(s[0]=='}' || s[0]==']' || s[0]==')') return false;
        stack <int> hold;
        for(char sh: s){
            if(hold.empty() && (sh=='}' || sh==']' || sh==')')) return false;
            if(sh==']'){
                if(hold.top()=='['){
                    hold.pop();
                    continue;
                }
                else return false;
            }
            else if(sh=='}'){
                if(hold.top()=='{'){
                    hold.pop();
                    continue;
                }
                else return false;
            }
            else if(sh==')'){
                if(hold.top()=='('){
                    hold.pop();
                    continue;
                }
                else return false;
            }
            hold.push(sh);
        }
        if(!hold.empty()) return false;
        return true;
    }
};