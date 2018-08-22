#include "./../../../Include/Common.h"

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


bool comparator(Interval a, Interval b){
    return a.start < b.start ? true : false;
}

// Add any helper functions(if needed) above.
vector<Interval> merge_intervals(vector<Interval> intervals_list)
{
    vector<Interval> output; 
    int n = intervals_list.size();

    if(n == 0)
        return output;

    // Debugging code
    for(int i = 0; i < n; i++){
        cout << " [" << intervals_list[i].start << "," << intervals_list[i].end << "] ";
    }

    // Sort by starting times
    sort (intervals_list.begin(), intervals_list.end(), comparator); 

    output.push_back(intervals_list[0]);
    int index = 0;

    for(int i = 1; i < n; i++){
        if(intervals_list[i].start > output[index].end) {
            output.push_back(intervals_list[i]);
            index++;
        } else {
            if(output[index].end < intervals_list[i].end){
                output[index].end = intervals_list[i].end;
            }
        }
    }
    return output;    
}