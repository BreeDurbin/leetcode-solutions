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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        
        ListNode *left = new ListNode(0, nullptr), *right = new ListNode(0, nullptr), *start = left, *mid = right;

        while(head){
            if(head->val < x){//left
                left->next = head;
                left = left->next;
            }
            else{ //right
                right->next = head;
                right = right->next;
            }
            if(!head->next){
                left->next = mid->next;
                right->next = nullptr;
                break;
            }
            head = head->next;
        }

        return start->next;
    }
};