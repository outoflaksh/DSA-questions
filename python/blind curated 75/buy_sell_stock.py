def maxProfit(prices):
    left, right = 0, 1
    profit = 0

    while right < len(prices):
        # update left to be the min of the pointers
        if prices[right] < prices[left]:
            left = right
        else:
            # calc profit at all possible right vals
            profit = max(profit, prices[right] - prices[left])

        right += 1

    return profit


print(maxProfit([7, 1, 4, 6, 5]))  # 5
print(maxProfit([7, 6, 5, 4]))  # 0
print(maxProfit([9, 3, 6, 1, 3]))  # 3
