def cheapest_cost(prices):
	cur = prev = 0
	print(prices)
	for cost in prices:
		cur, prev = cost + min(cur, prev), cur

	return min(cur, prev)

prices = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
print(cheapest_cost(prices))
