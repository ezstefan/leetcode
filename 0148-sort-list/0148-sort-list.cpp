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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* convertArrToLinkedList(vector<int>& arr){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        for(int i = 0; i<arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummyNode->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp1= list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(arr.begin(),arr.end());
        ListNode* head = convertArrToLinkedList(arr);
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next== NULL) {
            return head;
        }
        ListNode* middle = findMiddle(head); 

        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left,right);
    }
};