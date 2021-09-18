class Node:
	def __init__(self, val):
		self.val = val
		self.next = None


class LinkedList():
	def __init__(self):
		self.head = None
		self.currHead = None

	def append(self, val):
		nNode = Node(val)
		if self.head == None:
			self.head = nNode
			self.currHead = self.head
			return

		tmpNode = self.currHead
		while tmpNode.next != None:
			tmpNode=tmpNode.next

		tmpNode.next = nNode

	def print(self):
		tmpNode = self.head

		while(tmpNode!=None):
			print(tmpNode.val)
			tmpNode=tmpNode.next



def main():
	val = [1,2,3,4,5,6,7,8,9]
	ll = LinkedList()
	for e in val:
		ll.append(e)
	ll.print()


if __name__ == "__main__":
	main()