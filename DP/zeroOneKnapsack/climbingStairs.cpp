//70. Climbing Stairs

//You are climbing a staircase. It takes n steps to reach the top.

//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
       int t[n+1];
        for(int i=0;i<=n;i++) t[i]=0;
        t[1]=1;
        if(n>=2) t[2]=2;
        for(int i=3;i<=n;i++){
             t[i] = t[i-1]+t[i-2];    
        }
        return t[n];
    }
};