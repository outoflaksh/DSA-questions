# Leetcode 187

from typing import List


def findRepeatedDnaSequences(s: str) -> List[str]:
    freq = {}
    n = len(s)
    ans = []

    for i in range(n - 10):
        sub = s[i : i + 10]
        if sub not in freq:
            freq[sub] = 0

        freq[sub] += 1

        if freq[sub] == 2:
            ans.append(sub)

    return ans


print(
    findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")
)  # ['AAAAACCCCC', 'CCCCCAAAAA']

# Time: O(N); Space: O(N)
