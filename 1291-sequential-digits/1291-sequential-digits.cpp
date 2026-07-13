class Solution {
public:
    vector<int> ans;

    void solve(string s , int low , int high){
        int num = stoi(s);

        if(num > high)return;

        if(num >= low && num <= high){
            ans.push_back(num);
        }

        if(num <= high){
            
            
            int last_digit = (num > 10) ? num%10 : num;
            if(last_digit == 9)return;
            string newnum = s + to_string(last_digit+1);
            solve(newnum , low , high);   

        }
    }
    vector<int> sequentialDigits(int low, int high) {
        string s = "";
        for(int i=1; i<= 9 ; i++){
            s = to_string(i);
            solve(s , low , high);
            s.pop_back();
        }

        sort(ans.begin() , ans.end());
        return ans;
    }
};