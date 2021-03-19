while True:
	try:
		s=input()
		if s:
			list=s.split(" ")
			ch=list[1]
			a=int(list[0])
			b=int(list[2])
			if ch==('+'):
				print(a+b)
			elif ch==('-'):
				print(a-b)
			elif ch==('*'):
				print(a*b)
			elif ch==('/'):
				print(a//b)
	except EOFError:
			break