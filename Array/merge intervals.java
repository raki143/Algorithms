// merge interval
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {

    ArrayList<Interval> result = new ArrayList<Interval>();
    intervals.add(newInterval);
    
    Collections.sort(intervals, new Comparator<Interval>(){
        
        public int compare(Interval i1, Interval i2){
            
            if(i1.start != i2.start){
                return i1.start - i2.start;
            }else{
                return i1.end - i2.end;
            }
        }
    });
    
    Interval pre = intervals.get(0);
    
    for(int i=1;i < intervals.size();i++){
       
       Interval current = intervals.get(i);
       
       if(current.start > pre.end){
           result.add(pre);
           pre = current;
       }else{
           Interval merged = new Interval(pre.start, Math.max(pre.end,current.end));
           pre = merged;
       }
        
    }
    
    result.add(pre);
    return result;
    }
}
