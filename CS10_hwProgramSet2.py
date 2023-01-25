# Program set 2: Stock Transaction Program
# This program will show Last month Kool Doode purchased some stock from Kaplack, Inc.


#input
stockName = input('Please enter the stock name>: ')
numberShare = int(input('Please enter the number of shares>: '))
purchasePrice = float(input('Please enter the purchase price>: '))
sellingPrice = float(input('Please enter the selling price>: '))
commission = float(input('Please enter the commission>: '))

#calculation
amountPaid = numberShare * purchasePrice
comPaidPurchase = amountPaid * commission
amountSold = numberShare * sellingPrice
comPaidSale = amountSold * commission
profit = amountSold - comPaidSale - amountPaid - comPaidPurchase

#display
print('Amount paid for the stock:', ' '*10, '$', format(amountPaid, '13,.2f'))
print('Commission paid on the purchase:', ' '*4, '$', format(comPaidPurchase, '13,.2f'))
print('Amount the stock sold for:', ' '*10, '$', format(amountSold, '13,.2f'))
print('Commission paid on the sale:', ' '*8, '$', format(comPaidSale, '13,.2f'))
print('Profit (or loss if negative):', ' '*7, '$', format(profit, '13,.2f'))


##Test Run 1
##Please enter the stock name>: Kaplack, Inc.
##Please enter the number of shares>: 10000
##Please enter the purchase price>: 33.92
##Please enter the selling price>: 35.92
##Please enter the commission>: 0.04
##Amount paid for the stock:            $    339,200.00
##Commission paid on the purchase:      $     13,568.00
##Amount the stock sold for:            $    359,200.00
##Commission paid on the sale:          $     14,368.00
##Profit (or loss if negative):         $     -7,936.00

##Test Run 2
##Please enter the stock name>: IBM
##Please enter the number of shares>: 15000
##Please enter the purchase price>: 50.25
##Please enter the selling price>: 100.20
##Please enter the commission>: 0.02
##Amount paid for the stock:            $    753,750.00
##Commission paid on the purchase:      $     15,075.00
##Amount the stock sold for:            $  1,503,000.00
##Commission paid on the sale:          $     30,060.00
##Profit (or loss if negative):         $    704,115.00

##Test Run 3
##Please enter the stock name>: Tesla
##Please enter the number of shares>: 20000
##Please enter the purchase price>: 220.58
##Please enter the selling price>: 116.35
##Please enter the commission>: 0.03
##Amount paid for the stock:            $  4,411,600.00
##Commission paid on the purchase:      $    132,348.00
##Amount the stock sold for:            $  2,327,000.00
##Commission paid on the sale:          $     69,810.00
##Profit (or loss if negative):         $ -2,286,758.00

##Test Run 4
##Please enter the stock name>: bitcoin
##Please enter the number of shares>: 3
##Please enter the purchase price>: 60002
##Please enter the selling price>: 22632
##Please enter the commission>: 0.02
##Amount paid for the stock:            $    180,006.00
##Commission paid on the purchase:      $      3,600.12
##Amount the stock sold for:            $     67,896.00
##Commission paid on the sale:          $      1,357.92
##Profit (or loss if negative):         $   -117,068.04

##Test Run 5
##Please enter the stock name>: Apple
##Please enter the number of shares>: 14522
##Please enter the purchase price>: 140.50
##Please enter the selling price>: 143.75
##Please enter the commission>: 0.02
##Amount paid for the stock:            $  2,040,341.00
##Commission paid on the purchase:      $     40,806.82
##Amount the stock sold for:            $  2,087,537.50
##Commission paid on the sale:          $     41,750.75
##Profit (or loss if negative):         $    -35,361.07


