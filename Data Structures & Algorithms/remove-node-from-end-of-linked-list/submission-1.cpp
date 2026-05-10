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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = slow;
        if(slow->next == nullptr && n >= 1)
            return NULL;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(prev != nullptr)
            prev->next = slow->next;
        else
            head = slow->next;
        slow->next = nullptr;
        return head;
    }
};
