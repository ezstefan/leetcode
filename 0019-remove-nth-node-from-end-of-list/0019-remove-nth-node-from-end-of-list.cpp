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
    // Step 1: Calculate the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        // Step 2: Find the position from the start
        int positionFromStart = length - n;
        if (positionFromStart < 0 || positionFromStart >= length) {
            return head;  // Invalid k value, return the original list
        }
        
        // Step 3: If deleting the head node
        if (positionFromStart == 0) {
            ListNode* newHead = head->next;
            delete head;  // Free the memory of the old head
            return newHead;
        }

        // Step 4: Traverse to the node just before the node to delete
        temp = head;
        for (int i = 0; i < positionFromStart - 1; i++) {
            temp = temp->next;
        }

        // Step 5: Delete the node by adjusting pointers
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;  // Free the memory of the deleted node

        return head;  // Return the modified list
    }
};