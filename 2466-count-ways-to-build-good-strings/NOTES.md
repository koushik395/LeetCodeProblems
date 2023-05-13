**Bottom Up DP Example**
low = 3, high = 3, zero = 1, one = 1
dp []= {1,0,0,0};
​
-> i = 1;
**for zeros**
1 >= 1 dp[1] = dp[1] + dp[1-1]
dp [] = {1,1,0,0};
**for ones**
1 >= 1 dp[1] = dp[1] + dp[1-1]
dp [] = {1,2,0,0};
​
-> i = 2;
**for zeros**
2 >= 1 dp[2] = dp[2] + dp[2-1]
dp [] = {1,2,2,0};
**for ones**
2 >= 1 dp[2] = dp[2] + dp[2-1]
dp [] = {1,2,4,0};
​
-> i = 3;
**for zeros**
3 >= 1 dp[3] = dp[3] + dp[3-1]
dp [] = {1,2,4,4};
**for ones**
3 >= 1 dp[3] = dp[3] + dp[3-1]
dp [] = {1,2,4,8};