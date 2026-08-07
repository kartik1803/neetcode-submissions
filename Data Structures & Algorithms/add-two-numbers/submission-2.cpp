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
void finalans(ListNode*&head1,ListNode*&tail1,int carry){
    ListNode*insert=new ListNode(carry);
    if(head1==NULL){
        head1=insert;
        tail1=insert;

    }
    else{
        tail1->next=insert;
        tail1=insert;
    }

}

ListNode*addup(ListNode*l1,ListNode*l2){
    int carry =0;
    ListNode*head1=NULL;
    ListNode*tail1=NULL;
    while(l1!=NULL||l2!=NULL||carry!=0){
        int n1=0;
        if(l1!=NULL){
            n1=l1->val;
            l1=l1->next;
        }
        int n2=0;
        if(l2!=NULL){
            n2=l2->val;
            l2=l2->next;
        }
        int sum =n1+n2+carry;
        int digit=sum%10;
        carry=sum/10;
        finalans(head1,tail1,digit);
            }
            return head1;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1==NULL){
        return l2;
       } 
       if(l2==NULL){
        return l1;
       }

       ListNode*ans =addup(l1,l2);
       return ans ;
    }
};
