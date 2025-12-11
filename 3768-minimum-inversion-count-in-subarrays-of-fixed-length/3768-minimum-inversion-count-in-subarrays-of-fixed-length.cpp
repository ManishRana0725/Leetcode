class Solution {
public:

    void build_segment_tree( int i , int l , int r , vector<int>& segment_tree , vector<int>& arr ) {
        // your code here

        if(l == r){
            segment_tree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build_segment_tree(2*i + 1 , l , mid , segment_tree , arr);
        build_segment_tree(2*i + 2 , mid + 1 , r , segment_tree , arr); 

        segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2*i + 2];
        return;
    }

    void update_segment_tree(int i , int l , int r , vector<int>& segment_tree , int index , int value ){
        // your code here

        if(l == r ){
            segment_tree[i] += value;
            return;
        }

        int mid = l + (r - l) / 2;

        if(index <= mid){
            update_segment_tree( 2*i+1 , l , mid , segment_tree , index  , value );
        }else{
            update_segment_tree(2*i+2 ,  mid + 1 , r , segment_tree , index  , value );
        }

        segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2*i + 2];
        return;
    }   


    long long query_segment_tree(int i , int l , int r , vector<int>& segment_tree , int start , int end ){
        // your code here

        if(r < start || l > end){  // out of range
            return 0; // neutral element for sum
        }

        if(l >= start && r <= end){  // completely within range
            return segment_tree[i];
        }

        int mid = l + (r - l) / 2;
        // partially within range
        int left_sum = query_segment_tree(2*i + 1 , l , mid , segment_tree , start , end);
        int right_sum = query_segment_tree(2*i + 2 , mid + 1 , r , segment_tree , start , end);

        return left_sum + right_sum;
    }   
    long long minInversionCount(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin() , arr.end());
        
        unordered_map<int , int> map;
        int value = 1;
        for(int i=0 ; i<n ; i++){
            map[arr[i]] = value;
            value++;
        }
        int maxi = value;
        int mini = 1;
        vector<int> a(n);

        for(int i=0 ; i<n ; i++){
            int d = nums[i];
            a[i] = map[d];
        }

        vector<int> segment_tree(4*value , 0);
        long long ans = 0;
        for(int i=0 ; i<k ; i++){
            update_segment_tree(0 , 1 , maxi , segment_tree , a[i] , 1 );
            if(i > 0){
                ans += query_segment_tree(0 , 1 , maxi , segment_tree , a[i]+1 , maxi );
            }
        }

        long long final_ans = LLONG_MAX;
        final_ans = min(final_ans , ans);

        for(int i=k ; i<n ; i++){
            // delete char 
            ans -= query_segment_tree(0 , 1 , maxi , segment_tree , 1 ,  a[i-k]-1 );

            update_segment_tree( 0 , mini , maxi , segment_tree , a[i-k] , -1);

            update_segment_tree(0 , mini , maxi , segment_tree , a[i] , +1);

            ans += query_segment_tree(0 , 1 , maxi , segment_tree , a[i]+1 ,  maxi);
            
            final_ans = min(final_ans , ans);
        }


        return final_ans;


    }
};