class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour == 12? 0: hour;
        double angle =  abs((11*minutes*1.0)/2 - 30*hour); 
        return angle <= 180?angle:360-angle;
    }
};