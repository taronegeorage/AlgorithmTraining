// leetcode 83.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        auto dummy = new ListNode(0);
        dummy->next = head;
        while(head->next) {
            if(head->next->val == head->val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return dummy->next;
    }
    ListNode* deleteDuplicates2(ListNode* head) {
        auto first = head;
        while(head) {
            if(head->next && head->next->val == head->val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return first;
    }
};

// 8ms 97.69%
// 9.3MB 86.79%
