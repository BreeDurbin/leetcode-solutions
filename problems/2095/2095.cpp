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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next){
            return nullptr;
        } 

        ListNode* hare=head->next;
        ListNode* tortoise=head;
        ListNode* prev_slow = nullptr;

        while(hare && hare->next){ 
            prev_slow=tortoise;
            tortoise=tortoise->next;
            hare=hare->next->next;
        }

        if(!hare){
            ListNode* m=tortoise->next;
            prev_slow->next = m;
            delete tortoise;
            return head;
        }else{
            ListNode* m=tortoise->next;
            tortoise->next = m->next;
            delete m;
            return head;
        }

        return head;
    }
};