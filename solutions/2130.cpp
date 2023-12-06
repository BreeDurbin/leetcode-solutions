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

    int pairSum(ListNode* head) {
        ListNode *fast=head,*slow=head;
        int i = 0;
        while(fast&&fast->next){
            i++;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reversedHead = reverse(slow);

        int max_sum = 0;
        for(int j=0; j<i; j++){
            max_sum = max(max_sum, head->val + reversedHead->val);
            head = head->next;
            reversedHead = reversedHead->next;
        }
        return max_sum;
    }

    ListNode* reverse(ListNode* head){
        ListNode* newHead = nullptr;
        while(head){
             ListNode* next = head->next;
             head->next = newHead;
             newHead = head;
             head = next;
        }
        return newHead;
    }
};