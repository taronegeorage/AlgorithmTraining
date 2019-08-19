ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        for(auto pre = dummy; pre->next && pre->next->next;) {
            auto a =  pre->next, b = a->next;
            pre->next = b;
            a->next = b->next;
            b->next = a;
            pre = a;
        }
        return dummy->next;
    }
