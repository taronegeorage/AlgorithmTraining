class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        stringstream ss;
        ss << str;
        ss >> ans;
        return ans;
    }
};
