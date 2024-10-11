/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || !head || head->next==nullptr) return head;
        int i=0;
        ListNode *dummy = new ListNode(0); 
        ListNode *cur = head, *prev = nullptr, *next = head->next, *lp = dummy;
        dummy->next = head;

        for(int i = 0; i < left - 1; i++){
            lp = cur;
            cur = cur->next;
        }

        for(int i=0; i < right - left + 1; i++){
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

        }

        lp->next->next = cur;
        lp->next = prev;

        return dummy->next;
    }
};
