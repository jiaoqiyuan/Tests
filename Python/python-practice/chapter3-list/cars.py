#!/usr/bin/python3

cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
print(cars)

cars.sort(reverse=True)
print(cars)

print("\nHere is the sorted list:")
print(sorted(cars))
print("\nHere is the sorted list(reverse=True):")
print(sorted(cars, reverse = True))
print("\nHere is the original list:")
print(cars)
print(len(cars))
