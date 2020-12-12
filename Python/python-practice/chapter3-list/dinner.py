#!/usr/bin/python3

friends = ['jim', 'bob', 'lily']
print(friends)

busy = friends.pop(1)
print(busy)
print(friends)

friends.insert(1, 'jiao')
print("I will invite " + friends[0].title() + " " + friends[1].title() +\
        " " + friends[2].title() + "to my home!")

print("Now I have a bigger table, I will invite three more friends!")
friends.insert(0, 'machael')
friends.insert(2, 'jodan')
friends.insert(5, 'jean')
print(friends)
print("I will invite " + str(len(friends)) + "people!")

print("I am so sorry that my table is not able to site all of 6 people!")
people = friends.pop()
print("I am sorry for not inviting you, " + people.title())
people = friends.pop()
print("I am sorry for not inviting you, " + people.title())
people = friends.pop()
print("I am sorry for not inviting you, " + people.title())
people = friends.pop()
print("I am sorry for not inviting you, " + people.title())

print(friends[0].title() + ", I will invite you to my home!")
print(friends[1].title() + ", I will invite you to my home!")
del friends[0]
del friends[0]

print(friends)
