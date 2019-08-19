// leetcode  142.
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
    ListNode *detectCycle(ListNode *head) {
        auto quick = head, slow = head;
        while(quick) {
            quick = quick->next;
            slow = slow->next;
            if(quick)
                quick = quick->next;
            else
                break;
            
            if(quick == slow) {
                quick = head;
                while(quick != slow) {
                    quick = quick->next;
                    slow = slow->next;
                }
                return quick;
            }
        }
        return quick;
    }
};

// 12ms 75.13%
// 9.7MB 97.62%
