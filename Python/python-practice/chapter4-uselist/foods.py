my_foods = ['pizza', 'falafel', 'varrot cake']
friend_foods = my_foods[:]

my_foods.append('cannoli')
friend_foods.append('ice cream')

print("My favorite foods are:")
print(my_foods)

print("\nMy friend's favorite foods are:")

print(friend_foods)

print("The first three items in the list are: ", end = "")
items = my_foods[:]
print(items[:3])

print("Three items from the middle of the list are: ", end = "")
print(items[1:4])

print("The last three items in the list are:", end = "")
print(items[-3:])