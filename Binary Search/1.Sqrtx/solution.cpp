//leetcode 69.

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x==1)
            return x;
        int left = 0, right = x;
        int mid = 0;
        while(left <= right) {
            mid = (left+right) / 2;
            if(mid <= x/mid && (mid+1) > x/(mid+1)) 
                break;
            else if(mid  > x/mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return mid;
        
    }
};

// 0ms 100.00%
// 8.2MB 40.64%
//




int mySqrt(int x) {
        long ans = x;
        while(ans*ans > x)
            ans = (ans + x / ans) / 2;
        return ans;
    }

// 4ms 84.51%
// 8MB 86.54%
