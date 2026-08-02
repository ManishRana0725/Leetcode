class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        
        int n = tasks.size();
        int m = shifts.size();

        vector<long long> prefix(n+1 , 0);

        for(int i=n-1 ; i>=0 ; i--){

            prefix[i] = tasks[i] + prefix[i+1];
            
        }

        int i=0 ; 
        vector<int> ans(m);

        long long remaining = tasks[0];

        for(int j=0 ; j<m ; j++){

            long long total = remaining + prefix[i] - tasks[i];

            if((long long)shifts[j] >= total){
                // push back 0 
                // i = 0 , remaining = 0
                ans[j] = 0;
                i = 0 , remaining = tasks[0]; 
            }else{
                long long diff = total - shifts[j];

                // binaray on prefix array as diff is target 
                // can also use upper_bound , lower_bound
                int l = i, r = n - 1;
                int pos = i;

                while (l <= r) {
                    int mid = (l + r) / 2;

                    if (prefix[mid] >= diff) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                i = pos;
                remaining = diff - prefix[pos + 1];

                ans[j] = n - i;


            }
        }

        return ans;
        
    }
};