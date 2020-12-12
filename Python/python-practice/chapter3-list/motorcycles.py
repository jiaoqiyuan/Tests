#!/usr/bin/python3

motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles.append('ducati')
print(motorcycles)

motorcycles.insert(0, 'ducati')
print(motorcycles)

del motorcycles[0]
print(motorcycles)

del motorcycles[1]
print(motorcycles)

poped_motorcycle = motorcycles.pop()
print(poped_motorcycle)

first_owned = motorcycles.pop(0)
print(first_owned)
