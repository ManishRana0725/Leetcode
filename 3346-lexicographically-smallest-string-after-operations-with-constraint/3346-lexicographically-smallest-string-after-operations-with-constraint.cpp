class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        vector<char> mpp(52);

        for(int i=0 ; i<52 ;i++){
            mpp[i] =  'a' + (i%26);
            cout<<mpp[i];
        }
        cout<<endl;
        for(int i=0 ;i<n; i++){
        
            int diff = min(s[i] - 'a' , (mpp[25] - s[i]) +1 );
            
            if(k >= diff){
                s[i] = 'a';
                k = k-diff;
            }
            else{
                s[i] = s[i]-k;
                k = 0;
                break;
            }

        }
        return s;
    }
};