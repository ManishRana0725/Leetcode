class Solution {
public:
    void makePrefix(int n , vector<int>& prefix){
        string s = to_string(n);
        int d = 0;
        string s1 ="";
        for(int i=0 ; i<s.size() ; i++){
            s1 = s[i];
            d = d*10 + stoi(s1);
            prefix.push_back(d);
        }
        return;
    }
    bool search(int n , vector<int>& prefix){
        int s = 0 ; 
        int e = prefix.size()-1;

        while(s <= e){
            int mid = s + (e - s)/2;

            if(prefix[mid] == n){
                return true;
            }else if(prefix[mid] > n){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return false;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        vector<int> prefix1;

        for(int i=0 ; i<n ; i++){
            makePrefix(arr1[i] , prefix1);
        }

        sort(prefix1.begin() , prefix1.end());
        int ans = 0;
        for(int i=0 ; i<m ; i++){

            string s = to_string(arr2[i]);
            int d = 0;
            string s1 = "";
            for(int i=0 ; i<s.size() ; i++){
                s1 = s[i];
                d = d*10 + stoi(s1);
                // - > binary search on prefix1
                if(search(d , prefix1)){
                    ans = max(ans , i+1);
                }
            }
            
            
        }
        return ans;
    }
};