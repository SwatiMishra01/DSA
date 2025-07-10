https://leetcode.com/problems/lemonade-change/description/
LEETCODE-860

  class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(int i=0; i<bills.size(); i++){
            //if it is a bill of five
            if(bills[i]==5){
                five++;
            }
            //if it is a bill of 10-> return 5 if there is a five o/w false
            else if(bills[i]==10){
                if(five){
                five--;
                ten++;
                }
                else{
                    return false;
                }
            }

            //if it is a bill of 20-> return 10+5 or 5+5+5 or false o/w
            else{
               if( five && ten){
                five--;
                ten--;
               }
               else if(five>=3){
                five-=3;
               }
               else
                return false;
              
            }
        }
        return true;
    }
};
