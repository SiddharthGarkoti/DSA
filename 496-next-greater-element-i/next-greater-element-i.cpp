class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> mapp;
        stack <int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && !(st.top()>nums2[i])) st.pop();
            if(st.empty()) mapp[nums2[i]]=-1;
            else{
                 mapp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> res(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            res[i]=mapp[nums1[i]];
        }
        return res;
    }
};