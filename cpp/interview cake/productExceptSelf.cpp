// given an array print an array that contains the product of all other integers except self
// cannot use division

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// idea is to just calc the prod of all ints that precede a specific int
//  and then the prod of all ints after and then multiply them
vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int> &intVector)
{
    // make a vector with the products
    int n = intVector.size();

    if (n <= 1)
        throw invalid_argument("Nope!");

    vector<int> prods;
    int productSoFar = 1;

    for (int i = 0; i < n; i++)
    {
        prods.push_back(productSoFar);
        productSoFar *= intVector[i];
    }

    productSoFar = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        prods[i] *= productSoFar;
        productSoFar *= intVector[i];
    }

    return prods;
}

int main()
{
    vector<int> arr{1, 7, 3, 4};
    vector<int> prodExceptSelf = getProductsOfAllIntsExceptAtIndex(arr);
    for (int i : prodExceptSelf)
    {
        cout << i << ", ";
    }
    cout << "" << endl; // 84, 12, 28, 21,
}

// Time: O(N); Space: O(N)