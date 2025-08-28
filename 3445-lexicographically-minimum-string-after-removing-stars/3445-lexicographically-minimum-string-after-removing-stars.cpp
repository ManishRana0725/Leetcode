class Solution {
public:
    struct Compare{
        bool operator()(const pair<char,int>& a , const pair<char , int>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }    
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        priority_queue< pair<char , int> , vector<pair<char , int>> , 
            Compare> pq;

        int n = s.size();
        vector<bool> flag(n , false);

        for(int i=0 ; i<n ;i++){
            if(s[i] != '*'){
                pq.push({s[i] , i});
            }else{
                flag[i] = true;
                auto [ch , ind] = pq.top();
                flag[ind] = true;
                pq.pop();
            }
        }

        string ans = "";
        for(int i=0 ; i<n ; i++){
            if(flag[i]){
                continue;
            }else{
                ans += s[i];
            }
        }
        return ans;

        
    }
};