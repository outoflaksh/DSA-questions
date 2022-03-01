// given an array/vector of scores (ints) and a certain highest possible score
// WAF to return a sorted scoreArray (decreasing order); 
// the algorithm should take less than O(N*LogN) time

#include <iostream>
#include <vector>

using namespace std;

// since we do have a max, we can use a counting approach
// make another array where the indices represent the score and 
// the value representing its frequency
// then do an in-order walk through the counts,
// add the indices the number of times they appear

vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // sort the scores in O(n) time
    vector<int> counts(highestPossibleScore);
    
    for (int i : unorderedScores) {
        counts[i] += 1;
    }
    
    vector<int> sorted;
    
    for (int i = highestPossibleScore; i >= 0 ; i--) {
        for (int j = 0; j < counts[i]; j++) {
            sorted.push_back(i);
        }
    }

    return sorted;
}

int main() {
	const vector<int> unsortedScores {37, 89, 41, 65, 91, 53};
	const int HIGHEST_POSSIBLE_SCORE = 100;

	vector<int> sortedScores = sortScores(unsortedScores, HIGHEST_POSSIBLE_SCORE);
	// sortedScores: [91, 89, 65, 53, 41, 37]

	for (int i : sortedScores) {
		cout << i << " ";
	}
	
	cout << endl;
}