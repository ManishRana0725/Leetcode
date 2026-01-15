class Solution {
public:
    int solve(int mid , vector<int>& nums , vector<int>& c){
        int n = nums.size();
        int m = c.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0 ; i<= mid ; i++){
            mpp[c[i]-1].push_back(i);
        }


        if(mpp.size() != n)return false;


        int operation = 0;
        int marked = 0;
        for(int i=0 ; i<=mid ; i++){
            int ind = c[i]-1;

            if(mpp.count(ind) != 0 && mpp[ind].back() == i){

                if(operation >= nums[ind]){
                    marked++;
                    operation -= nums[ind];
                }else{
                    return false;
                }
            }else{
                operation++;
            }
        }

        if(marked == n)return true;
        return false;

    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        int s = 0; 
        int e = m-1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(solve(mid , nums , changeIndices)){
                e = mid-1;
                ans = mid+1;
            }else{
                s = mid+1;
            }
        }

        return ans;
    }
};