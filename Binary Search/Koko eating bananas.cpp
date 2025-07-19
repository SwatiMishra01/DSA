https://leetcode.com/problems/koko-eating-bananas/description/
LEETCODE-875
  -------------------------------------------------
     BRUTE FORCE-> will not work due to overflow
  --------------------------------------------------

class Solution {
public:
//function to find maximum in array
int findMax(vector<int> &piles) {
    int maxi = INT_MIN;
    int n = piles.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}


//function to calculate total time
int calculateTotalHours(vector<int> &piles, int hourly) {
    int totalH = 0;
    int n = piles.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(piles[i]) / (double)(hourly));
    }
    return totalH;
}

//MIAN FUNCTION
    int minEatingSpeed(vector<int>& piles, int h) {
        //Find the maximum number:
    int maxi = findMax(piles);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(piles, i);
        if (reqTime <= h) {
            return i;
        }
    }

    // return statement
    return maxi;
    }
T.C=O(max(a[]) * N)
S.C=O(1)

----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------
          BINARY SEARCH
-------------------------------------
class Solution {
public:
    bool canFinish(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // This is equivalent to ceiling(pile / k)
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1; // Minimum eating speed
        int e = *max_element(piles.begin(), piles.end()); // Maximum eating speed

        while (s < e) {
            int mid = s + (e - s) / 2;
            if (canFinish(piles, mid, h)) {
                e = mid; // Try a slower speed
            } else {
                s = mid + 1; // Increase speed
            }
        }
        return s; // The minimum k where she can finish within h hours
    }
};
};
