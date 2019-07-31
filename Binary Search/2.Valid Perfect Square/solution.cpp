// leetcode 367.
//

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1)
            return true;
        long left = 1, right = num;
        long mid;
        while(left <= right) {
            mid = (left+right)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid < num)
                left = mid + 1;
            else
                right = mid - 1;

        }
        return false;
    }
};

//0ms 100%  4ms 68.53
//8.2 16.03%
