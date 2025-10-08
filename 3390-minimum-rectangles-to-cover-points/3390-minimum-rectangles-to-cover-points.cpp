class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        vector<int> x_points;
        for(int i=0 ; i<n ;i++){
            x_points.push_back(points[i][0]);
        }

        sort(x_points.begin() , x_points.end());
        int ans = 1;
        int merge = x_points[0];

        for(int i=1; i<x_points.size() ; i++){
            if(x_points[i] - merge <= w){
                continue;
            }else{
                ans++;
                merge = x_points[i];
            }
        }
        return ans;
    }
};