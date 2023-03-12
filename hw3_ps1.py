# student name: Dee Bao
# student id: 1222029
# Program set 1:Using Functions modify Stock Transaction Program
# This program will show Last month Kool Doode purchased some stock from Kaplack, Inc.


#input function
def enterUserInfor()-> (str, float, float, float, float):
    '''This function let user enter their information about the stock they purchased.'''
    stockName = input('\nEnter Stock name: ')
    numberShare = int(input('Enter Number of shares : '))
    purchasePrice = float(input('Enter Purchase price : '))
    sellingPrice = float(input('Enter selling price : '))
    commission = float(input('Enter Commission : '))
    return (stockName, numberShare, purchasePrice, sellingPrice, commission)


#calculation function
def calculateProfit(numberShare: float, purchasePrice: float, sellingPrice: float, commission: float) -> (float, float, float, float, float):
    '''This function calculate the profit of the stock'''
    amountPaid = numberShare * purchasePrice
    comPaidPurchase = amountPaid * commission
    amountSold = numberShare * sellingPrice
    comPaidSale = amountSold * commission
    profit = amountSold - comPaidSale - amountPaid - comPaidPurchase
    return (amountPaid, comPaidPurchase, amountSold, comPaidSale, profit)


#display function
def displayStockInfo(stockName:str, amountPaid:float, comPaidPurchase:float, amountSold:float, comPaidSale:float, profit:float):
    '''This function display user's information about the stock they purchased'''
    print('\n\nStock name :', stockName)
    print('Amount paid for the stock:'+' '*10, '$', format(amountPaid, '13,.2f'), sep = '')
    print('Commission paid on the purchase:'+' '*4, '$', format(comPaidPurchase, '13,.2f'),sep = '')
    print('Amount the stock sold for:'+' '*10, '$', format(amountSold, '13,.2f'),sep = '')
    print('Commission paid on the sale:'+' '*8, '$', format(comPaidSale, '13,.2f'),sep = '')
    print('Profit (or loss if negative):'+' '*7, '$', format(profit, '13,.2f'),sep = '')


def main():
    '''The main function will keep asking user to enter their stock information until a No is entered.'''
    yesNo = input("Enter your stock information? Type 'y' for yes, or 'n' for no: ")
    # input
    while(yesNo != 'n'):
        stockName, numberShare, purchasePrice, sellingPrice, commission = enterUserInfor()
        amountPaid, comPaidPurchase, amountSold, comPaidSale, profit = calculateProfit(numberShare, purchasePrice, sellingPrice, commission)
        displayStockInfo(stockName, amountPaid, comPaidPurchase, amountSold, comPaidSale, profit)
        yesNo = input("\n\nEnter your stock information? Type 'y' for yes, or 'n' for no: ")


if __name__ == "__main__":
    main()

# Test Run 1
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: Kaplack, Inc.
# Enter Number of shares : 10000
# Enter Purchase price : 33.92
# Enter selling price : 35.92
# Enter Commission : 0.04
#
#
# Stock name : Kaplack, Inc.
# Amount paid for the stock:          $   339,200.00
# Commission paid on the purchase:    $    13,568.00
# Amount the stock sold for:          $   359,200.00
# Commission paid on the sale:        $    14,368.00
# Profit (or loss if negative):       $    -7,936.00
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: IBM
# Enter Number of shares : 15000
# Enter Purchase price : 50.25
# Enter selling price : 100.20
# Enter Commission : 0.02
#
#
# Stock name : IBM
# Amount paid for the stock:          $   753,750.00
# Commission paid on the purchase:    $    15,075.00
# Amount the stock sold for:          $ 1,503,000.00
# Commission paid on the sale:        $    30,060.00
# Profit (or loss if negative):       $   704,115.00
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: n

# Test Run 2
# Enter your stock information? Type 'y' for yes, or 'n' for no: n

# Test Run 3
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: apple
# Enter Number of shares : 111
# Enter Purchase price : 222
# Enter selling price : 333
# Enter Commission : 0.06
#
#
# Stock name : apple
# Amount paid for the stock:          $    24,642.00
# Commission paid on the purchase:    $     1,478.52
# Amount the stock sold for:          $    36,963.00
# Commission paid on the sale:        $     2,217.78
# Profit (or loss if negative):       $     8,624.70
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: tesla
# Enter Number of shares : 4210
# Enter Purchase price : 542
# Enter selling price : 156
# Enter Commission : 0.03
#
#
# Stock name : tesla
# Amount paid for the stock:          $ 2,281,820.00
# Commission paid on the purchase:    $    68,454.60
# Amount the stock sold for:          $   656,760.00
# Commission paid on the sale:        $    19,702.80
# Profit (or loss if negative):       $-1,713,217.40
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: google
# Enter Number of shares : 12
# Enter Purchase price : 1254
# Enter selling price : 2631
# Enter Commission : 0.08
#
#
# Stock name : google
# Amount paid for the stock:          $    15,048.00
# Commission paid on the purchase:    $     1,203.84
# Amount the stock sold for:          $    31,572.00
# Commission paid on the sale:        $     2,525.76
# Profit (or loss if negative):       $    12,794.40
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: facebook
# Enter Number of shares : 12
# Enter Purchase price : 54.56
# Enter selling price : 48.44
# Enter Commission : 0.05
#
#
# Stock name : facebook
# Amount paid for the stock:          $       654.72
# Commission paid on the purchase:    $        32.74
# Amount the stock sold for:          $       581.28
# Commission paid on the sale:        $        29.06
# Profit (or loss if negative):       $      -135.24
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: n


# Test Run 4
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: android
# Enter Number of shares : 1241
# Enter Purchase price : 12.24
# Enter selling price : 20.01
# Enter Commission : 0.08
#
#
# Stock name : android
# Amount paid for the stock:          $    15,189.84
# Commission paid on the purchase:    $     1,215.19
# Amount the stock sold for:          $    24,832.41
# Commission paid on the sale:        $     1,986.59
# Profit (or loss if negative):       $     6,440.79
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: amazon
# Enter Number of shares : 123
# Enter Purchase price : 456.78
# Enter selling price : 345.67
# Enter Commission : 0.02
#
#
# Stock name : amazon
# Amount paid for the stock:          $    56,183.94
# Commission paid on the purchase:    $     1,123.68
# Amount the stock sold for:          $    42,517.41
# Commission paid on the sale:        $       850.35
# Profit (or loss if negative):       $   -15,640.56
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: yahoo
# Enter Number of shares : 111
# Enter Purchase price : 45.2
# Enter selling price : 26.8
# Enter Commission : 0.02
#
#
# Stock name : yahoo
# Amount paid for the stock:          $     5,017.20
# Commission paid on the purchase:    $       100.34
# Amount the stock sold for:          $     2,974.80
# Commission paid on the sale:        $        59.50
# Profit (or loss if negative):       $    -2,202.24
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: n


# Test Run 5
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: bank of america
# Enter Number of shares : 123
# Enter Purchase price : 44.56
# Enter selling price : 55.46
# Enter Commission : 0.02
#
#
# Stock name : bank of america
# Amount paid for the stock:          $     5,480.88
# Commission paid on the purchase:    $       109.62
# Amount the stock sold for:          $     6,821.58
# Commission paid on the sale:        $       136.43
# Profit (or loss if negative):       $     1,094.65
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: microsoft
# Enter Number of shares : 15
# Enter Purchase price : 8764.56
# Enter selling price : 7755.55
# Enter Commission : 0.02
#
#
# Stock name : microsoft
# Amount paid for the stock:          $   131,468.40
# Commission paid on the purchase:    $     2,629.37
# Amount the stock sold for:          $   116,333.25
# Commission paid on the sale:        $     2,326.66
# Profit (or loss if negative):       $   -20,091.18
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: y
#
# Enter Stock name: HDFC bank
# Enter Number of shares : 231
# Enter Purchase price : 4562
# Enter selling price : 4444
# Enter Commission : 0.03
#
#
# Stock name : HDFC bank
# Amount paid for the stock:          $ 1,053,822.00
# Commission paid on the purchase:    $    31,614.66
# Amount the stock sold for:          $ 1,026,564.00
# Commission paid on the sale:        $    30,796.92
# Profit (or loss if negative):       $   -89,669.58
#
#
# Enter your stock information? Type 'y' for yes, or 'n' for no: n

