/*56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping 
intervals, and return an array of the non-overlapping intervals that cover all the intervals 
in the input.*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0){
            return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        for(int i=0;i<n;i++){
            if( i == n-1){
                output.push_back(intervals[i]);
            }
            else{
                if(intervals[i][1]>= intervals[i+1][0]){
                    intervals[i+1][0] = intervals[i][0];
                    intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
                }
                else{
                    output.push_back(intervals[i]);
                }
            }
        }
        return output;
    }
};