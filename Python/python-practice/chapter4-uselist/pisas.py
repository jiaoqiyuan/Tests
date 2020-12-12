pizzas = ['New-York-Style', 'Chicago-Style', 'California-Style', 'Pan-Pizza']
for pizza in pizzas:
	print("I like pepperoni pizza " + pizza)

print("I like pizza very much, I really love pizza!")

friend_pizzas = pizzas[:]
pizzas.append('Take and Bake Style')
friend_pizzas.append('Stufffed')

print("My favorite pizza are:")
for pizza in pizzas:
	print(pizza)
print("My friend's favorite pizzas are:")
for friend_pizza in friend_pizzas:
	print(friend_pizza)