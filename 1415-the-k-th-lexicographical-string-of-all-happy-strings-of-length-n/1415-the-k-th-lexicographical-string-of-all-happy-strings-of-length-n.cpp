class Solution {
public:
    vector<string> store;
    int n;
    void solve(int i , char prev , string& s){
        
        if(i == n){
            store.push_back(s);
            return;
        }
        
        if(prev != 'a'){
            s+='a';
            char newprev = 'a';
            solve(i+1 , newprev , s);
            s.pop_back();
        }
        if(prev != 'b'){
            s+='b';
            char newprev = 'b';
            solve(i+1 , newprev , s);
            s.pop_back();
        }
        if(prev != 'c'){
            s+='c';
            char newprev = 'c';
            solve(i+1 , newprev , s);
            s.pop_back();
        }

        return;
    }
    string getHappyString(int n, int k) {
        this->n = n;
        char prev = ' ';
        string s = "";
        solve(0 , prev , s );

        sort(store.begin() , store.end());

        if(store.size() < k){
            return "";
        }
        return store[k-1];
    }
};