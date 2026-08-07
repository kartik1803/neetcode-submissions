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
    void reorderList(ListNode* head) {
        if(head==NULL){
            return ;
        }
        vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n =ans.size();
        vector<int>finalans;
   int a = 0;
        int b = n - 1;

        while (a <= b) {
            finalans.push_back(ans[a++]);

            if (a <= b)
                finalans.push_back(ans[b--]);
        }
        temp = head;
        int i = 0;

        while (temp != NULL) {
            temp->val = finalans[i++];
            temp = temp->next;
        }


        
    }
};
