class Solution {
public:
    int totalMoney(int n) {
        //completeWeek indicates how many complete week Hercy added money
        //to the bank.
        int completeWeek = n / 7;
        
        //leftDays indicates number of left days after completeWeek turn.
        int leftDays = n % 7;
        
        //starting money in the last week
        int startMoney = completeWeek + 1;
        
        //sum of AP series : Sn = (n * [2 * a + (n - 1) * d]) / 2
        int completeWeekMoneysum = (completeWeek * (2 * 28 + (completeWeek - 1) * 7)) / 2;
        
        int leftDaysMoneySum = (leftDays * (2 * startMoney + (leftDays - 1) * 1)) / 2;
        
        return (completeWeekMoneysum + leftDaysMoneySum);
    }
};

/*
        In the first complete week, sum of total money in the bank.
            1+2+3+4+5+6+7 -> 28
            
            In the first week's monday -> initial starting money : $1
            
        In the second complete week, sum of total money in the bank.
            2+3+4+5+6+7+8 -> 35
            
            In the second week's monday -> initial starting money : $2
            
        In the third complete week, sum of total money in the bank.
            3+4+5+6+7+8+9 -> 42
            
            In the third week's monday -> initial starting money : $3
        
        If we closely look at the above numbers we'll find that
        the numbers are in Arithematic Progression.
        
        28, 35, 42, 49, 56, ......... nth term.
        
        We can find the sum of first n terms in the above series.
        
        Sn = (n * [2 * a + (n - 1) * d]) / 2
        
        T(nth_term) = a + (n - 1) * d
        
        Where a(28) is first term, n is term we want/upto the sum of nth terms and
        d(7) is common difference of A.P. series.
        
        
        NOTE: For the left days (n % 7), we can again use sum of AP series
              formula to get sum money added in the left days.
    */