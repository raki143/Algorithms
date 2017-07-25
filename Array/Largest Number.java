// Largest Number

/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

public class Solution {
	// DO NOT MODIFY THE LIST
	public String largestNumber(final List<Integer> a) {
	    
	    String[] arr = new String[a.size()];
	    
	    // form array string
	    for(int i=0;i < arr.length;i++){
	        arr[i] = String.valueOf(a.get(i));
	    }
	    
	    // sort Strings in descending order
	    Arrays.sort(arr,new Comparator<String>(){
	        public int compare(String a, String b){
	            return (b+a).compareTo(a+b);
	        }
	    });
	    
	    // form StringBuilder and append strings form array string
	    StringBuilder br = new StringBuilder();
	    for(String s:arr){
	        br.append(s);
	    }
	    // remove if 0 is at first character 
	    while(br.charAt(0) == '0' && br.length() > 1){
	        br.deleteCharAt(0);
	    }
	    // convert StringBuilder to string
	    return br.toString();
	}
}
