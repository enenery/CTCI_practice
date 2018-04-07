def lcs_length(x, y):
	m = len(x)
	n = len(y)
	b = [0 for i in range(1, n + 1)]
	c = [0 for i in range(n + 1)]
	
	for i in range(1, m):
		for j in range(1,n):
			if x[i] == y[j]:
				c[i, j] = c[i - 1, j - 1] + 1
				b[i, j] = "↖"
			elif c[i - 1, j] >= c[i, j - 1]:
				b[i, j] = "↑"
			else: 
				c[i, j] = c[i, j - 1]
				b[i, j] = "←"
	return c, b


arrow = '\u2196'
print(arrow)
