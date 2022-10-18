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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
           while(true)
        {
            ListNode* temp1=headA;
            ListNode* temp2=headB;
                if(temp1==NULL)
                break;
            while(temp2!=NULL)
            {
        if(temp1==temp2)
        {
            return temp1;
            break;
        }
        else
        {
          temp2=temp2->next;
        }
            }
        headA=headA->next;
        }
        return NULL;
    }
};
