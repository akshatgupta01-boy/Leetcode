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
        if(head == NULL || head -> next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* right = slow -> next;
        slow -> next = NULL;
        ListNode* left = sortList(head);
        right = sortList(right);
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(left && right){
            if(left -> val <= right -> val){
                tail -> next = left;
                left = left -> next;
            }
            else{
                tail -> next = right;
                right = right -> next;
            }
            tail = tail -> next;
        }
        tail -> next = left ? left : right;
        return dummy.next;
    }
};