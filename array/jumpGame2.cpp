//45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int fartherest = 0;
        int end=0;
        int jumps=0;
        for(int i=0;i<nums.size();i++){
            fartherest= max(fartherest, i+nums[i]);
            if(i == end){
                end = fartherest;
                jumps++;
                if(end == nums.size()-1){
                    break;
                }
            }
        }
        return jumps;
    }
};