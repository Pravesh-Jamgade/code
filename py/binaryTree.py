class Node:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None

class BinaryTree():
	def __init__(self):
		self.Tree = None

	def append(self, root, val):
		nNode=Node(val)

		if self.Tree == None:
			self.Tree = root

		if root == None:
			root=nNode
			return root
		
		else:
			if val <= root.val:
				root.left = self.append(root.left, val)
			else:
				root.right = self.append(root.right, val)

		return root

	def inorder(self, root):
		if root == None:
			return
		self.inorder(root.left)
		print(root.val)
		self.inorder(root.right)




def main():
	bt = BinaryTree()
	n = [4,1,5,10,14,13]

	root = None
	for e in n:
		root = bt.append(root, e)

	bt.inorder(root)

if __name__ == "__main__":
	main()