class Solution {
public: 
    // DP se bhi solve ho sakta hai 
    // agar hum har ek * pe all possible case check kar toh recursion se solve ho sakta hai aur phir usko optimize kar sakte hai 
    bool checkValidString(string s) {
        // stack<int> open; 
        // stack<int> star; 
        // for (int i = 0; i < s.length(); i++) {
        //     char ch = s[i];

            
        //     if (ch == '(') {
        //         open.push(i);
             
        //     } else if (ch == '*') {
        //         star.push(i);
   
        //     } else {
              
        //         if (!open.empty()) {
        //             open.pop();
                  
        //         } else if (!star.empty()) {
        //             star.pop();
                  
        //         } else {
        //             return false;
        //         }
        //     }
        // }

      
        // while (!open.empty() && !star.empty()) {

        //     if (open.top() > star.top()) {
        //         return false; 
        //     }
        //     open.pop();
        //     star.pop();
        // }

       
        // return open.empty();


        int n = s.size();

        int max = 0 , min = 0;

        for(int i=0 ; i<n ; i++){
            if(s[i] == '('){
                max += 1;
                min += 1;
            }else if(s[i] == ')'){
                min -= 1;
                max -= 1;
            }else{
                max += 1;
                min -= 1;
            }

            if(min < 0)min = 0;

            if(max < 0 )return false;
        }

        return (min == 0);
    }
};