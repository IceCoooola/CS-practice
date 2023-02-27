
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
    
  
