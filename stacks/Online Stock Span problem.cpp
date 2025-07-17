https://leetcode.com/problems/online-stock-span/description/
LEETCPDE-901

----------------------------------------
  APPROACH 1-> BRUTE FORCE
----------------------------------------

class StockSpanner {
public:
//store all previous prices
vector<int>prices;
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        int count=1;
      // go backwards until a price > current price is found
        for(int i=prices.size()-2; i>=0; i--){
            if(prices[i]<=price)
            count++;
            else
            break;
        }
        return count;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
T.C=O(N^2)
S.C=O(N)

  -----------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------------
   APPROACH 2-> MONOTONIC STACK (PGE)
  -------------------------------------------
  class StockSpanner {
public:
stack<pair<int,int>>st;
int day=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        day++;
        

        //PGE- prev greater element function
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }

        int span=st.empty()?day:day-st.top().second;

        st.push({price,day});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
T.C=O(N)
S.C=O(N)
