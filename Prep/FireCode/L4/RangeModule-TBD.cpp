#include "./../../../Include/Common.h"

/*
    A Range Module is a module that tracks ranges of numbers. 
    Input: [ [1,3], [7,10] ] & [2,6], 
    Output: [ [1,6], [7,10] ]

    Your task is to write a method - insert_range that takes in a vector of sorted, 
    non-overlapping integer Interval s (aka ranges) and a new Interval - 
    insert, and returns a vector of sorted Interval s where insert has been added to the vector 
    in the correct spot and the required overlapping ranges have been merged. 
*/


class Interval {
    public:
        int start;
        int end;
        Interval(){}
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
    };

Interval merge_intervals(Interval iv1, Interval iv2){
    Interval merged;
    merged.start = min(iv1.start, iv2.start);
    merged.end = max(iv1.end, iv2.end);
    return merged;
}
// Add any helper functions(if needed) above.
vector<Interval> insert_range(vector<Interval> intervals_list, Interval insert) {
    Interval prev, next = intervals_list[0];
    auto it = intervals_list.begin();

    // Insert at the start if needed
    if(insert.end < next.start){
        intervals_list.insert(it, insert);
        return intervals_list;
    } else if(insert.start < next.start && insert.end > next.start) {
        Interval merged = merge_intervals(insert, next);
        intervals_list[0] = merged;
    }

    for(int i = 1; i < intervals_list.size(); i++){
        prev = intervals_list[i - 1];
        next = intervals_list[i];
        if(insert.start >= prev.start && insert.start <= prev.end){
            // ---___---
            if(insert.end >= next.start && insert.end <= next.end){
                Interval merged = merge_intervals(prev, next);
                intervals_list[i - 1] = merged;                
                intervals_list.erase(intervals_list.begin() + i);
                continue;
            // ---___  ---
            } else if(insert.end < next.start ){
                Interval merged = merge_intervals(prev, insert);
                intervals_list[i - 1] = merged;
                break;
            }
        // --- ___---
        } else if(insert.start >= next.start && insert.start <= next.end){
            Interval merged = merge_intervals(next, insert);
            intervals_list[i] = merged;
            break;
            // --- ___ ---
        } else if(insert.start > prev.start && insert.end < next.start) {
            intervals_list.insert(it + i - 1, insert);
            break;
        }
    }
    return intervals_list;
}