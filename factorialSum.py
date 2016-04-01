def main():

	x = int(raw_input())
	fact = 1
	sum_ = 0

	while x > 1:
		fact *= x
		x -= 1

	while fact > 0:
		sum_ += (fact % 10)
		fact /= 10

	print sum_



if __name__ == '__main__':
	main()