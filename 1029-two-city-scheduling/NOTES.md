Visual
costs = [[10,20],[30,200],[400,50],[30,20]]
​
totalCost = 470 //at this point we summed up all city A costs
differenceArr = [10, 170, -350, -10] -> sort -> [-350, -10, 10, 170] //calculated and sorted all the differences between B and A
​
470 + (-350) + (-10) = 110 // make up for N / 2 of our worst decisions to go to A
​
solution = 110
​
for those who didn't understand why we just added first N/2 element of differenceArr in 470.
current_collected_fund_by_airport =470
if number is negative means e.g -370 he paid us 370 extra , then refund him. // current_collected_fund_by_airport = current_collected_fund_by_airport - 370
if number is positive means e.g +370 he has to pay extra to us , then add 370 to fund. // current_collected_fund_by_airport = current_collected_fund_by_airport +370