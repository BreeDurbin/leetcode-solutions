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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        auto left = head;
        auto right = getMid(head);
        auto temp = right->next;
        right->next = nullptr;
        right = temp;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }

private:
    ListNode* getMid(ListNode* head){
        auto &slow = head, fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode front(0);
        ListNode*  back = &front;
        while(left && right){
            if(left->val < right->val){
                back->next = left;
                left = left->next;
            } else {
                back->next = right;
                right = right->next;
            }
            back = back->next;
        }
        if(left){
            back->next = left;
        }
        else if(right){
            back->next = right;
        }
        
        return front.next;
    }


};