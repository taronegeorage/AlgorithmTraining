//leetcode 92. 
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto a = dummy, b = dummy;
        for(int i = 0;  i < n; i++) {
            if(i < m-1)
                a = a->next;
            b = b->next;
        }
        auto c = b->next, tmp = a->next;
        // for(auto d = tmp; d=d->next; d!=b) {
        //     auto cur = d->next;
        //     cur->next = d;
        //     d = cur;
        // }
        for(auto p = tmp, q =tmp->next; q!=c;) {
            auto cur = q->next;
            q->next = p;
            p=q;q=cur;
        }
        a->next = b;
        tmp->next = c;
        return dummy->next;
    }
    
};

// 4ms 68.01%
// 8.5MB 100%
