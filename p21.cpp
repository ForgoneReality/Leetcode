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
    
    //thinking of doing um. case in which one list is empty is checked for
    //but afterwards never happens again. then we 
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        if (list1 == nullptr)//extra check?
        {\
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        //possibly need to hold the first winner for retur
        
        ListNode* head;
        if (list1->val <= list2->val)
        {
            head = list1;
        }
        else
            head = list2;
        while(true)
        {
            if (list1->val <= list2->val)
            {
                while(list1->next && (list1->next->val <= list2->val))
                {
                    list1 = list1->next;
                }
                
                ListNode* a = list1->next;
                list1->next = list2;
                if(a == nullptr)
                {
                    return head;
                }
                else
                {
                    list1 = a;
                }
            }
            else
            {
                while(list2->next && (list2->next->val < list1->val))
                {
                    list2 = list2->next;
                }
                
                ListNode* a = list2->next;
                
                list2->next = list1;
                if(a == nullptr)
                {
                    return head;
                }
                else
                {
                    list2 = a;
                }
            }
        }
        
        return head;
    }
};