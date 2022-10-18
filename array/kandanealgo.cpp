//Kadane's Algorithm

/*Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one 
number) which has the maximum sum and return its sum.*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum = arr[0];
       long long maxE = arr[0];
       for(int i = 1; i< n; i++){
           maxE = max(arr[i],(int)maxE+arr[i]);
           sum = max(sum, maxE);
       }
       return sum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
  
  