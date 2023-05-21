**We first paint one of the islands using DFS with color 2, so we can easily identify island #1 and island #2. **
​
**Then we start expanding island #2 by paining connected empty area. Each round, we increase the color (3, 4, and so on) so we can keep track of the newly painted area. This ends when we "bump" into the first island.**
![](https://assets.leetcode.com/users/votrubac/image_1541488072.png)