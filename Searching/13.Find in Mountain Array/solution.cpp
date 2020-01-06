/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i = 0, j = mountainArr.length()-1;
        while(i < j) {
            int mid = (i+j)>>1;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) i = mid+1;
            else j = mid;
        }
        int peak = i;
        if(target > mountainArr.get(peak)) return -1;
        // 先找左边
        int lo = 0, hi = peak;
        while (lo < hi) {
            int mid = lo + hi + 1>> 1;
            if (target < mountainArr.get(mid)) 
                hi = mid - 1;
            else lo = mid;
        }
        if(mountainArr.get(lo)==target) return lo;
        // 在右边找。
        lo = peak + 1, hi = mountainArr.length() - 1;
        cout << lo << " " << hi << endl; 
        while (lo < hi) {
            int mid = lo + hi + 1 >> 1;
            if (target > mountainArr.get(mid)) 
                hi = mid - 1;
            else lo = mid;
        }
        if(mountainArr.get(lo)==target) return lo;
        return -1;
    }
};

// 8ms 9.4MB
