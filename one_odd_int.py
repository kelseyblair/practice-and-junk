"""
You have a very large array of integers. One of the integers appears an odd number of times, 
and all the rest appear an even number of time. Write effecient code to find the integer 
with the odd count.
"""



def find_odd_int(big_arr):
	result = 0 #Will this work if zero is in the array? I don't think so..

	#for size of array, iterate through and xor numbers with result
	for i in xrange(0,len(big_arr)):
		result = result ^ big_arr[i]

	return result

#some large array. 10 is the odd numbered number (should be)
arr = [1,1,2,10,10,2,1,1,1,5,5,1,2,2,2,10,10,2,2,1,1,2,2,2,5,5,5,10,10,5,5,1,1,5,5,5,5,5,2,2,10,10,1,1,10,10,2,2,10,5,5]

print( find_odd_int(arr) )


"""
Explanation:
Arg 1	Arg 2	Result
A		B		C
B		C		A
A		C		B
So to do the trick, we XOR A and B, and store C in A, destroying the original A.  
We then XOR B and C which gives us A back, which we store in B.  We then XOR A 
and C which gives us B back that we can store in A again.

The above is for swapping to numbers, A and B, without using temporary storage.

The same idea works for finding the odd number out. Let’s say we’re given the 
following array: [1, 2, 3, 1, 2, 3, 1]. If  we XOR all the elements in this 
array the result is 1^2^3^1^2^3^1 = 1. Because the numbers 2 and 3 will be XORed 
with themselves 1 time, producing 0. And the number 1 will be XORed with itself 2 
times, resulting in its own value. So, the overall result of the XOR operations 
is the number 1, odd occurring element in the array.

"""