def make_albun(name, album, songs=''):
	singer = {'name': name, 'album': album}
	if songs:
		singer['songs'] = songs
	return singer

singer1 = make_albun('jay', 'fantasy', '12')
print(singer1)
singer2 = make_albun('jollin', '72bian')
print(singer2)
singer3 = make_albun('eason', '10nian')
print(singer3)

while True:
	singer_name = input("\nPlease input a singer's name:")
	if singer_name == 'q':
		break
	album_name = input("input his/her album:")
	if album_name == 'q':
		break
	singer = make_albun(singer_name, album_name)
	print(singer) 
