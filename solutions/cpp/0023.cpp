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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto list : lists){
            while(list){
                q.push(list->val);
                list = list->next;
            }
        }
        ListNode * dummy = new ListNode(0);
        ListNode * cur = dummy;
        while(!q.empty()){
            cur->next = new ListNode(q.top());
            q.pop();
            cur = cur->next;
        }
        return dummy->next;
    }
};
