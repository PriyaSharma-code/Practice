/*509. Fibonacci Number
Given n, calculate F(n).*/

class Solution {
public:
    int fib(int N) {
        if(N < 2) 
            return N;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

class Solution:
    def fib(self, N: int) -> int:
        golden_ratio = (1 + 5 ** 0.5) / 2
    return int((golden_ratio ** N + 1) / 5 ** 0.5)