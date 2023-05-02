class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double farenheit = (9*1.0/5)*celsius + 32;
        return {kelvin,farenheit};
    }
};