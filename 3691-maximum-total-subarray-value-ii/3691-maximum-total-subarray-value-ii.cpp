class SegmentTree{
    public:
    vector<int> segmentTree;
    bool isMinTree;

    SegmentTree(vector<int>& nums , bool flag){
        int n = nums.size();
        this->isMinTree = flag;

        segmentTree.resize(4*n);

        buildSegment(0 , 0 , n-1 , nums);
    }

    void buildSegment(int i , int l , int r , vector<int>& nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;

        buildSegment(2*i+1 , l , mid ,nums);
        buildSegment(2*i+2 , mid+1 , r , nums);

        if(isMinTree){
            segmentTree[i] = min(segmentTree[2*i+1] , segmentTree[2*i+2]);
        }else{
            segmentTree[i] = max(segmentTree[2*i+1] , segmentTree[2*i+2]);
        }
    }

    int query(int start , int end , int i , int l , int r){

        if(l > end  || r < start){
            return isMinTree ? INT_MAX : INT_MIN;
        }

        if(l >= start && r <= end){
            return segmentTree[i];
        }
        
        int mid = l + (r-l)/2;

        int a = query(start , end , 2*i+1 , l , mid );
        int b = query(start , end , 2*i+2 , mid+1 , r);

        if(isMinTree){
            return min(a , b);
        }
        return max(a , b);
        
    }

    int q(int l , int r , int n){
        return query(l , r , 0 , 0 , n-1);
    }
};
class Solution {
public:

    typedef long long ll;

    ll getvalue(int l , int r , SegmentTree & minST , SegmentTree & maxST , int n ){
        int minEL = minST.q(l , r , n);
        int maxEL = maxST.q(l , r , n);

        return (ll)maxEL - minEL;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        SegmentTree minst(nums , true);
        SegmentTree maxst(nums , false);


        priority_queue<tuple<ll , int , int>> pq;

        for(int i=0 ; i<n ; i++){
            ll value = getvalue(i , n-1 , minst , maxst , n);
            pq.push({value , i , n-1});
        }

        ll result = 0;
        while(k--){
            auto [value , l , r] = pq.top();
            pq.pop();
            result += value;

            ll nextvalue = getvalue(l , r-1 , minst , maxst , n);

            pq.push({nextvalue , l , r-1});
        }

        return result;

    }
};