class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> cols;
    unordered_set<int> diag1, diag2;     
    void solve(int i , int n , vector<string>& v ){

        if(i == n)ans.push_back(v);

        for(int j=0 ; j<n ; j++){
            
            if(cols.count(j) || diag1.count(i-j) || diag2.count(i+j)){
                continue;
            }

            v[i][j] = 'Q';
            cols.insert(j);
            diag1.insert(i-j);
            diag2.insert(i+j);

            solve(i+1 , n , v);

            v[i][j] = '.';
            cols.erase(j);
            diag1.erase(i-j);
            diag2.erase(i+j);
        }

        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        solve(0, n , v);
        return ans;
    }
};