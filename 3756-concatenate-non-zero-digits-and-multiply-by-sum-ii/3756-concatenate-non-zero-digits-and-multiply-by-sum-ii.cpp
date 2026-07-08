class Solution {
public:
int M = 1e9+7;
struct Node {
    long long x = 0;
    long long sum = 0;
    long long cnt = 0;
};

Node make_node(char c) {
    Node t;
    if (c != '0') {
        int d = c - '0';
        t.cnt = 1;
        t.sum = d;
        t.x = d;
    }
    return t;
}

Node merge(const Node &L, const Node &R , vector<long long>& pow10) {
        Node res;
        res.cnt = L.cnt + R.cnt;
        res.sum = L.sum + R.sum;
        // L.x shifted by 10^(R.cnt) + R.x
        res.x = (L.x * pow10[R.cnt] + R.x) % M;
        return res;
}
void build(int i , int l , int r , vector<Node>& segment , string& s , vector<long long>& pow10){

    if(l == r){

        segment[i] = make_node(s[l]);
        return ;
    }

    int mid = l + (r-l)/2;

    build(2*i+1 , l , mid , segment , s , pow10);
    build(2*i+2 , mid+1 , r , segment , s , pow10);

 
    segment[i] = merge(segment[2*i+1] , segment[2*i+2] , pow10);

    return;
}

Node querry(int i , int l , int r , vector<Node>& segment , int ql , int qr , vector<long long>& pow10){

    if(ql > r || l > qr){
        return Node();
    }

    if(ql <= l && qr >= r ){
        return segment[i];
    }
    
    int mid = l + (r-l)/2;
    Node s1 = querry(2*i+1 , l , mid , segment , ql , qr , pow10 );
    Node s2 = querry(2*i+2 , mid+1 , r , segment , ql , qr , pow10);
    return merge(s1 , s2 , pow10);
    
}
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> ans;
       
        vector<Node> segment(4*n);

        vector<long long > pow10(n+1 , 1);

        for(int i=1; i<=n ; i++){
            pow10[i] = (pow10[i-1] *10 )%M;
        }
        build(0 , 0 , n-1 , segment , s , pow10);
        for(auto it : queries){
           
            int l = it[0];
            int r = it[1];
            

            Node x = querry(0 , 0 , n-1 , segment , l , r , pow10);

            long long out = (x.x * x.sum )%M;

            ans.push_back(out);

        }
        return ans;
    }
};