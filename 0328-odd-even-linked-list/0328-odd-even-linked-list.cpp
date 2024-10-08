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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> arr;  // Use a vector to store values
        ListNode* temp = head;

        // Collect odd indexed nodes
        while(temp != NULL) {
            arr.push_back(temp->val);  // Add node's value
            if(temp->next != NULL) {
                temp = temp->next;  // Move to the next node
            }
            if(temp != NULL) {
                temp = temp->next;  // Move to the next odd indexed node
            }
        }

        // Collect even indexed nodes
        temp = head->next;  // Start from the first even indexed node
        while(temp != NULL) {
            arr.push_back(temp->val);  // Add node's value
            if(temp->next != NULL) {
                temp = temp->next;  // Move to the next node
            }
            if(temp != NULL) {
                temp = temp->next;  // Move to the next even indexed node
            }
        }

        // Update the linked list with collected values
        int i = 0;
        temp = head;
        while(temp != NULL) {
            temp->val = arr[i];  // Update node's value
            i++;
            temp = temp->next;  // Move to the next node
        }

        return head;  // Return the modified list
    }
};