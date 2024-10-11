/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* collisionPt(ListNode* temp1, ListNode* temp2, int d) {
        while( d != 0) {
            d--;
            temp2 = temp2->next;
        }
        while(temp1 != temp2) {
            temp1 = temp1 ->next;
            temp2 = temp2 ->next;
        }
        return temp1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = 0;
        ListNode* temp1 = headA;

        while (temp1 != NULL) {
            cnt1++;
            temp1 = temp1->next;
        }
        int cnt2 = 0;
        ListNode* temp2 = headB;

        while(temp2 != NULL) {
            cnt2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        if(cnt1 < cnt2) {
            return collisionPt(headA, headB, cnt2-cnt1);
        }
        else {
            return collisionPt(headB, headA, cnt1-cnt2);
        }
        
    }
};