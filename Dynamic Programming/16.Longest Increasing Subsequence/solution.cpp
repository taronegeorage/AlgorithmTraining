// 300.
class Solution {
public:
    public:
    // 8ms
    int lengthOfLIS(vector<int>& nums) {
        int* tail = new int[nums.size()];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int l = 0, m = ans;
            while(l != m){
                int mid = (l+m)/2;
                if(tail[mid] < nums[i])
                    l = mid + 1;
                else
                    m = mid;
            }
            tail[l] = nums[i];
            if(l == ans) ans += 1;
        }
        return ans;
    }
    // 60 ms
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;        
        f_ = vector<int>(n, 0);        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, LIS(nums, i));
        return ans;
    }
private:
    vector<int> f_;
    // length of LIS ends with nums[r]
    int LIS(const vector<int>& nums, int r) {
        if (r == 0) return 1;
        if (f_[r] > 0) return f_[r];
        int ans = 1;
        for(int i = 0; i < r; ++i)
            if (nums[r] > nums[i])
                ans = max(ans, LIS(nums, i) + 1);
        f_[r] = ans;
        return f_[r];
    }
    // 40ms
    int lengthOfLIS1(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> ans(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j <= i; j++){
                if(nums[i] > nums[j])
                    ans[i] = max(ans[i], ans[j] + 1);
            }
        
        return *std::max_element(std::begin(ans), std::end(ans));
    }

};
