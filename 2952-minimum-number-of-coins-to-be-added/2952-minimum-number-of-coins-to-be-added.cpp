class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();

        int count = 0 ;
        int reach = 0;
        int i = 0;
        sort(coins.begin() , coins.end());

        while(reach < target){

            if(i < n && coins[i] <= reach+1){
                reach += coins[i];
                i++;
            }else{
                count++;
                reach += (reach+1);
            }
        }
        return count;
    }
};