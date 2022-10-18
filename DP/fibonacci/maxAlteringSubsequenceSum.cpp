/*1911. Maximum Alternating Subsequence Sum

Given an array nums, return the maximum alternating sum of any subsequence of nums (after
 reindexing the elements of the subsequence).*/

 class Solution {
public:
    long long maxAlternatingSum(vector<int>& A) {
        long long even=A[0], odd = 0;
        for(int i=1;i<A.size();i++){
            odd = max(odd, even - A[i]);
            even = max(even, odd+ A[i]);
        }
        return max(even,odd);
    }
};