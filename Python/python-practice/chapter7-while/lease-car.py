number = input("Please input a number to me so I can find it can be devoted by 10:")
if int(number) % 10 == 0:
    print("\nThe number " + number + " can be devoted by 10.")
else:
    print("\nThe number " + number + " can not be devoted by 10.")

message = input("What kind of car do you want to lease?")
print("\nLet me see if I can find you a Subaru.")

number = input("How many people eat here?")
if int(number) > 8:
    print("\nThere are not enough tables here for you.")
else:
    print("\nHere is the table.")
