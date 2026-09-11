class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        for(int i=0 ; i<n ; i++){
            if(digits[i] == 0)continue;

            for(int j=0 ; j<n ; j++){

                if(i == j)continue;

                for(int k = 0 ; k<n ; k++){

                    if(i == k || j == k)continue;

                    int number = digits[i];
                    number*=10;
                    number += digits[j];
                    number*=10;
                    number += digits[k];

                    if(number % 2 == 0){
                        st.insert(number);
                    }
                }
            }
        }
        return st.size();
    }
};