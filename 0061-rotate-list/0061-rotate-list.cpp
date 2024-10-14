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
    ListNode* findTail(ListNode* head) {
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        return tail;
    }

    int findLength(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;  
        
        ListNode* tail = findTail(head);
        int length = findLength(head);

        if (head == NULL || head->next == NULL || k % length == 0) {
            return head;
        }

        tail->next = head;  
        int end = length - (k % length);

        ListNode* temp = head;
        while (temp != NULL && end > 0) {  
            end--;
            if (end > 0) temp = temp->next;  
        }

        ListNode* newHead = temp->next;  
        temp->next = NULL;  
        
        return newHead;  
    }
};
