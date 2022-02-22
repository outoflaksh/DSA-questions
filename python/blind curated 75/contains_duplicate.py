# Leetcode 217


def containsDuplicate(nums: list) -> bool:
    unique = set()

    for i in nums:
        if i in unique:
            return True
        unique.add(i)

    return False


print(containsDuplicate([1, 2, 3, 1]))  # True
print(containsDuplicate([1, 2, 3]))  # False
