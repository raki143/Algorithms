/* Prime Sum
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

*/

vector<int> Solution::primesum(int A) {
    
    vector<int> sol;
    vector<bool> isPrime(A+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int p=2;p*p <= A;p++){
        if(isPrime[p] == true){
            for(int i=2*p;i<=A;i+=p){
                isPrime[i] = false;
            }
        }
    }
    
    for(int i=0;i<A;i++){
        if(isPrime[i] && isPrime[A-i]){
            sol.push_back(i);
            sol.push_back(A-i);
            return sol;
        }
    }
    
    return sol;
}
