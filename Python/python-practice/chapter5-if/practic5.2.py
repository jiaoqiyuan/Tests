str1 = 'Hello'
str2 = 'hello'

print(str1 == str2)
print(str1.lower() == str2)

number1 = '100'
number2 = '101'
if number1 == number2:
	print("number1 = number2")
elif number1 > number2:
	print("number1 > number2")
elif number1 < number2:
	print("number1 < number2")

if (number1 == '100') and (number1 < number2):
	print("yes")

tmplist = ['100', '102', '109', '108']
if '100' in tmplist:
	print("list test ok")

if '110' not in tmplist:
	print("110 test ok")