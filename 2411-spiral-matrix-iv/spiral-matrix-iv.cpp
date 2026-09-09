/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        vector<vector<int>> matrix(m,vector<int>(n));
        while(top<=bottom && right>=left){
            for(int i=left;i<=right;i++){
                matrix[top][i]=head?head->val:-1;
                if(matrix[top][i]!=-1) head=head->next;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=head?head->val:-1;
               if(matrix[i][right]!=-1) head=head->next;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=head?head->val:-1;
                    if(matrix[bottom][i]!=-1) head=head->next;
                }
                bottom--;
            }
            if(right>=left){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=head?head->val:-1;
                    if(matrix[i][left]!=-1) head=head->next;
                }
                left++;
            }
        
        }
        return matrix;
    }
};