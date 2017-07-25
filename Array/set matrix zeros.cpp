// set matrix zeros
/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int row = A.size();
    int column = A[0].size();
    
    bool fr = false;
    bool fc = false;
    
    for(int i=0;i < row;i++){
        for(int j=0;j < column;j++){
            
            if(A[i][j] == 0){
                
                A[i][0] = 0;
                A[0][j] = 0;
                if(i == 0){
                    fr = true;
                }
                
                if(j == 0){
                    fc = true;
                }
                
            }
        }
    }
    
    for(int i=1;i < row;i++){
        
        for(int j=1;j < column;j++){
            
            if(A[i][0] == 0 || A[0][j] == 0){
                A[i][j] = 0;
            }
        }
        
    }
    
    if(fr){
        
        for(int j=0;j < column;j++){
            A[0][j] = 0;
        }
    }
    
    if(fc){
        for(int i=0;i < row;i++){
            A[i][0] = 0;
        }
    }
}
