class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costboth, int need1, int need2) {
        
        bool bothorone = false; // true if both cost1 + cost2 > copstboth is less

        if(cost1 + cost2 > costboth){
            bothorone = true;
        }

        long long ans = 0;

        if(bothorone){
            int d =  min(need1 , need2);

            ans += 1LL * d * costboth;
            need1 -= d;
            need2 -= d;
            if(need1 > 0){
                if(cost1 < costboth ){
                    ans += 1LL * need1 * cost1;
                }else{
                    ans += 1LL * need1 * costboth;
                }
            }
            if(need2 > 0){
                if(cost2 < costboth ){
                    ans += 1LL * need2 * cost2;
                }else{
                    ans += 1LL * need2 * costboth;
                }
            }
        }else{

            if(cost1 < costboth && cost2 < costboth){
                ans += 1LL * need1 * cost1;
                ans += 1LL * need2 * cost2;

            }else if(cost1 > costboth){
                ans += 1LL * need1 * costboth;

                need2 -= need1;

                if(need2 > 0){
                    ans += 1LL * need2 * cost2;
                }
            }else if(cost2 > costboth){
                ans += 1LL * need2 * costboth;

                need1 -= need2;

                if(need1 > 0){
                    ans += 1LL *need1 * cost1;
                }
            }
            
        }
        
        return ans;
    }
};