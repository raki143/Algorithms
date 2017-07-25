// Repeat an missing number array
/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int act_sum = 0;
    long long int exp_sum = 0;
    long long int act_prod = 0;
    long long int exp_prod = 0;
    long long int diff_sum = 0;
    long long int diff_prod = 0;
    long long int delta = 0;
    long long int i;
    
    for( i=0;i<A.size();i++){
        act_sum = act_sum + (long long int)A[i];
        act_prod = act_prod + (long long int) A[i]*A[i];
    }
    
    exp_sum = (long long int)(A.size()) * (A.size()+1)/2;
    exp_prod = (long long int)(A.size())*(A.size()+1)*(2*A.size()+1)/6;
    
    diff_sum = exp_sum - act_sum;
    diff_prod = exp_prod - act_prod;
    
    delta = diff_prod/diff_sum;
    
    long long int missingNumber = (delta + diff_sum)/2;
    long long int repeatedNumber = missingNumber - diff_sum;
    
    vector<int> result;
    result.push_back((int) repeatedNumber);
    result.push_back((int) missingNumber);
    
    return result;
    // long long int act_sum = 0;
    // long long int act_sum_sq = 0;
    // long long int exp_sum;
    // long long int exp_sum_sq;
    // long long int i = 0;
    
    // for(i = 0; i < A.size(); i++){
    //     act_sum = act_sum + (long long int)A[i];
    //     act_sum_sq = act_sum_sq + (long long int)A[i]*A[i];
    // }
    
    // exp_sum = (long long int)(A.size())*(A.size()+1)/2;
    // exp_sum_sq = (long long int)(A.size())*(A.size()+1)*(2*A.size()+1)/6;
    
    // long long int diff_sum_sq = exp_sum_sq - act_sum_sq;
    // long long int diff_sum = exp_sum - act_sum;
    
    // long long int tog = diff_sum_sq/diff_sum;
    
    // long long int mis = (tog + diff_sum)/2;
    // long long int rep = mis - diff_sum;
    
    // vector<int> sol;
    // sol.push_back((int)rep);
    // sol.push_back((int)mis);

    // return sol;
}
