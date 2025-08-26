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
   
    ListNode* fun(ListNode* list1,ListNode* list2)
    {
        ListNode* temp=list1;
        ListNode* ans = temp;
        list1 = list1->next;
      while(list1!=nullptr && list2!=nullptr)
      {
         if(list1->val<list2->val)
        {
         temp->next = list1;
         list1= list1->next;
        }
        else
        {
            temp->next = list2;
            list2 =  list2->next;
        }
        temp = temp->next;
      }
      if(!list1)
      {
        temp->next = list2;
      } 
      else
      {
         temp->next = list1;
      }

      return ans;
    }


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* temp;

        if(list1->val<=list2->val)
        {
          temp =  fun(list1,list2);
        }
        else
        {
           temp = fun(list2,list1);
        }

        return temp;

    }
};