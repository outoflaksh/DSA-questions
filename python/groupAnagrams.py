# Leetcode 49


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_map = {}

        for s in strs:
            sorted_str = str(sorted(s))
            if sorted_str not in sorted_map:
                sorted_map[sorted_str] = []
            sorted_map[sorted_str].append(s)

        r = []
        for i in sorted_map:
            r.append(sorted_map[i])

        return r
