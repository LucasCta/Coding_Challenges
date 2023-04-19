def numero2(number,acc):
    if (acc == 1):
        return number//10 + (number%10 >= 2)
    qnt2 = numero2(number,acc-1)
    tmp = int(str(number)[-1*acc])
    if (tmp < 2):
        qnt2 += (number//(10**acc)) * (10**(acc-1))
    elif (tmp == 2):
        bottom = number - (number//(10**(acc-1)) * (10**(acc-1)))
        qnt2 +=  (number//(10**acc)) * (10**(acc-1)) + int(bottom) + 1 
    else:
        qnt2 += (number//(10**acc) + 1) * (10**(acc-1))
    return qnt2

t = int(input())
for i in range(t):
    x, y = input().split(" ")
    xl, yl = len(x), len(y)
    print(numero2(int(y),yl)-numero2(int(x),xl))
