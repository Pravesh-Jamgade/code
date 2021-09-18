basket = {'apple', 'orange', 'pear', 'banana'}

if 'apple' in basket:
	print("holla")
else:
	print("mr. holla")

a = {x for x in 'abracadabra' if x not in 'abc'}

for e in a:
	print(e)

tel = {'jack': 4098, 'snape': 4139}
tel['guido'] = 4123

print(tel)
print(tel['jack'])
lst = list(tel)
print(lst)
sortTel = sorted(tel)
print(sortTel)

sq = {x:x**2 for x in (2,4,5)}

print(sq)


knights = {'gallahad': 'the pure', 'robin': 'the brave'}

for k,v in knights.items():
	print(k,v)

for i, v in enumerate(['tic','tac','toe']):
	print(i, v)

questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']

for q, a in zip(questions, answers):
	print('q: '+q, ' a: '+a)

if (1,2,3) < (1,2,4):
	print('less-1')

if [1,2,3] < [1,2,4]:
	print('less-2')

