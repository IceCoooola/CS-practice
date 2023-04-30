# Dee Bao
# 1222029
# Homework 5 Program Set 1
# Write a program to calculate and display the loan for buying a car.

class Loan:
    # construct a loan object
    def __init__(self, annualInterestRate: float, yearsOfLoan: int, loanAmount: float, borrowerName: str):
        self.__annualInterestRate = annualInterestRate
        self.__yearsOfLoan = yearsOfLoan
        self.__loanAmount = loanAmount
        self.__borrowerName = borrowerName

    def getannualInterestRate(self) -> float:
        return self.__annualInterestRate

    def getYearsOfLoan(self) -> int:
        return self.__yearsOfLoan

    def getloanAmount(self) -> float:
        return self.__loanAmount

    def getBorrowerName(self) -> str:
        return self.__borrowerName

    def setAnnualInterestRate(self, annualInterestRate):
        self.__annualInterestRate = annualInterestRate

    def setYearsOfLoan(self, yearsOfLoan):
        self.__yearsOfLoan = yearsOfLoan

    def setLoanAmount(self, loanAmount):
        self.__loanAmount = loanAmount

    def setborrowerName(self, borrowerName):
        self.__borrowerName = borrowerName

    def getMonthlyPayment(self):
        monthlyInterestRate = self.__annualInterestRate / 1200
        monthlyPayment = self.__loanAmount * monthlyInterestRate / (
                    1 - (1 / (1 + monthlyInterestRate) ** (self.__yearsOfLoan * 12)))
        return monthlyPayment

    def getTotalPayment(self):
        totalPayment = self.getMonthlyPayment() * self.__yearsOfLoan * 12
        return totalPayment


def main():
    # input from user
    annualInterestRate = float(input('Enter yearly interest rate: '))
    yearsOfLoan = int(input('Enter number of years as an integer: '))
    loanAmount = float(input('Enter loan amount: '))
    borrowerName = input('Enter a borrower\'s name: ')

    # create an Loan object
    loanObj = Loan(annualInterestRate, yearsOfLoan, loanAmount, borrowerName)

    # display and print the monthly payment, total payment for the loan person.
    print('The loan is for', loanObj.getBorrowerName())
    print('The monthly payment is', format(loanObj.getMonthlyPayment(), ',.2f'))
    print('The total payment is', format(loanObj.getTotalPayment(), ',.2f'))
    print()
    # ask user if they wish to change the loan amount
    again = input('Do you want to change the loan amount? Y for yes or enter to quit')

    # while user did not enter an "enter"
    while again.lower() != '':

        # ask user to input a new loan amount
        newLoanAmount = float(input('Enter new loan amount'))

        # revise the loan amount
        loanObj.setLoanAmount(newLoanAmount)

        # display and print the new monthly payment, total payment for the loan person.
        print('The loan is for', loanObj.getBorrowerName())
        print('The monthly payment is', format(loanObj.getMonthlyPayment(), ',.2f'))
        print('The total payment is', format(loanObj.getTotalPayment(), ',.2f'))
        print()

        # ask user if they wish to change the loan amount
        again = input('Do you want to change the loan amount? Y for yes or enter to quit')


if __name__ == "__main__":
    main()

# Test Run 1
# Enter yearly interest rate: 2.5
# Enter number of years as an integer: 5
# Enter loan amount: 1000.00
# Enter a borrower's name: John Jones
# The loan is for John Jones
# The monthly payment is 17.75
# The total payment is 1,064.84
#
# Do you want to change the loan amount? Y for yes or enter to quity
# Enter new loan amount5000
# The loan is for John Jones
# The monthly payment is 88.74
# The total payment is 5,324.21
#
# Do you want to change the loan amount? Y for yes or enter to quit
#
# Process finished with exit code 0


# Test Run 2
# Enter yearly interest rate: 5.4
# Enter number of years as an integer: 2
# Enter loan amount: 1524
# Enter a borrower's name: Janne
# The loan is for Janne
# The monthly payment is 67.13
# The total payment is 1,611.20
#
# Do you want to change the loan amount? Y for yes or enter to quity
# Enter new loan amount2657
# The loan is for Janne
# The monthly payment is 117.04
# The total payment is 2,809.03
#
# Do you want to change the loan amount? Y for yes or enter to quit


# Test Run 3
# Enter yearly interest rate: 1.5
# Enter number of years as an integer: 20
# Enter loan amount: 4530
# Enter a borrower's name: Anna
# The loan is for Anna
# The monthly payment is 21.86
# The total payment is 5,246.23
#
# Do you want to change the loan amount? Y for yes or enter to quity
# Enter new loan amount2000
# The loan is for Anna
# The monthly payment is 9.65
# The total payment is 2,316.22
#
# Do you want to change the loan amount? Y for yes or enter to quit


# Test Run 4
# Enter yearly interest rate: 2.5
# Enter number of years as an integer: 50
# Enter loan amount: 11000
# Enter a borrower's name: Willey
# The loan is for Willey
# The monthly payment is 32.14
# The total payment is 19,281.40
#
# Do you want to change the loan amount? Y for yes or enter to quity
# Enter new loan amount5000
# The loan is for Willey
# The monthly payment is 14.61
# The total payment is 8,764.27
#
# Do you want to change the loan amount? Y for yes or enter to quity
# Enter new loan amount2000
# The loan is for Willey
# The monthly payment is 5.84
# The total payment is 3,505.71
#
# Do you want to change the loan amount? Y for yes or enter to quit


# Test Run 5
# Enter yearly interest rate: 1.5
# Enter number of years as an integer: 12
# Enter loan amount: 45684
# Enter a borrower's name: Lorry
# The loan is for Lorry
# The monthly payment is 346.86
# The total payment is 49,947.31
#
# Do you want to change the loan amount? Y for yes or enter to quity
# Enter new loan amount50000
# The loan is for Lorry
# The monthly payment is 379.63
# The total payment is 54,666.09
#
# Do you want to change the loan amount? Y for yes or enter to quit



