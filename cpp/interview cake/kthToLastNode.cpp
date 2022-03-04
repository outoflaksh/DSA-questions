// WAF to return the kth to last node from a SLL given head and k

// two-pass, 
// calc the length then len - k and just reach this no. of steps
LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
    // return the kth to last node in the linked list
    if (k < 1) {
        throw invalid_argument("invalid");
    }
    
    int totalLen = 0;
    LinkedListNode* curr = head;
    
    while (curr != nullptr) {
        totalLen++;
        curr = curr->next_;
    }
    
    int finalPos = totalLen - k;
    curr = head;
    
    for (int i = 0; i < finalPos; i++) {
        curr = curr->next_;
    }
    
    return curr;
}



// one pass, make fast go k steps
// then start slow to step forward until fast reaches end
// this way slow steps for as much steps as fast has left
// and fast has len(list) - k steps left: which is what we want
LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
    // return the kth to last node in the linked list
    if (k < 1) {
        throw invalid_argument("invalid");
    }
    
    LinkedListNode* slow = head;
    LinkedListNode* fast = head;
    
    for (size_t i = 0; i < k ; i++) {
        if (!fast->next_) {
            throw invalid_argument("k > len(list)");
        }
        
        fast = fast->next_;
    }
    
    while (fast != nullptr) {
        fast = fast->next_;
        slow = slow->next_;
    }

    return slow;
}

// Time: O(N) & Space: O(1) for both

// note: both will take the same amt of steps to complete. 
// one-pass is not faster than the two-pass
// since, first one goes n steps then n-k 
// and second goes k steps then both the ptrs go n-k steps, effectively reaching same 
// however, it just may so happen that the second one is "slightly" faster,
// depending upon the caching mechanisms of the processor