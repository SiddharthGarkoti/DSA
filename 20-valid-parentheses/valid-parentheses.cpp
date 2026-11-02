class Solution {
public:
    bool isValid(string s) {
        stack <char> hold;
        for(char sh: s){
            if(sh=='(') hold.push(')');
            else  if(sh=='{') hold.push('}');
            else if(sh=='[') hold.push(']');
            else{
                if(hold.empty() || sh!=hold.top()) return false;
                hold.pop();
            }
        }
        return hold.empty();
    }
};