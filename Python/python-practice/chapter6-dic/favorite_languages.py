favorite_languages = {
	'jen': 'python',
	'sarah': 'c',
	'edward': 'ruby',
	'phil': 'python',
}
print("Sarah's favorite language is " +	
	favorite_languages['sarah'].title() +
	".")

someone = {
	'first_name': 'wang', 
	'last_name': 'xiaoming', 
	'age': 15, 
	'city': 'beijing',
}
print(someone['first_name'].title())
print(someone)
for name, language in favorite_languages.items():
	print(name.title() + "'s favorite language is "+
		language.title() + ".")
print()
for name in favorite_languages.keys():
	print(name.title())
print()


number_dic = {
	'xiaoming': 8,
	'lili': 0,
	'lilei': 6,
	'hanmei': 3,
	'zhangsan':1,
}
print("lilei like the number: " + str(number_dic['lilei']))

words = {
	'return': 'It means the program is over and return a value.',
	'int': 'It means the variable is integer.',
	'python': 'It represent a code language.',
	'java': 'It represent a program language.',
	'if': 'It means whether.',
}
for key, value in words.items():
	print(key + ":" + value)

favorite_languages = {
	'jen': 'python',
	'sarah': 'c',
	'edward': 'ruby',
	'phil': 'python',
}
friends = ['phil', 'sarah']
for name in favorite_languages.keys():
	print(name.title())
	if name in friends:
		print("Hi " + name.title() +
			", I see your favorite_language is " +
			favorite_languages[name].title() + "!")
for name in sorted(favorite_languages.keys()):
	print(name.title() + ", thank you for taking the poll.")

print("\nThe following languages have been mentioned:")
for language in set(favorite_languages.values()):
	print(language.title())

investeds = ['phil', 'jen']
for name in favorite_languages.keys():
	if name in investeds:
		print(name.title() + ", Thanks for your investegating!")
	else:
		print("Please accept my investigating!")

favorite_languages = {
	'jen': ['Python', 'ruby'],
	'sarah': ['c'],
	'edward': ['ruby', 'go'],
	'phil': ['python', 'haskell'],
}
for name, languages in favorite_languages.items():
	print("\n" + name.title() + "'s favorite languages are:")
	for language in languages:
		print("\t" + language.title())