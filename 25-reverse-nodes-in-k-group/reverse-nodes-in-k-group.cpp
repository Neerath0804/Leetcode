class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Check if there are at least k nodes to reverse
        while (cnt < k) {
            if (temp == NULL) return head;
            temp = temp->next;
            cnt++;
        }

        // Reverse next groups first
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reverse current group
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        // ✅ Return new head of this reversed group
        return prevNode;
    }
};
