class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string>ans(m);
        string hori = "";
        for(int i=0 ; i<m ;i++){
            string s = "";

            for(int j = 0 ; j<n ; j++){

                if(j == n-1){
                    s.push_back('.');
                }
                else{
                    s.push_back('#');
                }
            }

            ans[i] = s;
        }

        for(int i=0 ; i<n ; i++){
            hori.push_back('.');
        }

        ans[0] = hori;

       

        return ans;
    }
};