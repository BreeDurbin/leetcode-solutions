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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head || !head->next) return nullptr;
        int n = 0;
        ListNode* cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        
        if(n==k) return head->next;

        cur = head;
        for(int i=0; i<n-k-1; i++){
            cur = cur->next;
        }

        cur->next = cur->next->next;

        return head;
    }
};