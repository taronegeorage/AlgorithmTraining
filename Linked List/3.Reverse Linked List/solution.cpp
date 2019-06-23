//leetcode 206

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
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* tmp = NULL;
        while(head != NULL){
            tmp = head->next;
            head->next = ans;
            ans = head;
            head = tmp;
        }
        return ans;
    }
};


// 4ms 99.76%
// 9.2MB 36.69%
