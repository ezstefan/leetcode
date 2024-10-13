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
        if(head == NULL) {
            return head;
        }
        unordered_set<int> seen;
        ListNode* prevNode = NULL;
        ListNode* temp = head;

        while( temp != NULL) {
            if(seen.find(temp->val) != seen.end()) {
                ListNode* frontNode = temp->next;
                prevNode->next = frontNode;
                delete(temp);
                temp = frontNode;
            }
            else{
                seen.insert(temp->val);
                prevNode = temp;
                temp = temp->next; 
            }

        }
        return head;
        
    }
};