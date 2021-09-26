/*
TC : O(N)
SC : O(1)



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

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                flag = true;
                break;
            }
        }
        if (!flag) return nullptr;
        ListNode* curr = head;
        while (curr && slow) {
            if (curr == slow) return curr;
            curr = curr->next;
            slow = slow->next;

        }
        return nullptr;
    }
};