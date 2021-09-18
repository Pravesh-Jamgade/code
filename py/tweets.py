
def main():
	data = {}
	t = int(input())
	while t!=0:
		t=t-1
		n = int(input())
		for i in range(n):
			name, twt =(str(input())).split()
			if data.get(name, 0) == 0:
				data[name]=1
				continue
			data[name]=data[name]+1

		ans = 0
		qlf = []
		for k,v in data.items():
			ans=max(v,ans)
		for k,v in data.items():
			if v == ans:
				qlf.append(k)
		qlf.sort()

		for names in qlf:
			print(names, ans)


if __name__ == "__main__":
	main()


