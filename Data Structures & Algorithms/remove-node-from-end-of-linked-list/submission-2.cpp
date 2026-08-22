class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches the last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node
        slow->next = slow->next->next;

        return dummy.next;
    }
};