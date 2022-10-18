//1143. Longest Common Subsequence

//Given two strings text1 and text2, return the length of
// their longest common subsequence. If there is no common subsequence, return 0.

class Solution {
public:
  
    int longestCommonSubsequence(string a, string b) {
        short m[1001][1001] ={};
        for(auto i=0;i< a.size();i++){
            for(auto j=0;j<b.size();j++){
                m[i+1][j+1] = a[i]==b[j]? m[i][j] + 1: max(m[i+1][j] , m[i][j+1]);
            }
        }
        return m[a.size()][b.size()];
    }
};