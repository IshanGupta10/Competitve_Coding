def main():
	x = int(raw_input())
	a = 0
	b = 1
	c = []
	c.append(a)
	c.append(b)
	while  x > 1:
		temp = a + b
		a = b
		b = temp
		c.append(temp)
		x -= 1
	print c

if __name__ == '__main__':
	main()