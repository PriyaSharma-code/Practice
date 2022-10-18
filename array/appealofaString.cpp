//2262. Total Appeal of A String

/*The appeal of a string is the number of distinct characters found in the string.

For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
Given a string s, return the total appeal of all of its substrings.

A substring is a contiguous sequence of characters within a string.*/

class Solution {
public:
    long long appealSum(string s) {
        long long prev[26]={}, n= s.size(),res=0;
        for(int i=0;i<n;i++){
            res += (i + 1 - prev[s[i]-'a'])*(n - i);
            prev[s[i] - 'a'] = i+1;
        }
        return res;
    }
};