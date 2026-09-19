class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1=max(x1,min(xCenter,x2)), y1=max(y1,min(y2,yCenter));
        return (x1-xCenter)*(x1-xCenter)+(y1-yCenter)*(y1-yCenter) <= radius*radius;
    }
};