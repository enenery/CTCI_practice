def insertion_sort(arr):
	print(arr)
	for i in range(0,len(arr)-1):	
		j = i + 1;
		found = False
		while j > 0 and not found:
			if arr[j-1] > arr[j]:
				tmp = arr[j]
				arr[j] = arr[j-1]
				arr[j-1] = tmp
			else:
				found = True;
			j = j - 1;
	print(arr)
		

arr = [100, 32, 4, 2, 1]		
insertion_sort(arr)