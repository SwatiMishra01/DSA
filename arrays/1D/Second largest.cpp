class Solution {
public:
    int secondLargest(vector<int>& nums) {
        int largest = INT_MIN;
        int second = INT_MIN;

        for (int x : nums) {
            if (x > largest) {
                if (x != largest) {
                    second = largest;
                    largest = x;
                }
            } 
            else if (x > second && x < largest) {
                second = x;
            }
        }

        return (second == INT_MIN ? -1 : second);
    }
};
