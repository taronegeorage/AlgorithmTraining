class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode pre(0);
        pre.next = head;
        ListNode* l1 = &pre;
        ListNode* l2 = head;
        while(l2 != NULL && l2->next != NULL){
            ListNode* nextStart = l2->next->next;
            l1->next = l2->next;
            l2->next->next = l2;
            l2->next = nextStart;
            l1 = l2;
            l2 = l2->next;
        }
        return pre.next;
    }
};

// 4ms/0ms 93.59%/100%
// 8.8MB 52.79%
