Same as Longest Increasing Subsequence Problem
​
Since it's Longest Non-decreasing Subsequence , we need to change a bit comparator relationship:
For i, x in enumerate(nums):
If x >= last element in the lis
we append into the lis.
ans[i] = len(lis)
Else
idx = Find the index of the smallest number > x
lis[idx] = x; // Replace that number with x
ans[i] = idx + 1