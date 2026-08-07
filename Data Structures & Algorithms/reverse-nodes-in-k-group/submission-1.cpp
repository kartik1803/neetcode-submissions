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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt<k){
            return head;

        }

        cnt=0;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*fwd=NULL;
        while(curr!=NULL&&cnt<k){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
            cnt++;
        }
        if(cnt==k){
            head->next=reverseKGroup(curr,k);
        }
        return prev;

    }
};
