
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

	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		ListNode* curr = head;
		int len = 1;
		while (curr->next) {
			curr = curr->next;
			len++;
		}
		if (k > len) k = k % len;
		k = len - k;
		if (k == 0 || k == len) return head;
		ListNode* temp = head;
		int cnt = 1;
		while (cnt < k) {
			temp = temp->next;
			cnt++;
		}
		ListNode* newHead = temp->next;
		temp->next = nullptr;
		curr->next = head;
		return newHead;
	}
};