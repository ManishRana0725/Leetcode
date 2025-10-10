class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;
        while(numBottles > 0){
            
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
             if(empty >= numExchange){
               
                empty = empty - numExchange;
                numBottles++;
                numExchange++;
            }
            else{
                ans += numBottles;
                numBottles = 0;
            }
            
            
        }

        return ans;
    }
};