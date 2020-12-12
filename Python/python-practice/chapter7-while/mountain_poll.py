responses = {}

#设置一个标志，之处调查是否继续
polling_active = True
while polling_active:
    name = input("\nWhat's your name? ")
    response = input("Which mountain would you like to climb someday ")
    #将答卷存储在字典中
    responses[name] = response
    #看是否还有人参与调查
    repeat = input("Would you like to let another person respond? (yes/no )")
    if repeat == 'no':
        polling_active = False
print("\n---Poll Results----")
for name, response in responses.items():
    print(name + " would you like to climb " + response + ".")
