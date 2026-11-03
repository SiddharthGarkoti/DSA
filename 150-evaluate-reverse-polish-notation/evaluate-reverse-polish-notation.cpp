class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> hold;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a=hold.top();
                hold.pop();
                int b=hold.top();
                hold.pop();
                hold.push(a+b);
            }
            else if(tokens[i]=="-"){
                int a=hold.top();
                hold.pop();
                int b=hold.top();
                hold.pop();
                hold.push(b-a);
            }
            else if(tokens[i]=="*"){
                int a=hold.top();
                hold.pop();
                int b=hold.top();
                hold.pop();
                hold.push(a*b);
            }
            else if(tokens[i]=="/"){
                int a=hold.top();
                hold.pop();
                int b=hold.top();
                hold.pop();
                hold.push(b/a);
            }
            else{
                hold.push(stoi(tokens[i]));
            }
        }
        return hold.top();
    }
};