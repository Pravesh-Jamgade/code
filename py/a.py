import asyncio




def filter2(nums):
	for num in nums:
		yield num*3
	

def filter3(nums):
	for num in nums:
		yield num

nums = [0,-1,-4,-9,-16,-25,-36,-45]



a= ["A", "a", "B", "b", "C", "c", "D", "d"]

ad = dict(zip(a[0::2], a[1::2]))
print(ad)