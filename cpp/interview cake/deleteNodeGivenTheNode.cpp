// WAF to delete a node from a SLL given the ptr to that node
#include <iostream>
#include <stdexcept>

using namespace std;

// soln: instead of the traditional method to delete by traversing,
// we dont just exchange the values of the node ahead and transfer the
// next nodes next chain to the current one: effectively deleting it

void deleteNode(LinkedListNode* nodeToDelete)
{
    if (nodeToDelete == nullptr) return;
    
    LinkedListNode *nextNode = nodeToDelete->next_;
    
    if (nextNode) {
        nodeToDelete->intValue_ = nextNode->intValue_;
        nodeToDelete->next_ = nextNode->next_;
        delete nextNode;
    } else {
        throw invalid_argument("not possible");
    }
}

// Time & Space: O(1)


// note: the soln eventhough is amazing and clever, it's imperfect
// such a code can cause side-effects and bugs.
// for ex, if there is a var in the code referencing the node being deleted,
// it would then have a diff value because the node was modified
// and that could be an unexpected value for it and cause bugs