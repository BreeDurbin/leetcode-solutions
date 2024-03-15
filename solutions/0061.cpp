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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode *new_end = head, *old_end = head;

        int n=1;
        while(old_end->next){
            old_end = old_end->next;
            n++;
        }
        old_end->next = head;

        //reduce the size of k so that it only rotates size of list times
        int smol_k = k % n;

        //rotate head forward to smol_k
        for(int i=0; i< n - smol_k - 1; i++){
            new_end = new_end->next;
        }
        head = new_end->next;

        //setup new end
        new_end->next = nullptr;

        return head;
    }
};