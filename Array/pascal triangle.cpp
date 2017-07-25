// pascal triangle 
/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int> > pascalTriangle;
    
    for(int line=1;line<=A;line++){
        
        vector<int> row;
        int c = 1;
        
        for(int i=1;i<=line;i++){
            row.push_back(c);
            c = c * (line - i)/i;
        }
        pascalTriangle.push_back(row);
    }
    return pascalTriangle;
}
