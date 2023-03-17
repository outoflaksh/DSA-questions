def coinChange(coins, val):
    coins.sort(reverse=True)

    result = 0

    for coin in coins:
        if val % coin == 0:
            return result + val / coin
        result += val // coin
        val = val % coin


print(coinChange([25, 20, 10, 15, 5], 55))
