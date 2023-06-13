class Solution {
public:
    bool isPossible(int start, int mid, int target) {
        for (int i = 1; i <= mid + 1; i++) {
            if (abs(start) == target)
                return true;
            if (start + abs(i) <= target)
                start = start + abs(i);
            else
                start = start - abs(i);
        }
        return false;
    
    }
    int reachNumber(int target) {
        target = abs(target); // Make target positive

        int sum = 0;
        int steps = 0;

        while (sum < target || (sum - target) % 2 != 0) {
            steps++;
            sum += steps;
        }

        return steps;
    }
};