//2390. Removing Stars From a String

//using 2 pointers
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(auto c: s){
            if (c == '*') j--;
            else s[j++] = c;
        }
        return s.substr(0, j);
    }
};


//using stack
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto c: s){
            if(c == '*'){
                st.pop();
            }else st.push(c);
        }
        int i = st.size()-1;
        string ans(st.size(), '*');
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};