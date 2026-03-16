class Solution {
public:
    bool good(int x){
        string s = to_string(x);

        bool inc = true, dec = true;

        for(int i=1;i<s.size();i++){
            if(s[i] <= s[i-1]) inc = false;
            if(s[i] >= s[i-1]) dec = false;
        }

        return inc || dec;
    }

    long long dp[20][2][2][11][2][2][150];
    bool goodSum[150];

    long long solve(int pos, bool tight, bool started, int last,
                    bool inc, bool dec, int sum, string &s){

        if(pos == s.size()){
            if(!started) return 0;

            if(inc || dec) return 1;

            if(goodSum[sum]) return 1;

            return 0;
        }

        long long &res = dp[pos][tight][started][last][inc][dec][sum];
        if(res != -1) return res;

        res = 0;

        int limit = tight ? s[pos]-'0' : 9;

        for(int d=0; d<=limit; d++){

            bool newtight = tight && (d==limit);
            bool newstarted = started || (d!=0);

            int newlast = last;
            bool newinc = inc;
            bool newdec = dec;
            int newsum = sum;

            if(!newstarted){
                res += solve(pos+1, newtight, newstarted, 10, 1, 1, 0, s);
                continue;
            }

            if(!started){
                newlast = d;
                newsum = d;
            } 
            else{
                if(d <= last) newinc = 0;
                if(d >= last) newdec = 0;
                newsum += d;
                newlast = d;
            }

            res += solve(pos+1, newtight, newstarted, newlast, newinc, newdec, newsum, s);
        }

        return res;
    }
    
    long long calc(long long x){

        string s = to_string(x);
        memset(dp,-1,sizeof(dp));

        return solve(0,1,0,0,1,1,0,s);
    }
    long long countFancy(long long l, long long r) {
        
        for(int i=0;i<150;i++){ // the sum of any 15 digit number is at most 15*9 so we can compute for the sums 
            goodSum[i] = good(i);
        }
        return calc(r) - calc(l-1);
    }
};