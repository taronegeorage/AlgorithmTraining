// 682.
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        for(const string& op : ops){
            if(op == "+")
                s.push_back(s.end()[-1]+s.end()[-2]);
            else if(op == "C")
                s.pop_back();
            else if(op == "D")
                s.push_back(s.back()*2);
            else
                s.push_back(stoi(op));
        }
        return accumulate(s.begin(), s.end(), 0);
    }
};
