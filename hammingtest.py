# hammingtest.py

import unittest

import hamming

class hamming_test1(unittest.TestCase):
	""" Tests count_bits, count_bits2, popcount_py, and popcount in hamming.py """

	def test_countbits_num7_3bits(self):
		"""test for 3 bits total set in 7"""
		self.assertEqual(hamming.count_bits(7), 3)

	def test_countbits2_num7_3bits(self):
		"""test for 3 bits total set in 7"""
		self.assertEqual(hamming.count_bits2(7), 3)

	def test_popcountpy_num7_3bits(self):
		"""test for 3 bits total set in 7"""
		self.assertEqual(hamming.popcount_py(7), 3)

	def test_popcount_num7_3bits(self):
		"""test for 3 bits total set in 7"""
		self.assertEqual(hamming.popcount(7), 3)


if __name__ == '__main__':
	unittest.main()