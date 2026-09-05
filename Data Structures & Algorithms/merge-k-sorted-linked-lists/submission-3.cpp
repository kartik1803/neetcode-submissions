class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()) {

            ListNode* top = pq.top();
            pq.pop();

            if(head == NULL) {
                head = top;
                tail = top;
            }
            else {
                tail->next = top;
                tail = top;
            }

            if(top->next != NULL) {
                pq.push(top->next);
            }
        }

        return head;
    }
};
