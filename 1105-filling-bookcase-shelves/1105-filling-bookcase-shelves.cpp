class Solution {
public:
    int dp[1000];
    int solve(int i , vector<vector<int>>& books, int shelfwidth ){
        int n = books.size();

        if(i == n)return 0;

        if(dp[i] != -1)return dp[i];
        int minheight = INT_MAX;
        int width = shelfwidth;
        int height = 0 ;

        for(int j = i ; j < n ; j++){
            int w = books[j][0];
            int h = books[j][1];

            if(width >= w){
                height = max(height , h);
                width -= w;
                minheight = min(minheight , height +  solve(j+1 , books , shelfwidth));
            }else{
                minheight = min(minheight , height + solve(j , books , shelfwidth));
                break;
            }
        }

        return dp[i] = minheight;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfwidth) {
        int n = books.size();

        memset(dp , -1 , sizeof(dp));
        return solve(0 , books , shelfwidth);
    }
};