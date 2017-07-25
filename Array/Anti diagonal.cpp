// Anti diagonal
/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]

Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector< vector<int> > result;
    vector<int> temp;
    
    int n = A.size();
    
    if(n == 0){
        return result;
    }
    
    for(int d=0;d <= 2*(n-1);d++){
        for(int i=0;i<=d;i++){
            if(i<n && d-i < n){
                temp.push_back(A[i][d-i]);
            }
        }
        result.push_back(temp);
        temp.clear();
    }
    return result;
}
