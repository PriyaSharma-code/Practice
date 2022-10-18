/*Chef has 33 numbers PP, QQ and RR. Chef wants to find the number of triples (A, B, C)(A,B,C) such that:

(A \mid B) = P,(A∣B)=P, (B \mid C) = Q(B∣C)=Q and (C \mid A) = R(C∣A)=R (Here, \mid∣ denotes the bitwise OR operation)
0 \le A, B, C \lt 2^{20}0≤A,B,C<2 
20*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long p,q,r,ans = 1;
	    cin>>p>>q>>r;
	    for(int i=0;i<20;i++){
	        int cnt = ((p&(1<<i))>0);
	        cnt +=((q&(1<<i))>0);
	        cnt +=((r&(1<<i))>0);
	        if(cnt ==1){
	            ans = 0;
	        }
	        else{
	            if(cnt==3){
	                ans*=4;
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

/*There are a few cases here:

If all 33 are zero, then this bit must be zero in all of A, B, CA,B,C so there is only one option.
If exactly one of them is 11, such a case can never happen so the answer is immediately zero (for example,
 if A\vee B = 1A∨B=1, then either AA or BB must be 11 at this bit, and so at least one of A\vee C, B\vee 
 CA∨C,B∨C must be 11).
If exactly two of them are 11, there is exactly one option (if A\vee B = 0A∨B=0, then both AA and BB must 
be 00 and so C = 1C=1 is the only option, and so on).
If all three are 11, there are 44 possible options:
One way is for all three of A, B, CA,B,C to have a 11 at this bit
Otherwise, we can also choose exactly two of them to have a 11 at this bit. There are 33 ways to choose a pair.
Adding up the above options, we have 44 valid possibilities.*/