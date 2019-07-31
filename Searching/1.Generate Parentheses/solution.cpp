// leetcode 22.
//

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        help("", n, n);
        return ans;
    }

    void help(string sub, int left, int right) {
        if(left == 0 && right == 0){
            ans.push_back(sub);
            return;
        }
        if(left > 0){
            help(sub+"(", left-1, right);
        }

        if(right > left) {
            help(sub+")", left, right-1);
        }

    }
private:
    vector<string> ans;
};

// 4ms 93.46%
// 17.4MB 24.28%
