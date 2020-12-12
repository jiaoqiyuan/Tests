sandwich_orders = ['aaa', 'pastrami', 'bbb', 'pastrami', 'ccc','pastrami']
finished_sandwiches = []
print("\nAll pastrami had been sold!")
while 'pastrami' in sandwich_orders:
    sandwich_orders.remove('pastrami')

while sandwich_orders:
    sandwich_order = sandwich_orders.pop()
    print("\nI made your tuna sanwichi " + sandwich_order)
    finished_sandwiches.append(sandwich_order)
print("\nI have finished all sandwiches!")
    
