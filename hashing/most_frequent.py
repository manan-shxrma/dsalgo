def maxFreq(arr, n):
	
	# Using moore's voting algorithm
	res = 0
	count = 1
	
	for i in range(1, n):
		if (arr[i] == arr[res]):
			count += 1
		else:
			count -= 1
		
		if (count == 0):
			res = i
			count = 1
		
	return arr[res]

# Driver code
arr = [ 40, 50, 30, 40, 50, 30, 30 ]
n = len(arr)
freq = maxFreq(arr, n)
count = 0

for i in range (n):
		if(arr[i] == freq):
			count += 1
		
print("Element ", maxFreq(arr , n),
	" occurs ", count, " times")

# This code is contributed by shivanisinghss2110
