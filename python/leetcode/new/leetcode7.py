x = 1239913939193
x = str(x)
minus = 1
if x[0] == '-':
    x = x.replace('-', '')
    minus = -1
x = int(x[::-1])*minus

if -2**31 <= x <= 2**31-1:
    print(x)
else:
    print(0)

