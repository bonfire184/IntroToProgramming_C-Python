#include <iostream>
using namespace std;

class Polygon{
protected:
    int height;
    int width;   //derived classes will also have protected variables
public:
    Polygon(){
        cout<<"Polygon constructor called."<<endl;
    }
    void setValues(int h, int w){
        height = h;
        width = w;
    }
    int area(){
        cout<<"Polygon area called"<<endl;
        return height*width;
    }
};

class Rectangle:public Polygon{
public:
    Rectangle(){
        cout<<"rectangle constructor called"<<endl;
    }
    int area(){
        cout<<"Rectangle area called."<<endl;
        return height * width;
    }
};
//!derived class Triangle
class Triangle:public Polygon{
public:
    Triangle(){
        cout<<"triangle constructor called."<<endl;
    }
    /*!
    int area(){
        cout<<"triangle area called"<<endl;
        return (height * width) / 2;
    }*/
};

class Automobile{
protected:
    string make;
    string model;
    int year;
    string condition;
public:
    Automobile(string ma, string mo, int y, string co){
        make = ma;
        model = mo;
        year = y;
        condition = co;
        //cout<"calling Automobile constructor"<<endl;
    }
};

class Truck:public Automobile{
private:
    string cab;
    string bed;
public:
    Truck(string ma, string mo, int y, string co, string c, string b):Automobile(ma, mo, y, co){
        cab = c;
        bed = b;
        cout<<"calling truck constructor"<<endl;

    }
};



int main(){


    //Base class Parent
    //Derived classes (children)
    //Polygon: height, width, # of sides ------>>> shares with triangle and square

    //Base class Automobile: Make, Model, Year, Condition, Color, VIN
    //SUBCLASS OF AUTOMOBILE Car: Inherits from automobile but also has its own unique properties and methods: trunk, doors, # of seats
    //"                                                                                                "truck: bed, cab

    Truck trk("Ford", "F150", 1990, "bad", "extended", "extra");


    Rectangle rect;
    rect.setValues(7, 3);
    cout<<"The area is: "<<rect.area()<<endl;//Constructs a Polygon so that it can construct a Rectangle

    cout<<" "<<endl;
    Triangle tri;
    tri.setValues(4, 5);
    cout<<"The area is: "<<tri.area()<<endl;
    Triangle tri2;
    tri2.setValues(3.3, 3.4);
}
