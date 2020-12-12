users = ['admin', 'zhao', 'zhang', 'liu', 'jiao']
#users = []
if users:
	for user in users:
		if user == 'admin':
			print("Hello admin, would you like to see a status report?")
		else:
			print("Hello Eric, thank you for logging in again.")
else:
	print("We need to find some users!")

current_users = ['Admin', 'huang', 'zhao', 'Jiao', 'li']
tmp_users = []
for current_user in current_users:
	tmp_users.append(current_user.upper())

new_users = users[:]
for new_user in new_users:
	if new_user.upper() in tmp_users:
		print("Please input some other user names.")
	else:
		print("This name " + new_user + " hasn't been used.")

numbers = range(1, 10)
for number in numbers:
	if number == 1 or number == 2 or number == 3:
		print(str(number) + "st.")
	else:
		print(str(number) + "nd.")