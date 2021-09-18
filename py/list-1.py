lst = []

i = 0
while i< 15:
	lst.append(i)
	i+=1

print(lst)
lst.reverse()
print(lst)

lst.insert(0,-11)
print(lst)
lst.append(9)
lst.remove(9)
print(lst)
lst.append(9)
print( "count 9 :", lst.count(9))
lst.clear()
print(len(lst))



squares = []

for x in range(10):
	squares.append(x**2)

sq = [x**2 for x in range(10)]

co = [(x,y) for x in range(3) for y in range(3)]

print("co-od")
for e in co:
	print(e[0], e[1])
if 3 in lst:
	print("hollla")
else:
	print('mr holla')