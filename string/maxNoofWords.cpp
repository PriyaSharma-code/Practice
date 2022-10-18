/*2114. Maximum Number of Words Found in Sentences
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
       int res=0;
        for(auto i:sentences)
            res=max(res,(int)count(i.begin(),i.end(),' ')+1);
        return res;
    }
};

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        return max(s.count(" ") for s in sentences) + 1