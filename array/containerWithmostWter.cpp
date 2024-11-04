//11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while(left<right){
            int currentArea = min(height[left],height[right])*(right-left);
            if(currentArea> maxArea){
                maxArea = currentArea;
            }
            if(height[left]< height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};