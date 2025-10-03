class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 0;
        int n = tasks.size();
        unordered_map<int , long long> mpp;
        
        for(int i=0 ; i<n ; i++){
            ans++;
            if(mpp.find(tasks[i]) != mpp.end()){
                if(mpp[tasks[i]] + space >= ans){
                    ans = mpp[tasks[i]] + space + 1;
                    mpp[tasks[i]] = ans ;
                }else{
                    mpp[tasks[i]] = ans;
                }
            }
            else{
                mpp[tasks[i]] = ans ;
                
            }
        }

        return ans;
    }
};