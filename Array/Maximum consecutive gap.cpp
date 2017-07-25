// Maximum consecutive gap
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
*/

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 2){
        return 0;
    }
    
    
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    
    vector<int> bucketMaxima(A.size()-1,INT_MIN);
    vector<int> bucketMinima(A.size()-1,INT_MAX);
    
    for(int i=0;i<A.size();i++){
        maximum = max(maximum,A[i]);
        minimum = min(minimum,A[i]);
    }
    
    // bucket width
    float delta = (float)(maximum - minimum)/((float)(A.size()-1));
   // cout<<"delta is "<<delta;
    
    // populate bucket maxima and minima
    for(int i=0; i < A.size();i++){
        if(A[i]==maximum || A[i] == minimum){
            continue;
        }
        
        int bucketIndex = (int) floor((A[i] - minimum)/delta);
        
        bucketMaxima[bucketIndex] = bucketMaxima[bucketIndex] == INT_MIN ? A[i] : max(bucketMaxima[bucketIndex],A[i]);
        bucketMinima[bucketIndex] = bucketMinima[bucketIndex] == INT_MAX ? A[i] : min(bucketMinima[bucketIndex],A[i]);
        
    }
    
    int prev = minimum;
    int maxGap = 0;
    
    for(int i=0; i < A.size()-1;i++){
        
        if(bucketMinima[i] == INT_MAX){
            continue;
        }
        
        maxGap = max(maxGap, bucketMinima[i]-prev);
		prev = bucketMaxima[i];
    }
    
    maxGap = max(maxGap, maximum - prev);
	
	return maxGap;
}
