/*
    Time complexity: O(N * T)
        For enQueue(): O(N)
        For deQueue(): O(1)
        For peek(): O(1)
        For isEmpty(): O(1)

    Space Complexity : O(N)

    Where 'N' is the maximum number of elements that are in the stack at any time.
    Where 'T' is the total number of queries which are performed.
*/

#include <stack>

class Queue {
    stack<int> *s1;
    stack<int> *s2;
public:
    Queue() {
        s1 = new stack<int>();
        s2 = new stack<int>();

    }
    // EnQueue item to the queue.
    void enQueue(int val) {
        // Move all elements from s1 to s2.
        while (!s1->empty()) {
            // To insert a value, first whole of the s1 is transferred to s2, then the new element is inserted in s1.
            s2->push(s1->top());
            s1->pop();
        }

        // Push item into s1.
        s1->push(val);

        // Push everything back to s1.
        while (!s2->empty()) {
            s1->push(s2->top());
            s2->pop();
        }


    }

    // Dequeue an item from the queue.
    int deQueue() {
        // If first stack is empty.
        if (s1->empty()) {
            return -1;
        }

        // Return top of s1.
        int tp = s1->top();
        s1->pop();
        return tp;
    }

    // Returns the Front element of the queue.
    int peek() {
        if (s1->empty()) {
            return -1;
        }

        return s1->top();
    }

    // Whether the queue is empty or not.
    bool isEmpty() {
        return (s1->empty());
    }

};