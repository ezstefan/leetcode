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
    // Function to reverse a linked list.
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseLinkedList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    // Function to check if the linked list is a palindrome.
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;  // Return true for empty or single node list.
        }

        // Find the middle of the linked list using two pointers.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list.
        ListNode* newHead = reverseLinkedList(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        // Compare the first and second halves of the list.
        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(newHead);  // Restore the list before returning.
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseLinkedList(newHead);  // Restore the second half back to original.

        return true;  // The list is a palindrome.
    }
};
