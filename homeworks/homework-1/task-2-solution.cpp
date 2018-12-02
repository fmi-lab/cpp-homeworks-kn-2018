#include <iostream>

using namespace std;
int main() {
    double x, y;
    cin >> x >> y;

    double grayX1 = -4, grayY1 = -2.5;
    double grayX2 = 9, grayY2 = 6;

    double white1_X1 = -1, white1_Y1 = -2;
    double white1_X2 = 3, white1_Y2 = 2;

    double white2_X1 = 3, white2_Y1 = -0.5;
    double white2_X2 = 5.5, white2_Y2 = 2;

    double white3_X1 = 3, white3_Y1 = 2;
    double white3_X2 = 7, white3_Y2 = 4.5;

    bool isInGrayArea = grayX1 < x && x < grayX2 && grayY1 < y && y < grayY2;
    bool isInOrOnBottomWhiteRect = white1_X1 <= x && x <= white1_X2 && white1_Y1 <= y && y <= white1_Y2;
    bool isInOrOnMiddleWhiteRect = white2_X1 <= x && x <= white2_X2 && white2_Y1 <= y && y <= white2_Y2;
    bool isInOrOnUpperWhiteRect = white3_X1 <= x && x <= white3_X2 && white3_Y1 <= y && y <= white3_Y2;

    bool isOnOuterContour = ((x == grayX1 || x == grayX2) && grayY1 <= y && y <= grayY2) ||
               ((y == grayY1 || y == grayY2) && (grayX1 <= x && x <= grayX2));
    bool isOnInnerContour = ((y == white1_Y1 || y == white1_Y2) && white1_X1 <= x && x <= white1_X2) ||
                            (x == white1_X2 && white1_Y1 <= y && y <= white2_Y1) ||
                            (y == white2_Y1 && white2_X1 <= x && x <= white2_X2) ||
                            (x == white2_X2 && white2_Y1 <= y && y <= white2_Y2) ||
                            (y == white2_Y2 && white2_X2 <= x && x <= white3_X2) ||
                            (x == white3_X2 && white3_Y1 <= y && y <= white3_Y2) ||
                            (y == white3_Y2 && white3_X1 <= x && x <= white3_X2) ||
                            (x == white3_X1 && white3_Y1 <= y && y <= white3_Y2) ||
                            (x == white1_X1 && white1_Y1 <= y && y <= white1_Y2);

    if (isInGrayArea && !isInOrOnBottomWhiteRect && !isInOrOnMiddleWhiteRect && !isInOrOnUpperWhiteRect) {
        cout << 2;
    } else if (isOnOuterContour || isOnInnerContour) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}

