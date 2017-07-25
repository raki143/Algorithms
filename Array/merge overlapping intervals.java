// merge overlapping intervals
/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
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
    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {

        ArrayList<Interval> result = new ArrayList<Interval>();
        
        if(intervals == null || intervals.size() == 0){
            return result;
        }
        
        Collections.sort(intervals,new Comparator<Interval>(){
           public int compare(Interval i1, Interval i2){
               if(i1.start != i2.start){
                    return i1.start - i2.start;
                }else{
                    return i1.end - i2.end;
                }
           } 
            
        });
        
        Interval pre = intervals.get(0);
        for(int i = 1; i < intervals.size();i++){
            Interval current = intervals.get(i);
            if(current.start > pre.end){
                result.add(pre);
                pre = current;
            }else{
              Interval merged = new Interval(pre.start,Math.max(pre.end,current.end));
              pre = merged;
            }
        }
        result.add(pre);
        return result;
    }
}
