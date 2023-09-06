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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        ListNode* head = new ListNode();
        ListNode* current = head;
        int carry = 0;
        bool initializeSummedStart = true;
        int sum = 0;


        while(l1 != nullptr || l2 != nullptr || carry != 0){

            if(l1 != nullptr && l2 != nullptr){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != nullptr && l2 == nullptr) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else if(l1 == nullptr && l2 != nullptr){
                sum = l2->val + carry;
                l2 = l2->next;
            } else {
                sum = carry;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            
        }

        return head->next;

    }

};