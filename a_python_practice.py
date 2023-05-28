
import qrcode

def main():
    image = qrcode.make("i love you")
if __name__ == '__main__':
    main()

import turtle
turtle.hideturtle()
turtle.pensize(3)
turtle.penup()
turtle.goto(-200, -50)
turtle.pendown()
turtle.circle(40, steps = 3) # Draw a triangle
turtle.penup()
turtle.goto(-100, -50)
turtle.pendown()
turtle.circle(40, steps = 4) # Draw a square
turtle.penup()
turtle.goto(0, -50)
turtle.pendown()
turtle.circle(40, steps = 5) # Draw a pentagon
turtle.penup()
turtle.goto(100, -50)
turtle.pendown()
turtle.circle(40, steps = 6) # Draw a hexagon
turtle.penup()
turtle.goto(200, -50)
turtle.pendown()
turtle.circle(40) # Draw a circle
turtle.do
t = dict()
# t.add("123","123",1)
t = {"1","2",1}
print(t)

# import tkinter
# # This program uses a GUI to get three tests
# # scores and display their average.
# import tkinter
# class TestAvg:
#     def __init__(self):
#         # Create the main window.
#         self.main_window = tkinter.Tk()
#         # Create the five frames.
#         self.test1_frame = tkinter.Frame(self.main_window)
#         self.test2_frame = tkinter.Frame(self.main_window)
#         self.test3_frame = tkinter.Frame(self.main_window)
#         self.avg_frame = tkinter.Frame(self.main_window)
#         self.button_frame = tkinter.Frame(self.main_window)
#         # Create and pack the widgets for test 1.
#         self.test1_label = tkinter.Label(self.test1_frame, \
#         text='Enter the score for test 1:')
#         self.test1_entry = tkinter.Entry(self.test1_frame, \
#         width=15)
#         self.test1_label.pack(side='left')
#         self.test1_entry.pack(side='left')
#         # Create and pack the widgets for test 2.
#         self.test2_label = tkinter.Label(self.test2_frame, \
#         text='Enter the score for test 2:')
#         self.test2_entry = tkinter.Entry(self.test2_frame, \
#         width=10)
#         self.test2_label.pack(side='left')
#         self.test2_entry.pack(side='left')
#         # Create and pack the widgets for test 3.
#         self.test3_label = tkinter.Label(self.test3_frame, \
#         text='Enter the score for test 3:')
#         self.test3_entry = tkinter.Entry(self.test3_frame, \
#         width=10)
#         self.test3_label.pack(side='left')
#         self.test3_entry.pack(side='left')
#         # Create and pack the widgets for the average.
#         self.result_label = tkinter.Label(self.avg_frame, \
#         text='Average:')
#         self.avg = tkinter.StringVar() # To update avg_label
#         self.avg_label = tkinter.Label(self.avg_frame, \
#         textvariable=self.avg)
#         self.result_label.pack(side='left')
#         self.avg_label.pack(side='left')
#         # Create and pack the button widgets.
#         self.calc_button = tkinter.Button(self.button_frame, \
#         text='Average', \
#         command=self.calc_avg)
#         self.quit_button = tkinter.Button(self.button_frame, \
#         text='Quit', \
#         command=self.main_window.destroy)
#         self.calc_button.pack(side='left')
#         self.quit_button.pack(side='left')
#         # Pack the frames.
#         self.test1_frame.pack()
#         self.test2_frame.pack()
#         self.test3_frame.pack()
#         self.avg_frame.pack()
#         self.button_frame.pack()
#         # Start the main loop.
#         tkinter.mainloop()
#         # The calc_avg method is the callback function for
#         # the calc_button widget.
#     def calc_avg(self):
#         # Get the three test scores and store them
#         # in variables.
#         self.test1 = float(self.test1_entry.get())
#         self.test2 = float(self.test2_entry.get())
#         self.test3 = float(self.test3_entry.get())
#         # Calculate the average.
#         self.average = (self.test1 + self.test2 + \
#         self.test3) / 3.0
#         # Update the avg_label widget by storing
#         # the value of self.average in the StringVar
#         # object referenced by avg.
#         self.avg.set(self.average)
# # Create an instance of the TestAvg class.
# test_avg = TestAvg()


# def main():
#     dict1 = dict({1:'a', 2:"b", 3:4})
#     print(dict1.values())
#     if 4 in dict1:
#         print("4 in dict1")
#     dict2 = {}
#     print(type(dict2))
#     dict3 = dict([(1,2),(2,1)])
#
# if __name__ == "__main__":
#     main()



import tkinter

class MyGUI:
    def __init__(self):
        main_window = tkinter.Tk()
        tkinter.mainloop()
        self.test1Frame = tkinter.Frame(main_window)
        self.test1Text = tkinter.Label(self.test1Frame, text="try")

def main():
    outFile = open("test.txt",'w')
    outFile.write("1\n2\n3\n4")
    outFile.close()
    inFile = open("test.txt","r")
    # content = inFile.read()
    # print(content)
    content = inFile.readlines()
    print(content)
    for line in content:
        line.rstrip()
    print(content)


if __name__ == "__main__":
    main()

def createTuple(inputStr : str):
    list1 = inputStr.split()
    positiveList = []
    for item in list1:
        num = int(item)
        if num > 0:
            positiveList.append(num)
    myTuple = tuple(positiveList)
    print(myTuple)

def main():
    inputStr = input("enter a tuple:>")
    createTuple(inputStr)

def test(x , y, z = 15):
    print(x,y,z,sep = '  ')

def main():
    # list3 = list(['a',1,True])
    # print(list3)
    # list2 = list3[1:2]
    # print(list2)
    # test(1,2)
    set1 = set([1,55,4,5])
    set2 = set((1,22,4,5))
    print(set1)
    print(set2)
    tuple1 = (1,2)
    tuple2 = (3,4)
    tuple3 = tuple1 + tuple2
    print(tuple3)
    
    
def main():
    a = [1,2,3,4]
    b = tuple(a)
    c = 1
    print(type(b))
    d = [1,]
    d = [1]
    print(type(d))
    e = tuple(d)
    print(type(e))
    f = {1,5,7,4,2,3,4}
    g = {2}
    print(f)
    print(type(g))
def test(i: int) -> (int, int, int):
    i = 15
    return 1,2,3

def main():
    # a = 1
    # test(a)
    # print(a)
    Dlist = [[1,2],[],[1,2,3]]
    print(Dlist[0][0])
    NewList = list()
    # creating a 2D list with 2 rows and 4 cols:
    for r in range(2):
        NewList.append([])
        for c in range(4):
            NewList[r].append(0)

    print(NewList)
    NewList.append([])
    print(NewList)
    t1 = (1,2)
    t2 = ("1")
    t3 = ("1",)
    print(type(t2))
    print(type(t3))
    t4, t5 = (2,3)
    print(type(t4))
    print(type(t5))
    a = test(1)
    print(a)
    print(type(a))

def test(i: int):
    i = 15

def main():
    a = 1
    test(a)
    print(a)
    

def test(ls:list):
    ls.pop(0)
    ls.pop(0)

def main():


    list1 = [1,2,2,2,3,4,True,7,False,0]

    try:
        idx = list1.index(1)
        idx = list1.index(1)
        idx = list1.index(1)
        print("hahah")
        idx = list1.index(33)
    except ValueError:
        print("item no found.")
    test(list1)
    print(list1)
    
    
    
def main():
    list1 = [1,2,2,2,3,4,True,7,False]
    if "123123" in list1:
        print(list1)
    print(list1.index(2))
    list1.append(1)
    print(list1)
    list1.sort()
    print(list1)


def main():
    a = [1,2,3,4]
    a[0] = 5
    a[2] = 'a'
    b = a[1:3]
    print(a)
    print(b)
    c = a[:]
    print(c)
    c[1] = 555
    print(a)

def main():

    a = list([1,2,3])
    b = ['asd',"123",2,True]
    c = list("123456")
    print(a)
    print(b)
    print(c)
    for i in b:
        i = 1
        print(i)

    for i in range(len(b)):
        print(b[i])
        i = i + 1

    print(b)
def main():
    print(hash(9))
    print(hash('123'))
    print(hash("233"))
    print(hash((1,3,5)))
    print(hash(True))

def main():
    # n = int(input('enter a number:\n'))
    # for i in range(n):
    #     print(i)
    a = dict([(1, '1'), (2, '2'), (3 , '3')])
    print(a.keys())
    print(type(a.keys()))
    print(type(a.values()))
    ls = list([[1,2,3],[4,5,6],[7,8,9]])
    print(ls)

def main():
    a = dict([(1, '1'), (2, '2')])
    print(a)
    b = a.pop(1)
    print(b)

    f = open("testFile.txt","w")
    f.write('abc\n\n')
    f.write('def\n\n')
    f.write('ghl\n\n')
    f.close()
    f = open("testFile.txt","r")
    print(f.readline())
    # print(f.readline())
    # print(f.readline())
    print('next line')
    print(f.readline())
    f.close()

if __name__ == "__main__":
    main()


ls = [1,2,3,4,5]
ls.pop(2)
print(ls)
del ls[0]
print(ls)


def main():
    str1 = "abc123"
    str2 = 'def'
    str3 = 'Fef 12'
    str4 = "\t\t   \n\n"
    # str3 = str1 + str2
    # print(str3)
    # print('abc' in str3)
    # print("abc" in str3)
    # print("abbc" in str3)
    # print("abc" not in str3)
    print(str1.isalnum()) # true
    print(str1.isdigit()) # false
    print(str1.isalpha()) # false
    print(str1.islower()) # true
    print(str1.isupper()) # false
    print(str1.isspace()) # false
    print("\n\n")
    print(str2.isalnum()) # true
    print(str2.isdigit()) # false
    print(str2.isalpha()) # true
    print(str2.islower()) # true
    print(str2.isupper()) # false
    print(str2.isspace()) # false
    print("\n\n")
    print(str3.isalnum()) # false
    print(str3.isdigit()) # false
    print(str3.isalpha()) # false
    print(str3.islower()) # false
    print(str3.isupper()) # false
    print(str3.isspace()) # false
    print("\n\n")
    print(str4.isalnum()) # false
    print(str4.isdigit()) # false
    print(str4.isalpha()) # false
    print(str4.islower()) # false
    print(str4.isupper()) # false
    print(str4.isspace()) # true

if __name__ == "__main__":
    main()
x = 5

def test1():
    global x
    x = 3
    print(x)
    str1 = "hello"
    str1[1] = '1'
    print(str1)

def main():
    test1()
    print(x)

if __name__ == "__main__":
    main()


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
    
  
