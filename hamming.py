def count_bits(num): #slowest
	count = 0
	while num:
		num &= num - 1
		count += 1
	return count

def count_bits2(num): #probably also slowest
	count = 0
	while num > 0:
		if( (num&1) == 1):
			count += 1
		num >>= 1
	return count


# other methods, minus the obvious look-up table method, because it's just too long

def popcount_py(x): #second fastest
    return bin(x).count("1")

def popcount(x): #fastest
    x -= (x >> 1) & 0x5555555555555555
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f
    return ((x * 0x0101010101010101) & 0xffffffffffffffff ) >> 56