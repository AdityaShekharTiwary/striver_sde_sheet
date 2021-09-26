/*
TC : O(N)
SC : O(1)
Approach : Reverse the list remove Kth node from the beginning again reverse the list then return the head

*/




/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverse(LinkedListNode<int>* &temp) {
    LinkedListNode<int>* curr = temp, *prev = nullptr, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;
    return temp;
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int n)
{
    if (n == 0) return head;
    if (!head) return nullptr;
    if (!head->next && n == 1) return nullptr;
    LinkedListNode<int>* temp = head;
    LinkedListNode<int>* newHead = reverse(temp);
    LinkedListNode<int>* curr = newHead;
    int cnt = 1;
    if (n == 1) {
        newHead = newHead->next;
    }
    while (cnt < n - 1) {
        curr = curr->next;
        cnt++;
    }
    curr->next = curr->next->next;
    return reverse(newHead);
}