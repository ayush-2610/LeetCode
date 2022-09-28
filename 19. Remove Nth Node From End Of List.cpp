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
   // ALGO - first calculate size of linked list by slow and fast pointer, then get to the node before to the node to be deleted,
    // then do operations and return head. Also check the condition that head isnt the node to be deleted
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* slow = head;
      ListNode* fast = head;
        int size = 1;
      while(fast!=NULL){
          if(fast->next==NULL) {
              size = size * 2 - 1;
              break;
          }
          if(fast->next->next==NULL) {
              size = size * 2;
              break;
          }
          slow = slow->next;
          size++;
          fast = fast->next->next;
      }
        if(size==n){
            return head->next;
        }
        ListNode* temp = head;
        
        for(int i=2; i<size-n+1; i++){
            temp=temp->next;
        }
        
        ListNode* prev = temp;
        ListNode* nxt = temp->next->next;
        temp = temp->next;
        prev->next = nxt;
        // free(temp);
        return head;
        
    }
};