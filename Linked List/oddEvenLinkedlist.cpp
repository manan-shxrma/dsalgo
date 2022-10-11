struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)// for edge case when case is []
        {
            return 0;
        }
       ListNode* ptr1 =head;
        ListNode* ptr2=head->next;
        ListNode* start =ptr2;
        
      
       while(ptr2!=NULL && ptr2->next!=NULL  )
        { 
           ptr1->next = ptr1->next->next;
            ptr2->next=ptr2->next->next;
           ptr1 = ptr1->next;
            ptr2=ptr2->next;
           }
        ptr1->next = start;
        return head;
    }
    
};
