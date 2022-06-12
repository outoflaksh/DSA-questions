// given a sorted array of integers, return a sorted array of all values squared

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int arr[] = {-9, -1, 2, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result[n];


    // left and right pointers
    int left = 0, right = n - 1, idx = n - 1;


    // keep comparing the pointers to check for larger absolute values
    // and add the sqaure of the larger one at the end of the result array
    while (left <= right){
        if (abs(arr[left]) > abs(arr[right])){
            result[idx] = arr[left]*arr[left];
            left++;
        } else {
            result[idx] = arr[right]*arr[right];
            right--;
        }

        idx--;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

}

// Space: O(n); Time: O(n)