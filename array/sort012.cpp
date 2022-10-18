//Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int A[], int n)
    {
        // coode here 
         int B[3] {0};
        int i=0;
        while(i<n){
            if(A[i] == 0)
                B[0]++;
            else if(A[i] == 1)
                B[1]++;
            else
                B[2]++;
                
            i++;
                
        }
        int j =0;
        while(B[0]--){
            A[j++] =0;
        }
        
        while(B[1]--){
            A[j++] =1;
        }
        
        while(B[2]--){
            A[j++] =2;
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends