places = []
flag = True
while flag:
    place = input("\nIf you could visit some places in the world, where would you go?\nEnter 'quit' to exit!")
    if place == 'quit':
        flag = False
    else:
        places.append(place)

print("\nYour places are: ")
for place in places:
    print("\n" + place)
