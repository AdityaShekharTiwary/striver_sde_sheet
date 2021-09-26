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

    int length(ListNode* curr) {
        int len = 0;
        while (curr) {
            curr = curr->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next = nullptr, *prev = nullptr, *curr = head;
        int cnt = 0;
        while (curr && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if (next) {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};