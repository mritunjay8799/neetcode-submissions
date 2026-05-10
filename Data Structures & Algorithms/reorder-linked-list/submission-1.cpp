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
    void reorderList(ListNode* head) {
        // Find Middle element
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half of list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        slow->next = nullptr;

        // Merge both list alternatively
        ListNode* head1 = head;
        ListNode* head2 = prev;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        bool toSwitch = false;
        while(head1 && head2){
            if(!toSwitch){
                tail->next = head1;
                head1 = head1->next;
            }
            else{
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
            toSwitch = !toSwitch;
        }
        tail->next = head1 ? head1 : head2;
        head = dummy.next;
    }
};
