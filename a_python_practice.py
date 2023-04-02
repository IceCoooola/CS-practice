def test(x:float, u:int, y = 10, z = 20):
    print(f"x = {x}, y = {y}, z = {z}, u = {u}")

def main():
    test(10, 20)


if __name__ == "__main__":
    main()



def test1(x = 15, y = 20, z = 5):
    print(f"x = {x}, y = {y}, z = {z}")
    return x * y * z

def main():
    print("no argument passing")
    test1()
    print("with positional argument passing")
    test1(1,1)
    print("with keyword argument passing")
    test1(x = 5, z = 15)
    print("with positional argument and keyword argument passing")
    test1(x = 5,y= 5)


if __name__ == "__main__":
    main()

def test(x , y):
    print(f"x = {x}")
    print(f"y = {y}")

def main():
    test(1,3)
    test(y = 3, x = 1)

def factor(n):
    ret = 1
    for i in range(1, n + 1):
        ret *= i
    return ret

def factorRecursion(n):
    if n == 0:
        return 1
    else:
        return factorRecursion(n - 1) * n
    
    
def factor(n):
    ret = 1
    for i in range(1, n + 1):
        ret *= i
    return ret

def factorRecursion(n):
    if n == 0:
        return 1
    else:
        return factorRecursion(n - 1) * n


def main():
    print(factor(5))
    print(factorRecursion(1))
x = 10 # global variable

def test():
    global x # 声明x是全局变量，然后就可以修改全局变量。
    x = 20
    if True:
        y = 30  # 函数代码块不涉及作用域，只有函数和类才会涉及到作用域
    print(y)

def test1(): # 函数只是在定义，不会执行函数体的内容。
    print("执行函数体代码")
    print("执行函数体代码")
    print("执行函数体代码")



def main():
    # test()
    # print(x)
    print("11111")
    test1()
    print("22222")
    test1()
    print("33333")
    test1()

if __name__ == "__main__":
    main()

def getData() -> (int, int):
    base = int(input("enter base:>"))
    height = int(input('enter height>:'))
    return base, height

def trigData(height:int, base: int) -> float:
    return (height * base / 2)

def displayData(height:int, base: int, area: float):
    print(f"height: {height}")
    print(f"base: {base}")
    print(f"area: {area}")


# write a function show_interest() to take in 3 parameters with default
# arguments rate =
# 0.01, period = 10, principal = 10000.00 (no user input required):
# - interest = principal * rate * periods
# - print the following string
def show_interest(rate = 0.01, periods = 10, principal = 10000):
    interest = principal * rate * periods
    print(interest)

def texas() -> None:
    birds = 5000
    print(f"texas has {birds} brids")

def California() -> None:
    birds = 8000
    print(f"California has {birds} brids")

def add(a = 10, b = 20, c = 30) -> int:
    return a + b + c


def main():
    # print(add(1, 2, b = 3))  # error generated
    # s = "0123456";
    # for i in range(1,5,2):
    #     print(s[i])
    # print(i)
    # for i in range(1,5):
    #     pass
    # print(i)
    # print(s[1:]) # s[1 to end]
    # print(s[1:-1])
    # # == print( s[1 : len(s) - 1]) == print(s[1 : 7 - 1]) == print(s[1: 6])
    # if 'x' in s:
    #     print(s)
    # else:
    #     print("?")
    # s = input("enter a string")
    # California()
    # texas()
    show_interest()


if __name__ == "__main__":
    main()


list = [10, 20, 30, 40] 
 
index = 0 
for index in range(4): 
    print(list[index]) 
def add(a = 10, b = 20, c = 30) -> int:
    return a + b + c


def main():
    print(add(1, 2, b = 3))


if __name__ == "__main__":
    main()



def max(num1:int, num2 : int) -> int :
    '''compare two numbers and return larger value'''
    if num1 > num2:
        return num1
    else :
        return num2
    
  
