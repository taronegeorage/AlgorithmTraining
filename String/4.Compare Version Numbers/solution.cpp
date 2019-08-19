// leetcode 165.
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j =  0;
        while(i  < version1.size()+1 || j < version2.size()+1) {
            int ii = i;
            while(ii < version1.size() && version1[ii] != '.') ii++;
            int v1 = i == ii ? 0 : atoi(version1.substr(i, ii-i).c_str());
               
            int jj = j;
            while(jj < version2.size() && version2[jj] != '.') jj++;
            int v2 = j == jj ? 0 : atoi(version2.substr(j, jj-j).c_str());
            
            if(v1 > v2)
                return 1;
            else if(v2 > v1)
                return -1;
            i = ii+1;
            j = jj+1;
        }
        return 0;
    }
};

// 0ms 100%
// 8.5MB 69.57%
