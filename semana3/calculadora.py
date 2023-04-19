def calcula (a, op, b):
    a, b = int(a), int(b)
    if op == "-":
        return a-b
    if op == "+":
        return a+b
    if op == "x":
        return a*b
    if op == "/":
        return int(a/b)

def calculadora(exp):

    val = ""
    if exp[0] != "(":
        for i in exp:
            if i != ")":
                val += i
            else:
                break
        return val

    fn, lp, rp = 0, 0, 0
    for i in range(len(exp)):
        if exp[i] == "(":
            lp += 1
        if exp[i] == ")":
            rp += 1
        if lp == rp:
            fn = i
            break
    
    return calcula (calculadora(exp[1:i]),exp[i+1],calculadora(exp[i+3:-1]))  

    
    
t = int(input())
for i in range(t):
    expressao = input()
    print(calculadora(expressao))
