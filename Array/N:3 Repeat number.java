// N/3 Repeat number
/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 
*/

public class Solution {
	// DO NOT MODIFY THE LIST
	public int repeatedNumber(final List<Integer> a) {
	    
	    int c1 = 0;
	    int c2 = 0;
	    Integer n1 = null;
	    Integer n2 = null;
	    
	    for(int i : a){
	        if(n1 != null && i == n1.intValue()){
	            c1++;
	        }else if(n2 != null && i == n2.intValue()){
	            c2++;
	        }else if(c1 == 0){
	            c1 = 1;
	            n1 = i;
	        }else if(c2 == 0){
	            c2 = 1;
	            n2 = i;
	        }else{
	            c1--;
	            c2--;
	        }
	    }
	
//	System.out.println(n1+" "+n2);    
	    c1 = 0;
	    c2 = 0;
	    
	    for(int i : a){
	        if(i == n1.intValue()){
	            c1++;
	        }else if(i == n2.intValue()){
	            c2++;
	        }
	    }
//	  System.out.println(c1+" "+c2);    
	  
	    if(c1 > Math.ceil(a.size() / 3)){
	        return n1;
	    }else if(c2 > Math.ceil(a.size() / 3)){
	        return n2;
	    }else{
	        return -1;
	    }
	}
}
