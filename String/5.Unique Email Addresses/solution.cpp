// leetcode 929,
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        for(auto email : emails) {
            int at = email.find('@');
            stringstream newemail;
            // string newemail;
            for(auto ch : email.substr(0, at)) {
                if(ch == '+') break;
                else if(ch != '.') newemail << ch;
            }
            newemail << email.substr(at);
            ans.insert(newemail.str());
        }
        return ans.size();
    }
};

// 40ms 26.45%
// 19.6MB 7.14%
