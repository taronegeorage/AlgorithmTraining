class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> m;
        for(auto& ch : s)
            m[ch] += 1;
        for(auto& ch : t){
            m[ch] -= 1;
            if(m[ch] < 0)
                return false;
        }
        return true;
    }
};

// 16ms 62.23%
// 9.5MB 16%


// use array
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        return false;
    
        int count[26] = {0};
    
        for (int i=0; i<s.size();i++)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
    
        for (int i=0; i<s.size();i++)
        {
            if (count[s[i]-'a']!=0)
                return false;
        }
    
        return true;
    }
};

// 8ms 98.52%
// 9.5MB 28.69%
