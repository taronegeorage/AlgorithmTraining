// leetcode 61.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        int len = 1;
        auto first = head, second = head, tmp = head;
        while(tmp = tmp->next)
            len++;
        k = k % len;
        while(k--) first = first->next;
        while(first->next) {
            first = first->next;
            second = second->next;
        }
        first->next = head;
        head = second->next;
        second->next = NULL;

        return head;
    }
};

//8ms 80.99%
//9MB 66.67%
