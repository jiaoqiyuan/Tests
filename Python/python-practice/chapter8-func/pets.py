def descrive_pet(pet_name, animal_type='dog'):
    """显示宠物信息"""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

#descrive_pet('hamster', 'harry')
#descrive_pet(animal_type='hamster', pet_name='harry')
descrive_pet(pet_name='harry', animal_type='hamster')
descrive_pet('hamster', 'harry')
descrive_pet(pet_name='while')
descrive_pet('while', 'fish')
