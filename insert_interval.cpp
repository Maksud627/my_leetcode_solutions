/*
How do we know if a given interval is overlapping with an interval?

Lets say I have this as list of intervals
[[1, 3], [6, 9]]   
interval to check: [2, 5]
now we have to check if [2, 5] overlaps with any of the intervals or not?

follow this algorithm:
[a, b] and [c, d] will overlap with each other if and only if,
a <= d && c <= b
- overlapping cases (in each case a will be smaller than d & b will be greater than c)
    a--------b            a-------b          a-----b        a------------b                
c----------------d   c---------d                c------d       c-----d


*/

// 57. Insert Interval: https://leetcode.com/problems/insert-interval/description/
// array, medium


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++){
            // if new interval is at front
            if(newEnd < intervals[i][0]){
                ans.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }

            // if new interval is at end
            else if(intervals[i][1] < newStart){
                ans.push_back(intervals[i]);
            }

            // if new interval is overlapping or inbetween
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        // if overlapping case is with 
        // the last element of the intervals list
        ans.push_back(newInterval);
        return ans;
    }
};

// TC -> O(n) :: As iterating, takes O(n) and pushing to vector also takes O(n)
// SC -> O(n) :: storing answer in another vector of n size