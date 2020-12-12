alien_color = 'red'
if alien_color == 'green':
	print("You get 5 point.")
else:
	print("You get 10 point.")

age = 13
if age < 2:
	pass
elif age < 4:
	print("You are learning to work.")
elif age < 13:
	print("You are child.")
elif age < 20:
	print("You are teenager.")
elif age < 65:
	print("You age major.")
elif age >= 65:
	print("You are old.")

favorite_fruits = ['apple', 'banana', 'orange', 'strawberry']
if 'banana' in favorite_fruits:
	print("You really like banana.")