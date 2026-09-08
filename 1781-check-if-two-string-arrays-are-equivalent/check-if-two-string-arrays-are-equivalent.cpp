class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1="";
        string w2="";
        for(string sh:word1) w1+=sh;
        for(string sh:word2) w2+=sh;
        return w1==w2;
    }
};