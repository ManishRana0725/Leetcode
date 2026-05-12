class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";

        for(auto it : chunks){
            s += it;
        }

        string word = "";
        unordered_map<string , int> mpp;
        int n = s.size();
        for(int i=0 ; i<n ; i++){
            
            if(s[i] == ' '){
                mpp[word]++;
                word = "";
            }
            else if(s[i] == '-'){

                if(i > 0 && i < n-1 && (s[i-1] >= 'a' && s[i-1] <= 'z') && (s[i+1] >= 'a' && s[i+1] <= 'z')){
                    word += s[i];
                }else{
                    mpp[word]++;
                    word = "";
                }
            }else{
                word += s[i];
            }
        }

        mpp[word]++;

        vector<int> ans;

        for(auto it : queries){
            if(mpp.count(it)){
                ans.push_back(mpp[it]);
            }else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};