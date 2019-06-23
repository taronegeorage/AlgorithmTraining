// leetcode 24
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return head;
        ListNode* p2 = head;
        ListNode* p1 = head->next;
        ListNode* pre = NULL;
        ListNode* tmp = NULL;
        while(p1 != NULL){
            p2->next = p1->next;
            p1->next = p2;
            if(pre != NULL)
                pre->next = p1;
            if(head == p2)
                head = p1;
            tmp = p1;
            p1 = p2;
            p2 = tmp;
            p2 = p2->next->next;
            pre = p1;
            if(p2 == NULL || p2->next == NULL)
                break;
            p1 = p1->next->next;
        }
        return head;
    }
};

// 4ms 93.59%
// 8.9MB 34.06%
