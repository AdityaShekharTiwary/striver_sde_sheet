/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head, *temp = nullptr;
        while (curr) {
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        while (curr) {
            curr->next->random = (curr->random) ? curr->random->next : curr->random;
            curr = curr->next->next;

        }
        Node* original = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        while (original && copy) {
            original->next = original->next->next;
            copy->next = (copy->next) ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }
        return newHead;
    }
};