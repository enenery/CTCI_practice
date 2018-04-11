def greedy_activity_selector(s, f):
	n = len(s)
	a = {0}
	newly_selected_activity = 0
	for i in range(1, n):
		if s[i] > f[newly_selected_activity]:
			a.add(i)
			newly_selected_activity = i
	return a


s = [0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
f = [0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]

a = greedy_activity_selector(s, f)
print(a)

