class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string,int> mpp;
        unordered_set <string> check;
        for(int i=0;i<list2.size();i++){
            mpp[list2[i]]=i;
            check.insert(list2[i]);
            }
        int res=INT_MAX;
        vector<string> ans;
        for(int i=0;i<list1.size();i++){
            if(check.count(list1[i])){
                if(res==(i+mpp[list1[i]])) ans.push_back(list1[i]);
                else if(res>(i+mpp[list1[i]])){
                    res=(i+mpp[list1[i]]);
                    ans.clear();
                    ans.push_back(list1[i]);
                }
            }

        }
        return ans;
    }
};