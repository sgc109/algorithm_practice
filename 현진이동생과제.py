
def gcd(a, b):
	if a==0 or b==0:
		return a+b
	if a > b:
		tmp = a
		a = b
		b = tmp
	return gcd(b % a, a)

def calcLen(s):
	si = int(s)
	ret = 1
	while (si > 0):
		ret = ret + 1
		si = si / 10
		print('si : %d ' % si)

	return ret


# s = input('Enter N(>=0) : ')	
s = '01'
print('%d has %d digit(s)' % (int(s), calcLen(s)))

