class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        unordered_set<string> accessedSet;  /* 已访问集合 */

        if(uset.find(endWord) == uset.end()) return 0;

        int res = 1;
        string word;
        int letterLen = beginWord.size();
        queue<string> que;
        que.push(beginWord);
        accessedSet.insert(beginWord);

        //bfs
        while(!que.empty())
        {
            int size = que.size();
            //层次遍历，每层代表改变了一次字符
            ++res;
            for(int k=0; k<size; ++k)
            {
                word = que.front();
                for(int i=0; i<letterLen; ++i)
                {
                    for(char ch : "abcdefghijklmnopqrstuvwxyz")
                    {
                        word[i] = ch;
                        if(word == endWord) goto __out;
                        if(uset.count(word) && !accessedSet.count(word)) 
                        {
                            accessedSet.insert(word);
                            que.push(word);
                        }
                    }
                    word = que.front();
                }
                que.pop();
            }
        }
        /* 无法转换 */
        if(word != endWord) return 0;
__out:
        return res;
    }
};