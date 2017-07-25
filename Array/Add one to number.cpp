// Add one to number

/*

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int carry = 1;
    int sum;
    int len = A.size();
    vector<int> result;
    
    for(int i = len - 1; i >=0; i--){
        sum = carry + A[i];
        result.push_back(sum%10);
        if(sum >= 10){
            carry = 1;
        }else{
            carry = 0;
        }
    }
    result.push_back(carry);
    
    int s = result.size();
    vector<int> ans;
    int i = s - 1;
    
    while(i >= 0 && result[i] == 0){
        i--;
    }
    
    while(i>=0){
        ans.push_back(result[i]);
        i--;
    }
    return ans;
}
