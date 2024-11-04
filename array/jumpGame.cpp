//55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fartherest = 0;
        for(int i=0;i<nums.size();i++){
            if(i>fartherest){
                return false;
            }
            fartherest = max(fartherest, i + nums[i]);
        }
        if(fartherest>=nums.size()-1){
            return true;
        }
        return false;

    }
};