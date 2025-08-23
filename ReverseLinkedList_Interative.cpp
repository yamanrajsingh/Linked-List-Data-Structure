
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head== nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nest = nullptr;

        while(curr!=nullptr)
        {
         nest = curr->next;
         curr->next = prev;
          prev = curr;
         curr= nest;
        }
        head= prev;
        return head;
    }
};