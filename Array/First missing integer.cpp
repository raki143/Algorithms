// First missing integer
/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

// Put each number in its right place.

// For example:

// When we find 5, then swap it with A[4].

// At last, the first place where its number is not right, return the place + 1.

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    
     for(int i = 0; i < n; ++ i){
         
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]){
                swap(A[i], A[A[i] - 1]);
                
            }
         
     }
        cout<<"\n2nd loop"<<endl;
        for(int i = 0; i < n; ++ i){
            cout<<A[i]<<" ";
            if(A[i] != i + 1)
                return i + 1;
            
        }
        
        return n + 1;
}
