#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle{
    private:
        int serialNumber;
        double width;
        double height;
        static int numSquare;
        static int numHoriz;
        static int numVert;
    public:
        Rectangle(double, double);
        ~Rectangle();
        void setWidth(double);
        void setHeight(double);
        void setSerialNumber(int);
        double getWidth() const;
        double getHeight() const;
        int getSerialNumber() const;
        static int getSquareCount();
        static int getHorizCount();
        static int getVertCount();
        static void incrementSquare();
        static void incrementVert();
        static void incrementHoriz();
};
#endif