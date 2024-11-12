//20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> bracketPairs= {
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> st;
        for(char c: s){
            if(bracketPairs.count(c)){
                char topelement = st.empty() ? '#' : st.top();
                st.pop();
                if(topelement!=bracketPairs[c]){
                    return false;
                }
            }
            else{ st.push(c);}
        }
        return st.empty();

    }
};