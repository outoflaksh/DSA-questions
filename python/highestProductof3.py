# given a list of ints (n>=3) find the highest product you can get from 3 values in it

# soln: since, there are only 3 ints, and we need to account for negatives too,
# we can only have either 0 or 2 negatives in the result.
# so we keep track of the prod of highest 2 numbers and lowest 2.
# and then for each current number we see if the prod with the prod of highest 2 or lowest 2
# is greater than the highest product of 3


def highestProductOf3(l: list):
    # keep track of the highest and lowest values

    highest = max(l[0], l[1])
    lowest = min(l[0], l[1])

    highestProdof2 = l[0] * l[1]
    lowestProdof2 = l[0] * l[1]

    maxProd = l[0] * l[1] * l[2]

    for i in range(2, len(l)):
        curr = l[i]

        maxProd = max(highestProdof2 * curr, lowestProdof2 * curr, maxProd)

        # updating the highest and lowest products
        highestProdof2 = max(curr * highest, curr * lowest, highestProdof2)
        lowestProdof2 = min(curr * highest, curr * lowest, lowestProdof2)

        # updating the highest and lowest
        highest = max(highest, curr)
        lowest = min(lowest, curr)

    return maxProd


print([1, 10, -5, 1, -100])  # 5000
print([-10, -10, 1, 3, 2])  # 300

# Time: O(N); Space: O(1)
