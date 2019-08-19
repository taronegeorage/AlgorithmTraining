class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> collect;
        for(auto word : strs) {
            string w = word;
            sort(w.begin(), w.end());
            collect[w].push_back(word);
        }
        for(auto item : collect) {
            ans.push_back(item.second);
        }
        return ans;
    }
};
