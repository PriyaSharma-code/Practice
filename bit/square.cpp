/*Given an integer n, calculate the square of a number without using *, / and pow(). */

 
int square(int num)
{
    // handle negative input
    if (num < 0)
        num = -num;
 
    // Initialize power of 2 and result
    int power = 0, result = 0;
    int temp = num;
 
    while (temp) {
        if (temp & 1) {
            // result=result+(num*(2^power))
            result += (num << power);
        }
        power++;
 
        // temp=temp/2
        temp = temp >> 1;
    }
 
    return result;
}