# primenumbers.py

which_prime = input("What prime do you want? ")

def find_prime(num):

	if num < 1:
		return False
	prime_count=1
	i=0
	while prime_count <= num:
		i = i + 1
		if is_prime(i)==True:
			# print(str(i) + " is a prime")
			prime_count = prime_count + 1
	return i 

		


def is_prime(n):
	if n <= 1:
		return False
	elif n <= 3:
		return True
	elif n%2==0 or n%3==0:
		return False
	i = 5
	while i*i <= n:
		if n%i==0 or n%(i+2)==0:
			return False
		i=i+6
	return True



# print(str(which_prime) + " is prime? " + str(is_prime(which_prime)))
print("The prime at position " + str(which_prime) + " is " + str(find_prime(which_prime)))

