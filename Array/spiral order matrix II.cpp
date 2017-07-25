// spiral order matrix II 
/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
 [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ] 
 */

 vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> >result(A, vector<int>(A, 0));
    
    int val = 1;
        int top = 0;
        int down = A-1;
        int left = 0;
        int right = A-1;
        
        while(val <= A*A){
            
            for(int i = left; i <= right;i++){
                result[top][i] = val;
                val++;
            }
            top++;
            
            for(int i = top; i <= down; i++){
                result[i][right] = val;
                val++;
            }
            right--;
            
            for(int i = right; i >= left; i--){
                result[down][i] = val;
                val++;
            }
            down--;
            
            for(int i = down;i >= top;i--){
                result[i][left] = val;
                val++;
            }
            left++;
        }
        return result;
}
