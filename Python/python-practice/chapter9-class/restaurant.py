class Restaurant():
    def __init__(self, restaurant_name, cuisin_type):
        self.restaurant_name = restaurant_name
        self.cuisin_type = cuisin_type
        self.number_served = 0

    def describe_restaurant(self):
        print("The restaurant's name is: " + self.restaurant_name)
        print("The restaurant's cuisin type is: " + self.cuisin_type)
    
    def open_restaurant(self):
        print("The restaurant is open.")

    def set_number_served(self, number_served):
    	self.number_served = number_served

    def increment_number_served(self, number):
    	self.number_served += number

restaurant = Restaurant('qilixiang', 'zhongcan')
#restaurant1 = Restaurant('chouguiyu', 'huicai')
#restaurant2 = Restaurant('dayu', 'tiebanshao')
#print(restaurant.cuisin_type)
#restaurant.describe_restaurant()
#restaurant1.describe_restaurant()
#restaurant2.describe_restaurant()
#restaurant.open_restaurant()

#restaurant.number_served = 150
restaurant.set_number_served(180)
restaurant.increment_number_served(100)
print("There are " + str(restaurant.number_served) + " people had come.")
