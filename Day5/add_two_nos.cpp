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

        int sum = 0, carry = 0;
        ListNode* head = nullptr, *curr = nullptr;
        while (l1 || l2) {
            int a = (l1) ? l1->val : 0;
            int b = (l2) ? l2->val : 0;

            sum = carry + a + b;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;

            if (!head) {
                head = new ListNode(sum);
                curr = head;
            }
            else {
                curr->next = new ListNode(sum);
                curr = curr->next;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return head;
    }
};