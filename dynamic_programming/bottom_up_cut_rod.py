# 15.1 from Introduction to Algorithms
# O(n^2) solution for Rod Cutting problem
def bottom_up_cut_rod(p, n):
	r = [0 for i in range(n + 1)]
	s = [0 for i in range(n + 1)]
	for j in range(1, n + 1):
		q = -1
		for i in range(1, j + 1):
			if q < p[i] + r[j - i]:
				q = p[i] + r[j - i]
				s[j] = i
			r[j] = q
	return r, s

p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24]	
n = len(p) - 1

r, s = bottom_up_cut_rod(p, n)
print (p)
print (r)
print (s)

print("For " + str(n) + " inches of rod, the max value is: $" + str(r[n]))
print("if you split the rod in the following way: ")
while n > 0:
	print (str(s[n]) + " inches for $" + str(r[s[n]]))	
	n = n - s[n]
