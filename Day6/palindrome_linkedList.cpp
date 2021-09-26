/*
TC : O(N)
SC : O(1)
Approach : Find middle then reverse then check for palindrome




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

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* &head) {
        ListNode* curr = head, *prev = nullptr, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* midHead = reverse(mid);
        ListNode* curr = head;
        while (curr && midHead) {
            if (curr->val != midHead->val) return false;
            curr = curr->next;
            midHead = midHead->next;
        }
        return true;
    }
};