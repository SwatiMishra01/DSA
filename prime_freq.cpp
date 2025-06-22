- You are given an integer array nums.
- Return true if the frequency of any element of the array is prime, otherwise, return false.
- The frequency of an element x is the number of times it occurs in the array.
- A prime number is a natural number greater than 1 with only two factors, 1 and itself.

 
----------------------------------------------------------------------------------------------------------------------
Example 1:
Input: nums = [1,2,3,4,5,4]
Output: true

Explanation:
4 has a frequency of two, which is a prime number.©leetcode

  ------------------------------------------------------------------------------------------------------------------------

  class Solution {
//function to check if a no. is prime or not
bool isPrime(int n){
    //// 0 and 1 are not prime
    if(n<=1)
    return false;

//2 & 3 are prime
if(n==2 || n==3)
    return true;


//for even no. and divisible by 3
    if(n%2==0 || n%3==0)
        return false;

        //any prime no. >3 lies in the form of-
       //             6k+1 OR 6k-1
        for(int i=5; 1LL *i*i<n; i+=6){
            if(n%i==0 || n%(i+2)==0)
                return false;
        }
return true;
}
        

        

    
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        //storing freq count
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }


        //checking if it is prime or not
        for (auto&[key,val]:freq){
            if(isPrime(val))
                return true;
        }
        return false;
    }
};©leetcode
