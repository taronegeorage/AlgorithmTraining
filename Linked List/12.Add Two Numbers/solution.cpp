// leetcode 2.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ans = new ListNode(-1), tmp = ans;
        int sum = 0;
        while(l1 || l2) {
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            tmp->next = new ListNode(sum % 10);
            sum /= 10;
            tmp = tmp->next;
        }
        if(sum == 1) tmp->next = new ListNode(1);
        
        return ans->next;
    }
};

