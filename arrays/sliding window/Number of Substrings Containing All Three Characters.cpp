https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
LEETCODE- 1358
------------------------------------
        BRUTE FORCE (TLE)
------------------------------------
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int hash[3] = {0};  // Reset for each i

            for (int j = i; j < n; j++) {
                hash[s[j] - 'a'] = 1;
                if (hash[0] + hash[1] + hash[2] == 3)
                    count++;
            }
        }

        return count;
    }
};
T.C=O(N^3)
S.C=O(3)

------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------------
             SLIDING WINDOW
  -------------------------------------------
  class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.size();
        int lastSeen[3]={-1,-1,-1};
        for(int i=0; i<n; i++){
            lastSeen[s[i]-'a']=i;
            if(
                lastSeen[0]!=-1 &&
                lastSeen[1]!=-1 &&
                lastSeen[2]!=-1
            )
            count+=1+min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
        return count;
    }
};
T.C=O(N)
S.C=O(3)
