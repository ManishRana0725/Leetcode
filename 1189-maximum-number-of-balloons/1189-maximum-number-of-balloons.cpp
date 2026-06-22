class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> mpp(26 , 0 );

        for(int i=0 ; i<n ; i++){
            mpp[text[i]-'a']++;
            
        }

        mpp['l'-'a'] /=2;
        mpp['o'-'a'] /=2;

        int mini = INT_MAX;
        for(int i=0 ; i<26 ;i++){

            if(i == 1 || i == 0 || i == 11 || i == 13 || i == 14 ){

                mini = min(mini , mpp[i]);
            }

        }

        return mini;
    }
};