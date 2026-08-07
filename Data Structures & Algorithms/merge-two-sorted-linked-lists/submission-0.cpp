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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        vector<int>ans1;
        vector<int>ans2;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        while(temp1!=NULL){
ans1.push_back(temp1->val);
temp1=temp1->next;
        }
        while(temp2!=NULL){
            ans2.push_back(temp2->val);
            temp2=temp2->next;
        }
        
        vector<int>ans;
        int i=0;
        int j=0;
        int n =ans1.size();
        int m =ans2.size();

        while(i<n&&j<m){
            if(ans1[i]<=ans2[j]){
                ans.push_back(ans1[i++]);
                
            }
            else{
                ans.push_back(ans2[j++]);
            }
        }
        while(i<n){
            ans.push_back(ans1[i++]);

        }
        while(j<m){
            ans.push_back(ans2[j++]);
        }

        ListNode*head1=NULL;
        ListNode*tail1=NULL;
        for(int i=0;i<ans.size();i++){
            ListNode*insert=new ListNode(ans[i]);
            if(head1==NULL){
                head1=insert;
                tail1=insert;
            }
            else{
                tail1->next=insert;
                tail1=insert;
            }
        }
        return head1;

    }
};
