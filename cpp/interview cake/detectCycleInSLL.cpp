// WAF to find out if a cycle exists in a linked list

#include <iostream>

using namespace std; 

// approach here is to use two pointers: one fast and one slow.
// this comes from the insight that if two people were running in a loop
// at different speeds, the fast one will eventually catch up with the slow one


bool containsCycle(const LinkedListNode* firstNode)
{
    // check if the linked list contains a cycle
    const LinkedListNode* slow = firstNode;
    const LinkedListNode* fast = firstNode;
    
    while (fast != nullptr && fast->next_) {
        slow = slow->next_;
        fast = fast->next_->next_;
        
        if (slow == fast) {
            return true;
        }
    }
    

    return false;
}

// Time: O(N) & Space: O(1)