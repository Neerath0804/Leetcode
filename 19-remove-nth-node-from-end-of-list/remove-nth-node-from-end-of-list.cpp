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
        if(head == NULL || head->next == NULL) 
        {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while( n > 0 && fast != nullptr)
        {
            fast = fast->next;
            n--;
        }
        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* curr = slow->next ;
        slow->next = slow->next->next;
        delete curr;
        return temp;
    }
};