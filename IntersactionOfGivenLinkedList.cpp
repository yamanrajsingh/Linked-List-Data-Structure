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

          // ListNode* A = headA;
        // ListNode* B = headB;
        // while(A!=B)
        // {
        //   A = (A==nullptr ? headB : A->next);
        //   B = (B==nullptr ? headA : B->next);
        // }
        // return A;
        
        if(headA == nullptr || headB == nullptr) return nullptr;
        set<ListNode*> s;
        while(headA!=nullptr)
        {
            s.insert(headA);
            headA = headA->next;
        }
        while(headB!=nullptr)
        {
            if(s.find(headB)!=s.end())  return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};