class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0; i < nums.size() && i < k; i++){
            que.push(nums[i]);
        }
        if(nums.size() > k){
            for(int i = k; i < nums.size(); i++){
                if(nums[i]>que.top()){
                    que.push(nums[i]);
                    que.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if(K > que.size())
            que.push(val);
        else if(val>=que.top()){
            que.push(val);
            que.pop();
        }
        return que.top();
    }
private:
    priority_queue<int, vector<int>, greater<int> > que;
    int K;
    // priority_queue<int> que;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


// 48ms 92.79%
// 19.6MB 35.50%
