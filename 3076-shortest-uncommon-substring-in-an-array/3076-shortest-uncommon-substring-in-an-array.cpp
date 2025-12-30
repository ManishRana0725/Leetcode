class Solution {
public:
    void generatesub(string& s , unordered_map<string , int>& mpp){

        int n = s.size();
        unordered_set<string> seen;   // FIX 1

        for(int i = 0; i < n; i++){
            string sub = "";
            for(int j = i; j < n; j++){
                sub += s[j];
                seen.insert(sub);
            }
        }

        for(auto &x : seen){
            mpp[x]++;
        }
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        int n = arr.size();

        unordered_map<string , int> mpp;
        vector<string> ans;
        for(auto it : arr){
            generatesub(it , mpp);
        }
        bool flag = false;
        for(auto it : arr){
            int m = it.size();
            string sub = "";
            int count = INT_MAX;
            string mini = it;
            flag = false;
            for(int i=0 ; i<m ; i++ ){
                sub = "";
                for(int j = i ; j<m ; j++){
                    sub += it[j];
                    
                    if(mpp[sub] == 1){
                        int len = j - i + 1;
                        if(len < count || (len == count && sub < mini)){
                            mini = sub;
                            count = len;
                            flag = true;
                        }
                    }                
                }
            }

            if(flag){
                ans.push_back(mini);
            }else{
                ans.push_back("");
            }
        }
        return ans;
    }
};