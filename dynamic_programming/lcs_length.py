def lcs_length(x, y):
	m = len(x)
	n = len(y)
	print("m = " + str(m))
	print("n = " + str(n))
	b = [[0 for i in range(m + 1)] for j in range(n + 1)]
	c = [[0 for i in range(m + 1)] for j in range(n + 1)]
	print("b = " + str(len(b)))
	print("c = " + str(len(c)))
	
	for i in range(1, m):
		for j in range(1, n):
			print("i = " + str(i))
			print("j = " + str(j))
			if x[i] == y[j]:
				c[i][j] = c[i - 1][j - 1] + 1
				b[i][j] = "↖"
			elif c[i - 1][j] >= c[i][j - 1]:
				c[i][j] = c[i - 1][j]
				b[i][j] = "↑"
			else: 
				c[i][j] = c[i][j - 1]
				b[i][j] = "←"
	return c, b

def print_lcs(b, x, i, j):
	print("i = " + str(i))
	print("j = " + str(j))
	if i == 0 or j == 0:
		return
	if b[i][j] == "↖":
		print_lcs(b, x, i - 1, j - 1)
		print(x[i])
	elif b[i][j] == "↑":
		print_lcs(b, x, i - 1, j)
	else:
		print_lcs(b, x, i, j - 1)

def print_matrix(x):
	for i in range(len(x)):
		for j in range(len(x)):
			print(x[i][j], end="")
		print("")

x = [' ', '1', '0', '0', '1', '0', '1', '0', '1']
y = [' ', '0', '1', '0', '1', '0', '1', '1', '0']

c, b = lcs_length(x, y)
print_matrix(b)
print_matrix(c)
print_lcs(b, x, len(x) - 1, len(y) - 1)
