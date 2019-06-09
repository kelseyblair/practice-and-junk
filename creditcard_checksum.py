#!usr/bin/python

def is_card_valid(number):
	str_num = str(number)
	slice_number = str_num[::2]
	slice_number_2 = str_num[1::2]
	slice_number = [int(slice_number[i])*2 for i in range(len(slice_number))]
	slice_number_2 = [int(slice_number_2[i]) for i in range(len(slice_number_2))]
	checksum = sum(slice_number_2)
	for num in slice_number:
		if num > 9:
			new_num = [int(str(num)[::][i]) for i in range(2)] #digit never has len > 2
			for elem in new_num:
				slice_number.append(elem)
	slice_number = [i for i in slice_number if i < 10]
	checksum += sum(slice_number)
	if checksum == 70:
		return True
	else:
		return False

def cardLuhnChecksumIsValid(n):
	r = [int(ch) for ch in str(n)][::-1]
	return (sum(r[0::2]) + sum(sum(divmod(d*2,10)) for d in r[1::2])) % 10 == 0

def michelChecksum(cc_number):
	return (sum((int(x) for x in ''.join([str(2*int(i)) for i in str(cc_number)[::2]])))+sum(int(y) for y in str(cc_number)[1::2])) % 10 == 0

card_number1 = 1234567890123456
card_number2 = 4417123456789113

print( card_number1, "valid? ", is_card_valid(card_number1) )
print( card_number2, "valid? ", is_card_valid(card_number2) )

print( card_number1, "valid? ", cardLuhnChecksumIsValid(card_number1) )
print( card_number2, "valid? ", cardLuhnChecksumIsValid(card_number2) )

print( card_number1, "valid? ", michelChecksum(card_number1) )
print( card_number2, "valid? ", michelChecksum(card_number2) )