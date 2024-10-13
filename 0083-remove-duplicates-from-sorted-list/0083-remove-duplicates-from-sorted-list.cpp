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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* frontNode = temp->next;

        while (frontNode != NULL) {
            if (temp->val == frontNode->val) {
                ListNode* duplicate = frontNode;
                frontNode = frontNode->next; 
                temp->next = frontNode;
                delete duplicate;  
            } else {
                temp = frontNode;
                frontNode = frontNode->next;
            }
        }
        return head;
    }
};
