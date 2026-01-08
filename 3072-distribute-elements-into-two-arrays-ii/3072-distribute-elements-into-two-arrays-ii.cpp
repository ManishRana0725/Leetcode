class Solution {
public:

    void update(int i , int l , int r , vector<int>& segment , int ind ){

        if( l == r){
            segment[i]++;
            return;
        }

        int mid = l + (r - l)/2;
        
        if(ind <= mid){
            update(2*i+1 , l , mid , segment , ind );
        }else{
            update(2*i+2 , mid+1 , r , segment ,ind );
        }

        segment[i] = segment[2*i+1] + segment[2*i+2];

    }
    int range(int i , int l , int r , vector<int>& segment , int start , int end){

        if(r < start || l > end){
            return 0;
        }

        if( start <= l && r <= end){
            return segment[i];
        }
        
        int mid = l + (r - l)/2;

        int leftsum = range(2*i+1 , l , mid , segment , start , end);
        int rightsum = range(2*i+2 , mid+1 , r , segment , start , end);

        
        return leftsum + rightsum;
    }
    vector<int> resultArray(vector<int>& nums) {
        int m = nums.size();
        vector<int> arr = nums;
        sort(arr.begin() , arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        unordered_map<int , int> mpp;
        int value = 1;

        for(auto it : arr){
            mpp[it] = value ;
            value++;
        }

        int n = arr.size();

        vector<int>segment1(4*n , 0) , segment2(4*n , 0);
        vector<int> arr1 , arr2;

        arr1.push_back(nums[0]);
        update(0 , 1 , n , segment1 , mpp[nums[0]]);
        arr2.push_back(nums[1]);
        update(0 , 1 , n , segment2 , mpp[nums[1]]);

        
        for(int i=2 ; i<m ; i++){
            int x = mpp[nums[i]];

            int q1 = range(0 , 1 , n , segment1 , x+1 , n);
            int q2 = range(0 , 1 , n , segment2 , x+1 , n);

            if(q1 > q2){
                update(0 , 1 , n , segment1 , x);
                arr1.push_back(nums[i]);
            }else if(q2 > q1){
                update(0 , 1 , n , segment2 , x);
                arr2.push_back(nums[i]);
            }else{  
                int n1 = arr1.size();
                int n2 = arr2.size();

                if(n1 <= n2){
                    update(0 , 1 , n , segment1 , x);
                    arr1.push_back(nums[i]);
                }else if(n2 < n1){
                    update(0 , 1 , n , segment2 , x);
                    arr2.push_back(nums[i]);
                }
            }
        }
        vector<int> ans;

        for(int i=0 ; i<arr1.size() ; i++){
            ans.push_back(arr1[i]);
        }
        for(int i=0 ; i<arr2.size() ; i++){
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};