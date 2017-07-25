// Max Distance
/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
*/

int maxValue(int x,int y){
    return x>y ? x : y;
}

int minValue(int x, int y){
    return x<y ? x : y;
}

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int arraySize = A.size();
    int maxDiff,i,j;
    vector<int> lmin(arraySize);
    vector<int> rmax(arraySize);
    
    lmin[0] = A[0];
    for(int i=1;i<arraySize;i++){
        lmin[i] = minValue(A[i],lmin[i-1]);
    }
    
    rmax[arraySize-1] = A[arraySize-1];
    for(int j=arraySize-2;j>=0;j--){
        rmax[j] = maxValue(A[j],rmax[j+1]);
    }
    
    maxDiff = -1;
    i=0;
    j=0;
    
    while(i < arraySize && j < arraySize){
        if(lmin[i] <= rmax[j]){
            maxDiff = maxValue(maxDiff,j-i);
            j++;
        }else{
            i++;
        }
    }
    return maxDiff;
}
