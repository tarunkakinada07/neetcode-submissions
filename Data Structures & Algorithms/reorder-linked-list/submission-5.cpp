class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        // Reverse second half
        ListNode* curr = head2;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head2 = prev;

        // Merge alternately
        while (head1 != nullptr && head2 != nullptr) {

            ListNode* nxt1 = head1->next;
            ListNode* nxt2 = head2->next;

            head1->next = head2;
            head2->next = nxt1;

            head1 = nxt1;
            head2 = nxt2;
        }
    }
};
