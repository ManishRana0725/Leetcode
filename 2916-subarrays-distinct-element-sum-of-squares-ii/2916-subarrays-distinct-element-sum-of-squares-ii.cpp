class Solution {
public:
    int MOD = 1e9+7;
    vector<long long>sqsumtree;
    vector<long long>sumtree;
    vector<long long>lazytree;
    int n ;

    void lazyAddition(int i , int l , int r , int val){
        int len = r-l+1;

        sqsumtree[i] += 2*val*sumtree[i] + len * val * val;
        sumtree[i] += (len *val);
    }
    void updateRange(int start , int end , int i , int l , int r , int val){

        if(lazytree[i] != 0){
            lazyAddition(i , l , r , lazytree[i]);

            if(l != r){
                lazytree[2*i+1] += lazytree[i];
                lazytree[2*i+2] += lazytree[i];
            }
            lazytree[i] = 0;
        }

        // completely outof range
        if( l > end || r < start || l > r){
            return;
        }

        if(l >= start && r <= end){
            lazyAddition(i , l , r , val);

            if(l != r){
                lazytree[2*i+1] += val;
                lazytree[2*i+2] += val;
            }
            return ;

        }

        int mid = l + (r-l)/2 ;

        updateRange(start , end , 2*i+1 , l , mid , val);
        updateRange(start , end , 2*i+2 , mid+1 , r , val);

        sumtree[i] = sumtree[2*i+1] + sumtree[2*i+2];
        sqsumtree[i] = sqsumtree[2*i+1] + sqsumtree[2*i+2];
    }
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqsumtree.assign(4*n , 0);
        sumtree.assign(4*n , 0);
        lazytree.assign(4*n , 0);

        vector<int> lastseen(100001 , -1);

        long long result = 0;

        for(int i=0 ; i<n ; i++){
            int start = lastseen[nums[i]] + 1;
            int end = i;

            updateRange(start , end , 0 , 0 , n-1 , 1);

            result = (result + sqsumtree[0] ) % MOD;

            lastseen[nums[i]] = i;
        }

        return (int)result;
    }

};