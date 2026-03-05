class Solution {
public:
    int longest(vector<int>& arr){
        sort(arr.begin(), arr.end());
        
        int best = 1, cur = 1;
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1] + 1){
                cur++;
            }else{
                cur = 1;
            }
            best = max(best, cur);
        }
        
        return best;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
         int h = longest(hBars);
        int v = longest(vBars);
        
        int side = min(h + 1, v + 1);
        
        return side * side;
    }
};