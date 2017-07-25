/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/

int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long rev = 0;
    int max = 1<<31;
    while(A != 0){
        
        if(rev!=0 && max/rev < 10 && max/rev > -10){
            return 0;
        }
        
        rev = rev*10 + A%10;
        A = A/10;
    }
    return (int)rev;
}
