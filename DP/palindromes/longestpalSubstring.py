#5. Longest Palindromic Substring

##Given a string s, return the number of palindromic substrings in it.

class Solution:
    def countSubstrings(self, S: str) -> int:
        def manachers(S):
            A = '@#' + '#'.join(S) + '#$'
            Z = [0] * len(A)
            center = right = 0
            for i in range(1, len(A) - 1):
                if i < right:
                    Z[i] = min(right - i, Z[2 * center - i])
                while A[i + Z[i] + 1] == A[i - Z[i] - 1]:  #check if first and last are smae
                    Z[i] += 1  #+1 if they are
                if i + Z[i] > right:
                    center, right = i, i + Z[i]
            return Z  #return no of substrings

        return sum((v+1)/2 for v in manachers(S))

class Solution {
public:
    string longestPalindrome(string s) {
if(s.size()==0) return "";
        int i = 0, j = 0;
        int n = s.size();
        //initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
        vector<vector<bool>> P(n, vector<bool> (n, false));
        for(int x = 0;x<n;x++){
            P[x][x]=true;
            if(x==n-1) break;
            P[x][x+1] = (s[x]==s[x+1]);
        }
        //dp 
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                P[i][j] = (P[i+1][j-1] && s[i]==s[j]);     
            }
        }
        //get maxstr result
        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(P[i][j]==true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    
    }
    
};