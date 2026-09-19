class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a = max(x1, min(xCenter, x2)) - xCenter;
        int b = max(y1, min(yCenter, y2)) - yCenter;
        return a * a + b * b <= radius * radius;
    }
};