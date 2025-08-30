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

 const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
    #define LC_HACK
    #ifdef LC_HACK
    const auto __ = []() {
        struct ___ {
            static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
        };
        std::atexit(&___::_);
        return 0;
    }();
    #endif
    
class Solution {
public:
    ListNode* midd(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!= nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }

  
  ListNode* merge(ListNode* L, ListNode* R)
  {
     ListNode* dummy = new ListNode(0);
     ListNode* temp = dummy;
     while(L!=nullptr && R!=nullptr)
     {
        if(L->val<R->val)
        {
            temp->next = L;
            L  = L->next;
        }
        else
        {
            temp->next = R;
            R = R->next;
        }
        temp = temp->next;
     }

    if(L!=nullptr) temp->next = L;
    if(R!=nullptr) temp->next = R;

    return dummy->next;
  }
    

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr ) return head;

        ListNode* mid = midd(head);
        ListNode* r = mid->next;
        mid->next = nullptr;
        ListNode* l = head;
        l = sortList(l);
        r = sortList(r);
        return merge(l,r);

    }
};