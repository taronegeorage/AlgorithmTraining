// 674.
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len = 1;
        int max = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1])
                len += 1;
            else{
                if(len > max)
                    max = len;
                len = 1;
            }       
        }
        if(len > max)
            max = len;
        return max;
    }
};
