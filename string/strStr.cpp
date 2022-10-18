/*28. Implement strStr()

Given two strings needle and haystack, return the index of the first occurrence 
of needle in haystack, or -1 if needle is not part of haystack.*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(),m=0;
        if(n==NULL){
            return 0;
        }
        for(int i=0;i<haystack.size();i++){
            if(haystack.substr(i, needle.size())== needle) 
                return i;
        }
        return -1;
    }
};