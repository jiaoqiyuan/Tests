squares = [value**2 for value in range(1, 11)]
print(squares)


numbers = range(1, 1000001)
print(min(numbers))
print(max(numbers))
print(sum(numbers))
#for number in numbers:
#	print(number)

numbers = list(range(1, 21))
odd_numbers = list(range(1, 21, 2))
print(numbers)
print(odd_numbers)

num_3 = list(range(3, 31, 3))
print(num_3)

cube = []
for number in range(1, 11):
	value = number ** 3
	cube.append(value)

print(cube)

cube = [number ** 3 for number in range(1, 11)]
print(cube)