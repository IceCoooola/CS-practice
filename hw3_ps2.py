# student name: Dee Bao
# student id: 1222029
# Program set 2: Credit card number validation Program
# This program will prompt user how many credit card they would like to check, and print whether the the
# credit card number is valid


def isValid(number:str)-> bool:
    '''this function return true if the card number is valid'''
    # check if length of string is improper
    if len(number) < 13 or len(number) > 16:
        return False
    # check if the string is all digit
    if not(number.isdigit()):
        return False
    # check if the first number is valid
    if not(number.startswith('4') or number.startswith('5') or number.startswith('6') or number.startswith('37')):
        return False
    # get the sum of even place from right and sum of odd digit number.
    sumOfEven = sumOfDoubleEvenPlace(number)
    sumOfOdd = sumOfOddPlace(number)
    # add up to total sum and check if it is divisible by 10
    totalSum = sumOfOdd + sumOfEven
    if totalSum % 10 == 0:
        return True
    else:
        return False


def sumOfDoubleEvenPlace(cardNumber:str)-> int:
    '''This function return sum of doubled even place digits from right in cardNumber, if the number is greater than
    9, then sum up the digit and returns it'''
    sum = 0
    for i in range(-2, -len(cardNumber) - 1, -2):
        sum += getDigit(int(cardNumber[i]) * 2)
    return sum


def getDigit(number: int) -> int:
    '''This function return this number if it is a single digit, otherwise, return the sum of the two digits'''
    if number > 9:
        return number % 10 + number // 10
    else:
        return number


def sumOfOddPlace(cardNumber:str) -> int:
    '''This function return sum of odd place digits in number'''
    sum = 0
    # add up all the odd digit number
    for i in range(-1, -len(cardNumber) - 1, -2):
        sum += int(cardNumber[i])
    return sum


def main():
    '''The main function will prompt user to enter how many credit card number they want to check,
    and print the whether the credit card number is valid or not'''
    # input of loop times
    num = int(input('How many credit card numbers do you want to check? '))
    for i in range(num):
        # input credit card number as a string
        cardNumber = input('Enter a credit card number: ')
        # check validity and print the result
        if isValid(cardNumber):
            print(cardNumber, 'is valid\n')
        else:
            print(cardNumber, 'is invalid\n')

if __name__ == "__main__":
    main()

# Test Run 1
# How many credit card numbers do you want to check? 2
# Enter a credit card number: 4388576018402626
# 4388576018402626 is invalid
#
# Enter a credit card number: 4388576018410707
# 4388576018410707 is valid


# Test Run 2
# How many credit card numbers do you want to check? 0


# Test Run 3
# How many credit card numbers do you want to check? 3
# Enter a credit card number: 12345678
# 12345678 is invalid
#
# Enter a credit card number: 5169769005222217
# 5169769005222217 is valid
#
# Enter a credit card number: 6011655276746808
# 6011655276746808 is invalid


# Test Run 4
# How many credit card numbers do you want to check? 4
# Enter a credit card number: 5432844511576542
# 5432844511576542 is invalid
#
# Enter a credit card number: 3710542698715314
# 3710542698715314 is invalid
#
# Enter a credit card number: 6513220846321985
# 6513220846321985 is invalid
#
# Enter a credit card number: 6759378257215020
# 6759378257215020 is valid


# Test Run 5
# How many credit card numbers do you want to check? 5
# Enter a credit card number: 3538640436946253
# 3538640436946253 is invalid
#
# Enter a credit card number: 370233658710982
# 370233658710982 is valid
#
# Enter a credit card number: 5526156171008000
# 5526156171008000 is valid
#
# Enter a credit card number: 2720994694354969
# 2720994694354969 is invalid
#
# Enter a credit card number: 6011536083710902
# 6011536083710902 is valid

