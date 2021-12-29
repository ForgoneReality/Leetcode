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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer = new ListNode();
        ListNode *head = answer;
        bool c = false;
        while (l1 && l2) {
            int num = c + l1->val + l2->val;
            c = false;
            if (num > 9)
            {
                num = num-10;
                c = true;
            }
            answer->val=num;
            if ((l1->next) && (l2->next))
            {
                answer->next = new ListNode();
                answer = answer->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        cout << head->val;
        ListNode* abc;
        if (l1)
        {
            abc = l1;
        }
        else if (l2)
        {
            abc = l2;
        }
        else
        {
            if (c)
            {
                answer->next = new ListNode();
                answer->next->val = 1;
            }
            return head;
        }
        if (c == false)
        {
            answer->next = abc;
        }
        else
        {
            while (abc->val == 9)
            {
                answer->next = new ListNode();
                answer = answer->next;
                if(abc->next == nullptr)
                {
                    answer->next = new ListNode();
                    answer->next->val = 1;
                    return head;
                }
                else
                {
                    abc = abc->next;
                }
            }
            answer->next = new ListNode();
            answer = answer->next;
            answer->val = 1 + abc->val;
            answer->next = abc->next;
        }
        return head;
        
    }
};