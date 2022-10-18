//Find position of set bit

// A utility function to check whether n is a power of 2 or not.
// See http://goo.gl/17Arj
int isPowerOfTwo(unsigned n)
{
    return n && (!(n & (n - 1)));
}

// Returns position of the only set bit in 'n'
int findPosition(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;

    unsigned i = 1, pos = 1;

    // Iterate through bits of n till we find a set bit
    // i&n will be non-zero only when 'i' and 'n' have a set bit
    // at same position
    while (!(i & n)) {
        // Unset current bit and set the next bit in 'i'
        i = i << 1;

        // increment position
        ++pos;
    }

    return pos;
}

/*The idea is to start from the rightmost bit and one by one check value of every bit. 
Following is a detailed algorithm.
1) If number is power of two then and then only its binary representation contains only one '1'.
 That's why check whether the given number is a power of 2 or not. If given number is not a 
 power of 2, then print error message and exit.
2) Initialize two variables; i = 1 (for looping) and pos = 1 (to find position of set bit)
3) Inside loop, do bitwise AND of i and number 'N'. If value of this operation is true, then 
"pos" bit is set, so break the loop and return position. Otherwise, increment "pos" by 1 and 
left shift i by 1 and repeat the procedure. */