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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;

        int carry = 0;
        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;

            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            current->next = newNode;
            current = current->next;
        }

        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            current->next = newNode;
        }

        return reverseLL(dummyNode->next);
    }
};
