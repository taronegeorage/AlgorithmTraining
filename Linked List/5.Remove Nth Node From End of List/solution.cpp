// leetcode 19.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto pre = new ListNode(0);
        pre->next = head;

        auto first = pre, second = pre;
        while(n--) first = first->next;
        while(first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return pre->next;
    }
};

// 4ms 86.71%
// 8.6MB 75.00%
