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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* current = head;

        while(current->next != nullptr){
            if(current->val == current->next->val){
                deleteNode(current);
            } else {
                current = current->next;
            }
        }

        return head;
    }
private:
    ListNode* deleteNode(ListNode* prev){
        auto* deleteMe = prev->next;
        auto* temp = prev->next->next;
        prev->next = temp;
        delete deleteMe;
        return prev;
    }
};