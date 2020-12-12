user_0 = {
	'username': 'efermi',
	'first': 'enrico',
	'last': 'fermi',
}
user_1 = {
        'username': 'jiao',
        'first': 'jiao',
        'last': 'qiyuan',
}
user_2 = {
        'username': 'abcd',
        'first': 'efg',
        'last': 'higk',
}


for key, value in user_0.items():
	print("\nKey: " + key)
	print("Value: " + value)
people = [user_0, user_1, user_2]

for person in people:
        for key, value in person.items():
                print("\nKey: " + key + "\tvalue: " + value.title())

