def main():
	x = int(raw_input())
	fact = 1
	while x > 0:
		fact *= x
		x -= 1
	print fact

if __name__ == '__main__':
 	main() 