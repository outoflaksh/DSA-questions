// given an array/vector, perform an in-place shuffle of items in it

#include <iostream>
#include <random>
#include <vector>

using namespace std;

size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}

// soln: fill the array one by one by choosing a random int from the array
// for in-place we can swap the item at the random index with the one we are filling
// (also called the fisher-yates algorithm or knuth shuffle)

void shuffle(vector<int>& theVector)
{
    // shuffle the input in place
    int n = theVector.size();
    for (int i = 0; i < n; i++) {
        int randIdx = getRandom(i, n-1);
        
        if (randIdx != i) {
            swap(theVector[i], theVector[randIdx]);
        }
    }

}

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    shuffle(arr);

    for (int i : arr) {
        cout << i << ", ";
    }

    cout << endl; // a random ordering
}

// Time: O(N); Space: O(1)