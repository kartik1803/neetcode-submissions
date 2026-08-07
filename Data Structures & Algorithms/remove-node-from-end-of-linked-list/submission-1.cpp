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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }

        vector<int> ans;
        ListNode* temp = head;

        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int k = ans.size();

        if(n > k){
            return head;
        }

        vector<int> finals;

        // Skip the (k-n)th index
        for(int i = 0; i < k; i++){
            if(i == k - n)
                continue;
            finals.push_back(ans[i]);
        }

        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;

        for(int x : finals){
            ListNode* node = new ListNode(x);

            if(head1 == NULL){
                head1 = node;
                tail1 = node;
            }
            else{
                tail1->next = node;
                tail1 = node;
            }
        }

        return head1;
    }
};
