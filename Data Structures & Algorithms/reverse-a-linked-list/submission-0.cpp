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
    ListNode* reverseList(ListNode* head) {
        ListNode* b = head;
        ListNode* a = nullptr;
        while(b!=nullptr){
            ListNode * tmp = a;
            a = b;
            b = b->next;
            a->next = tmp;
        }
        return a;
    }
};
