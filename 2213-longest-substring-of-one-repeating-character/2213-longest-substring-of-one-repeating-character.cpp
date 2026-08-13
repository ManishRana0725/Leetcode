class Solution {
public:
    struct Node{
        int pre= 0 ;
        int suff = 0;
        int maxlen = 0 ; 
        char rightchar = 0;
        char leftchar = 0;

    };
    int n ;
    vector<Node>segmentTree;

    Node merge(const Node& L , const Node& R , int leftlen , int rightlen){
        Node res;


        res.leftchar = L.leftchar;
        res.rightchar = R.rightchar;


        res.pre = L.pre;
        if(L.pre == leftlen && L.rightchar == R.leftchar){
            res.pre = L.pre + R.pre;
        }

        res.suff = R.suff;
        if(R.suff == rightlen && L.rightchar == R.leftchar){
            res.suff = L.suff + R.suff;
        }

        res.maxlen = max(L.maxlen , R.maxlen);

        if(L.rightchar == R.leftchar){
            res.maxlen = max(res.maxlen , L.suff + R.pre);
        }

        return res;

    }

    void buildsegment(int i , int l  , int r , string& s){
        if(l == r){
            segmentTree[i] = {1 , 1, 1 , s[l] , s[l]};
            return;
        }


        int mid = l + (r-l)/2;
        buildsegment(2*i+1 , l , mid , s);
        buildsegment(2*i+2 , mid+1 , r , s);

        segmentTree[i] = merge(segmentTree[2*i+1] , segmentTree[2*i+2] , mid-l+1 , r-mid);
    }
    void update(int i , int l  , int r , int pos , char ch){

        if(l == r){
            segmentTree[i] = {1 , 1 , 1 , ch , ch};
            return;
        }

        int mid = l + (r-l)/2;

        if(pos <= mid){
            update(2*i+1 , l , mid , pos , ch);
        }else{
            update(2*i+2 , mid+1 , r , pos , ch);
        }

        segmentTree[i] = merge(segmentTree[2*i+1] , segmentTree[2*i+2] , mid-l+1 , r-mid);

    }

    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        int k = queryCharacters.size();
        segmentTree.resize(4*n , Node());

        buildsegment(0 , 0 , n-1 , s);

        vector<int> result(k);

        for(int i=0 ; i<k ; i++){
            int pos = queryIndices[i];
            char val = queryCharacters[i];

            update(0 , 0 , n-1 , pos , val);

            result[i] = segmentTree[0].maxlen;
        }
        return result;
    }
};