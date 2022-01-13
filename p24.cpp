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
    ListNode* swapPairs(ListNode* head)
    {
        if (!head)
        {
            return nullptr;
        }
        else if (head->next == nullptr)
        {
            return head;
        }
        ListNode* holdme = head->next; //this will given us beginning of answer
        ListNode* second = holdme;

        while (head && second)
        {
            // // ListNode* nextup = swapFirstTwo(head);
            // // head->next = nextup;
            // // if(nextup != nullptr)
            // //     head = head->next;
            // else
            //     break;
            ListNode* third = head->next->next;
            if (third && third->next)
                head->next = third->next;
            else
                head->next = third;
            second->next = head;
            head = third;
            if (third)
                second = third->next;
            else
                second = nullptr;

        }

        return holdme;
    }
};