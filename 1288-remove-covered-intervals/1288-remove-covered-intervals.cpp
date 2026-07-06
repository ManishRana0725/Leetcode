class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size();

        sort(arr.begin() , arr.end());

        int count = 0;
        
        for(int i=0 ; i<n-1 ; i++){
            
            if(arr[i][0] == arr[i+1][0]){
                count++;
                continue;
            }else if(arr[i][0] <= arr[i+1][0] && arr[i][1] >= arr[i+1][1]){
                int next = i+1;

                while(next < n && arr[i][0] <= arr[next][0] && arr[i][1] >= arr[next][1]){
                    
                    count++;
                    next++;
                    
                }
                i = next -1;
            }
        }
        return n-count;
    }
};