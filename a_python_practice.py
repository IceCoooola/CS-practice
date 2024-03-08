
def diff(x, y):
    if x == y:
        return 0
    return 1
def edit_distance(x, y):
    """
    args:
        x:string = the first word.
        y:string = The second word.
    
    return:
        Tuple[String,String] = the optimum global alignment between x and y. The first string in the 
        tuple corresponds to x and the second to y. Use hypen's '-' to represent gaps in each string.
    """
    m = len(x)
    n = len(y)
    dp = [ [0] *(n+1) for _ in range(m + 1)]
    for i in range(1, m+1):
        dp[i][0] = i
    for i in range(1, n+1):
        dp[0][i] = i
    for i in range(1, m+1):
        for j in range(1, n+1):
            delete = dp[i - 1][j] + 1
            insert = dp[i][j - 1] + 1
            substitude = dp[i - 1][j - 1] + diff(x[i-1], y[j-1])
            dp[i][j] = min(delete, insert, substitude)          
    
    x_align = ""
    y_align = ""
    i, j = m, n
    while i > 0 or j > 0:
        if i > 0 and j > 0 and x[i - 1] == y[j - 1]:
            x_align += x[i - 1]
            y_align += y[j - 1]
            i, j = i - 1, j - 1
        elif i > 0 and dp[i][j] == dp[i - 1][j] + 1:
            x_align += x[i - 1]
            y_align += '-'
            i -= 1
        elif j > 0 and dp[i][j] == dp[i][j - 1] + 1:
            x_align += '-'
            y_align += y[j - 1]
            j -= 1
        else:
            x_align += x[i - 1]
            y_align += y[j - 1]
            i, j = i - 1, j - 1
    return ''.join(reversed(x_align)), ''.join(reversed(y_align))

def cumulative_mul(t):
    """Mutates t so that each node's label becomes the product of all labels in
    the corresponding subtree rooted at t.

    >>> t = Tree(1, [Tree(3, [Tree(5)]), Tree(7)])
    >>> cumulative_mul(t)
    >>> t
    Tree(105, [Tree(15, [Tree(5)]), Tree(7)])
    >>> otherTree = Tree(2, [Tree(1, [Tree(3), Tree(4), Tree(5)]), Tree(6, [Tree(7)])])
    >>> cumulative_mul(otherTree)
    >>> otherTree
    Tree(5040, [Tree(60, [Tree(3), Tree(4), Tree(5)]), Tree(42, [Tree(7)])])
    """
    if t.is_leaf():
        return
    p = t.label
    for b in t.branches:
        cumulative_mul(b)
        p *= b.label
    t.label = p


def prune_small(t, n):
    """Prune the tree mutatively, keeping only the n branches
    of each node with the smallest labels.

    >>> t1 = Tree(6)
    >>> prune_small(t1, 2)
    >>> t1
    Tree(6)
    >>> t2 = Tree(6, [Tree(3), Tree(4)])
    >>> prune_small(t2, 1)
    >>> t2
    Tree(6, [Tree(3)])
    >>> t3 = Tree(6, [Tree(1), Tree(3, [Tree(1), Tree(2), Tree(3)]), Tree(5, [Tree(3), Tree(4)])])
    >>> prune_small(t3, 2)
    >>> t3
    Tree(6, [Tree(1), Tree(3, [Tree(1), Tree(2)])])
    """
    while len(t.branches) > n:
        largest = max(t.branches, key=lambda t: t.label)
        t.branches.remove(largest)
    for b in t.branches:
        prune_small(b, n)


def delete(t, x):
    """
    Delete any occurrence of the 'x' within Tree 't'. When a non-leaf
    node is deleted, the deleted node's children should be attached to
    its parent. The order of the branches must be preserved.

    Assume that the root will never be deleted.

    >>> t = Tree(3, [Tree(2, [Tree(2), Tree(2)]), Tree(2), Tree(2, [Tree(2, [Tree(2), Tree(2)])])])
    >>> delete(t, 2)
    >>> t
    Tree(3)
    >>> t = Tree(1, [Tree(2, [Tree(4, [Tree(2)]), Tree(5)]), Tree(3, [Tree(6), Tree(2)]), Tree(4)])
    >>> delete(t, 2)
    >>> t
    Tree(1, [Tree(4), Tree(5), Tree(3, [Tree(6)]), Tree(4)])
    >>> t = Tree(1, [Tree(2, [Tree(4), Tree(5)]), Tree(3, [Tree(6), Tree(2)]), Tree(2, [Tree(6),  Tree(2), Tree(7), Tree(8)]), Tree(4)])
    >>> delete(t, 2)
    >>> t
    Tree(1, [Tree(4), Tree(5), Tree(3, [Tree(6)]), Tree(6), Tree(7), Tree(8), Tree(4)])
    """
    new_branches = []
    for b in t.branches:
        delete(b, x)
        if b.label == x:
            new_branches.extend([bc for bc in b.branches])
        else:
            new_branches.append(b)
    t.branches = new_branches


class Tree:
    """
    >>> t = Tree(3, [Tree(2, [Tree(5)]), Tree(4)])
    >>> t.label
    3
    >>> t.branches[0].label
    2
    >>> t.branches[1].is_leaf()
    True
    """
    def __init__(self, label, branches=[]):
        for b in branches:
            assert isinstance(b, Tree)
        self.label = label
        self.branches = list(branches)

    def is_leaf(self):
        return not self.branches

    def __repr__(self):
        if self.branches:
            branch_str = ', ' + repr(self.branches)
        else:
            branch_str = ''
        return 'Tree({0}{1})'.format(self.label, branch_str)

    def __str__(self):
        def print_tree(t, indent=0):
            tree_str = '  ' * indent + str(t.label) + "\n"
            for b in t.branches:
                tree_str += print_tree(b, indent + 1)
            return tree_str
        return print_tree(self).rstrip()


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

HW_SOURCE_FILE=__file__


def insert_items(s, before, after):
    """Insert after into s after each occurrence of before and then return s.

    >>> test_s = [1, 5, 8, 5, 2, 3]
    >>> new_s = insert_items(test_s, 5, 7)
    >>> new_s
    [1, 5, 7, 8, 5, 7, 2, 3]
    >>> test_s
    [1, 5, 7, 8, 5, 7, 2, 3]
    >>> new_s is test_s
    True
    >>> double_s = [1, 2, 1, 2, 3, 3]
    >>> double_s = insert_items(double_s, 3, 4)
    >>> double_s
    [1, 2, 1, 2, 3, 4, 3, 4]
    >>> large_s = [1, 4, 8]
    >>> large_s2 = insert_items(large_s, 4, 4)
    >>> large_s2
    [1, 4, 4, 8]
    >>> large_s3 = insert_items(large_s2, 4, 6)
    >>> large_s3
    [1, 4, 6, 4, 6, 8]
    >>> large_s3 is large_s
    True
    """
    i = 0
    while i != len(s):
        if s[i] == before:
            s.insert(i+1, after)
            i += 1
        i += 1
    return s

def group_by(s, fn):
    """Return a dictionary of lists that together contain the elements of s.
    The key for each list is the value that fn returns when called on any of the
    values of that list.

    >>> group_by([12, 23, 14, 45], lambda p: p // 10)
    {1: [12, 14], 2: [23], 4: [45]}
    >>> group_by(range(-3, 4), lambda x: x * x)
    {9: [-3, 3], 4: [-2, 2], 1: [-1, 1], 0: [0]}
    """
    grouped = {}
    for val in s:
        key = fn(val)
        if key in grouped:
            grouped[key].append(val)
        else:
            grouped[key] = [val]
    return grouped


def count_occurrences(t, n, x):
    """Return the number of times that x is equal to one of the
    first n elements of iterator t.

    >>> s = iter([10, 9, 10, 9, 9, 10, 8, 8, 8, 7])
    >>> count_occurrences(s, 10, 9)
    3
    >>> t = iter([10, 9, 10, 9, 9, 10, 8, 8, 8, 7])
    >>> count_occurrences(t, 3, 10)
    2
    >>> u = iter([3, 2, 2, 2, 1, 2, 1, 4, 4, 5, 5, 5])
    >>> count_occurrences(u, 1, 3)  # Only iterate over 3
    1
    >>> count_occurrences(u, 3, 2)  # Only iterate over 2, 2, 2
    3
    >>> list(u)                     # Ensure that the iterator has advanced the right amount
    [1, 2, 1, 4, 4, 5, 5, 5]
    >>> v = iter([4, 1, 6, 6, 7, 7, 6, 6, 2, 2, 2, 5])
    >>> count_occurrences(v, 6, 6)
    2
    """
    count = 0
    for _ in range(n):
        if next(t) == x:
            count += 1
    return count


def repeated(t, k):
    """Return the first value in iterator t that appears k times in a row,
    calling next on t as few times as possible.

    >>> s = iter([10, 9, 10, 9, 9, 10, 8, 8, 8, 7])
    >>> repeated(s, 2)
    9
    >>> t = iter([10, 9, 10, 9, 9, 10, 8, 8, 8, 7])
    >>> repeated(t, 3)
    8
    >>> u = iter([3, 2, 2, 2, 1, 2, 1, 4, 4, 5, 5, 5])
    >>> repeated(u, 3)
    2
    >>> repeated(u, 3)
    5
    >>> v = iter([4, 1, 6, 6, 7, 7, 8, 8, 2, 2, 2, 5])
    >>> repeated(v, 3)
    2
    """
    assert k > 1
    count = k
    prev = None
    while True:
        x = next(t)
        if x == prev:
            count -= 1
        else:
            count = k - 1
            prev = x
        if count == 0:
            return x



def sprout_leaves(t, leaves):
    """Sprout new leaves containing the labels in leaves at each leaf of
    the original tree t and return the resulting tree.

    >>> t1 = tree(1, [tree(2), tree(3)])
    >>> print_tree(t1)
    1
      2
      3
    >>> new1 = sprout_leaves(t1, [4, 5])
    >>> print_tree(new1)
    1
      2
        4
        5
      3
        4
        5

    >>> t2 = tree(1, [tree(2, [tree(3)])])
    >>> print_tree(t2)
    1
      2
        3
    >>> new2 = sprout_leaves(t2, [6, 1, 2])
    >>> print_tree(new2)
    1
      2
        3
          6
          1
          2
    """
    if is_leaf(t):
        return tree(label(t), [tree(leave) for leave in leaves])
    else:
        new_branches = []
        for b in branches(t):
            new_branches.append(sprout_leaves(b, leaves))
        return tree(label(t), new_branches)

def partial_reverse(s, start):
    """Reverse part of a list in-place, starting with start up to the end of
    the list.

    >>> a = [1, 2, 3, 4, 5, 6, 7]
    >>> partial_reverse(a, 2)
    >>> a
    [1, 2, 7, 6, 5, 4, 3]
    >>> partial_reverse(a, 5)
    >>> a
    [1, 2, 7, 6, 5, 3, 4]
    """
    left = start
    right = len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1



# Tree Data Abstraction

def tree(label, branches=[]):
    """Construct a tree with the given label value and a list of branches."""
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [label] + list(branches)

def label(tree):
    """Return the label value of a tree."""
    return tree[0]

def branches(tree):
    """Return the list of branches of the given tree."""
    return tree[1:]

def is_tree(tree):
    """Returns True if the given tree is a tree, and False otherwise."""
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    """Returns True if the given tree's list of branches is empty, and False
    otherwise.
    """
    return not branches(tree)

def print_tree(t, indent=0):
    """Print a representation of this tree in which each node is
    indented by two spaces times its depth from the root.

    >>> print_tree(tree(1))
    1
    >>> print_tree(tree(1, [tree(2)]))
    1
      2
    >>> numbers = tree(1, [tree(2), tree(3, [tree(4), tree(5)]), tree(6, [tree(7)])])
    >>> print_tree(numbers)
    1
      2
      3
        4
        5
      6
        7
    """
    print('  ' * indent + str(label(t)))
    for b in branches(t):
        print_tree(b, indent + 1)

def copy_tree(t):
    """Returns a copy of t. Only for testing purposes.

    >>> t = tree(5)
    >>> copy = copy_tree(t)
    >>> t = tree(6)
    >>> print_tree(copy)
    5
    """
    return tree(label(t), [copy_tree(b) for b in branches(t)])



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
    
  
