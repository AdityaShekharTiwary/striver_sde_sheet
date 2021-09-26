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

    int findLength(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if (!head1 || !head2) return nullptr;
        int la = findLength(head1);
        int lb = findLength(head2);

        if (la > lb) {
            int diff = la - lb;
            while (diff--) {
                head1 = head1->next;
            }
        }
        else {
            int diff = lb - la;
            while (diff--) {
                head2 = head2->next;
            }
        }

        while (head1 && head2) {
            if (head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return nullptr;
    }
};