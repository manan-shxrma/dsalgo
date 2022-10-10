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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next== nullptr){
            return NULL;
        }
        ListNode *slow = head ,*fast = head;
        while(fast != nullptr && fast->next != nullptr){
            if(slow != fast){
            slow = slow->next;
            }
            fast = fast->next->next;
        }
    
        slow->next = slow->next->next;

    
    return head;
        }
};
