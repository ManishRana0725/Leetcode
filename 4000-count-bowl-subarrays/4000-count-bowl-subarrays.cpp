class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        // yeh monotonic stack se hoga maxheap aur 2 pointer se nahi
        

        vector<int>right(n , n) , left(n , -1);

        stack<int> st;
        for(int i=0 ; i<n ;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1 ;i>=0  ;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(left[i] != -1 && right[i] != n)count++;
        }

        return count;
        
    }
};