def top_down_cut_rod(p, n):
	if n == 0:
		return 0
	q = -1
	for i in range(1, n + 1):
		q = max(q, p[i] + top_down_cut_rod(p, n-1))
	return q;
	
p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24]	
n = len(p) - 1
n = 4

q = top_down_cut_rod(p, n)
print (q)