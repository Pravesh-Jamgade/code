price = '10'
weight = 67.8
# height = input('What is your height ?')
print("your " + str(weight)) #string concatenate

print(round(weight))
m=-908
print(abs(m))

import math

print(math.floor(weight))
print(math.ceil(weight))
print(math.factorial(5))

name='pravesh jamgade'
print(len(name))

print(name.upper())
print(int(price) + 10)

i=1
while i<=6:
	print(i)

	i+=1

lst=['A','B','C', 'D', 'E', 'F', 'G']
for m in lst:
	print(m)
print("new\n")
for i in range(3):
	print(lst[i], i)

print('new\n')
for i in range(1,7,2): # (start, len, indrement by)
	print(lst[i], i)

prices = [10,20,30]
total = 0
for price in prices:
	total+=price

print(f"total: {total}")

for i in range(3):
	for j in range(3):
		print(f'({i},{j})')



print(lst[:])

mat=[
	[1,2,3],
	[4,5,6],
	[7,8,9],
]
print(mat)


lst.append('H')
lst.append(1)
lst.append(-9)
lst.append(1)
lst.append(1)
lst.append(1)
lst.append(1)
print(lst)
lst.insert(0,'o')
lst.remove('H')
print(lst)

lst.pop()
print(lst)
print(lst.index('B'))

print('B' in lst)
print(lst.count(1))

p = [4,5,6,7,0,-1]
p.sort()
print(p)
q=p.copy()
print(q)

lst=(1,4,1,1,0,-6)
print(lst.count(1))
print(lst[0])

point=(1,2,3)
x,y,z=point
print(x,y,z)

cust = {
	"name":"pravesh",
	"age":25
}

print(cust["name"])
# print(cust["Name"]) key error
print(cust.get("Name", "not here"))
cust["newKey"]="newValue"
print(cust)


a=10
try:
	a = a/(1-1)
except ZeroDivisionError:
	print('0 value error')
except ValueError:
	print("error")	

class Point:
	def __init__(self,x=None,y=None):
		self.x=x
		self.y=y

	def move(self):
		print('move')

	def draw(self):
		print('draw')


p = Point()
p.move()
p.draw()

q = Point(10,7)


class Person:
	def __init__(self, name):
		self.name=name

	def talk(self):
		print(f'hi, I am {self.name}')



john=Person('john')
john.talk()
print(john.name)

class Animal:
	def walk(self):
		print('walk')

class Dog(Animal):
	pass

class Cat(Animal):
	pass

dog=Dog()
dog.walk()


cat=Cat()
cat.walk()

uio = []

print(len(uio))
