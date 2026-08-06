class Solution {
public:
    bool solve(int n , int t){
        int pro = 1;
        while(n>0){
            int d = n%10;
             n = n/10;
            pro *= d;
        }
        if(pro % t == 0)return true;
        else return false;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(!solve(i , t)){
            i++;
        }
        return i;
    }
};