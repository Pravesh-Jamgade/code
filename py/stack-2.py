
class Stack():
	def __init__(self):
		self.items = []

	def push(self, item):
		self.items.append(item)

	def pop(self):
		self.items.pop()

	def get_stack(self):
		return self.items

	def empty(self):
		if len(self.items) == 0:
			return True
		return False

	def top(self):
		return self.items[-1]

def main():
	p = "(()))"
	q = "()()()"
	s = Stack()

	inp = [p,q]
	t = 2;
	
	for cur in inp:
		for b in cur:
			if s.empty()==False and s.top()== '(' and b==')':
				s.pop()
			else:
			 s.push(b)

		if s.empty():
			print(cur +" is valid.\n")
		else:
			print(cur +" is invalid.\n")
			while s.empty() == False:
				s.pop()




if __name__ == "__main__":
	main()