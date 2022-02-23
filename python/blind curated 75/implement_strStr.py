# Return the index of first occurence of needle in haystack
# -1 if needle not in haystack & 0 if length(needle) = 0


def strStr(haystack: str, needle: str) -> int:
    subLen = len(needle)

    for i in range(0, len(haystack) - subLen + 1):
        if haystack[i : i + subLen] == needle:
            return i

    return -1


print(strStr("hello", "ll"))  # 2
print(strStr("hello", "k"))  # -1
print(strStr("hello", ""))  # 0
