
/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 
*/

bool Solution::isPower(int A) {
    
    int x =2;
    int i;
    if(A==1){
        return true;
    }
    
    for(i = 2; i < 33 && x <= pow(2, 16); i++){
            if(pow(x, i) == A)
                return true;
            if(pow(x, i) >= pow(2, 32)){
                i = 1;
                x++;
            }
    }
    return false;
}
