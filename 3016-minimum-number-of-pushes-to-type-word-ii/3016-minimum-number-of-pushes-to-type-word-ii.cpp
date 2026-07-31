class Solution {
public:
    int minimumPushes(string word) {

        vector<int> mpp(26 , 0);
        for(auto ch : word){
            mpp[ch-'a']++;
        }

        sort(mpp.rbegin() , mpp.rend());

        int ans = 0;
        int count = 0;
        for(int i=0 ; i<26 ;i++){
            count++;
            int times = count/8;
            if(count%8 != 0)times++;
            ans += ((times)* mpp[i]);
        }
        return ans;
    }
};