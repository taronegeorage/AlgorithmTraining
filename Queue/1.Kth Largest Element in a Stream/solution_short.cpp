class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : K(k) {
        for(auto e : nums) {
            pq.push(e);
            if(pq.size() > K) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int> > pq;
    int K;
    // priority_queue<int> que;
};

// 40ms 99.46%
// 19.5MB 41.92%
