class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> mpp(26 , 0);
        
        int maxi = INT_MIN;

        for(int i =0 ; i<n ;i++){
            vector<int> mpp(26 , 0);
            
            for(int j=i ; j<n ;j++){
                mpp[s[j]-'a']++;
                bool flag = true;
                for(int k=0 ;k<26 ; k++){
                    if(mpp[k] >0 && mpp[k] != mpp[s[j]-'a']){
                        flag = false;
                        
                    }
                }

                if(flag){
                    maxi = max( maxi , (j-i)+1);
                }

            }
        }
        return maxi;
    }
};