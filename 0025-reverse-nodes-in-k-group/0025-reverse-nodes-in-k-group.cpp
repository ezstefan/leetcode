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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while( temp != NULL) {
            ListNode* frontNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = frontNode;
        }
        return prevNode;
    }
    ListNode* getKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        k = k - 1;
        while(  temp != NULL && k > 0) {
            k--;
            temp = temp->next;

        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while( temp != NULL) {
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode == NULL) {
                if(prevNode != NULL) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseList(temp);
            if( temp == head) {
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
        }
};