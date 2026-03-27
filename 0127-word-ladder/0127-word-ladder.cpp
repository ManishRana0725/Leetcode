class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int >> q;
        unordered_set<string > st(wordList.begin() , wordList.end());
       
        st.erase(beginWord);
        q.push({beginWord , 1});

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord)return level;

            for(int i=0;i<word.length();i++){
                char change = word[i];
                for(char j='a';j<='z';j++){
                    word[i] = j;
                    if(  st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word , level+1});
                    }
                }
                word[i] = change;
            }
        }
        return 0;
    }
};