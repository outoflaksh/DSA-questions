// Given three vectors: takeOutOrders, dineInOrders, servedOrders, 
// write a function to check that my service is first-come, first-served. 
// i.e. the order of all order items from the first two vectors should be in the same order in the third one.
// Example: [1,2]; [3,4]; [1,3,2,4] should result in true as the order is preserved
// But [1,2]; [3,4]; [1,4, 2, 3] should give false as 4 comes before 3 => not in order
// none of the vectors are sorted in any order

#include <iostream>
#include <vector>

using namespace std;

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    // check if we're serving orders first-come, first-served
    int t = takeOutOrders.size(), d = dineInOrders.size(), s = servedOrders.size();
    
    int takeOutPt = 0, dineInPt = 0, servedPt = 0;
    
    // keep two pointers to track the first vectors & increment all if the curr in serve equals curr in any of the first vectors
    while (servedPt < s) {
        if (takeOutOrders[takeOutPt] == servedOrders[servedPt]) {
            takeOutPt++;
        }
        else if (dineInOrders[dineInPt] == servedOrders[servedPt]) {
            dineInPt++;
        }
        
        servedPt++;
    }
    
    // if we reached the end with them that means they are in order
    if (takeOutPt == t && dineInPt == d) {
     // need both to be in order
        return true;
    } else {
    	return false;
    }
}


int main() {
    const vector<int> takeOutOrders {1, 4, 5};
    const vector<int> dineInOrders {2, 3, 6};
    const vector<int> servedOrders {1, 2, 3, 4, 5, 6};
    cout << isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders) << endl; // 1 or true
}

// Time: O(N); Space: O(1)