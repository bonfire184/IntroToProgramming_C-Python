#include <iostream>

using namespace std;

/*
*/
class Automobile{
    private:
        string make;
        string model;
        string condition;
        int year;
        int speed;
        int topspeed;
    public:
        Automobile(string ma, string mo, int y, int s, int TS){
            make = ma;
            model = mo;
            year = y;
            condition = "new";
            speed = s;
            topspeed = TS;
        }//end Automobile
        string getCondition(){
            return condition;
        }
        string getMake(){
            return make;
        }
        string getModel(){
            return model;
        }
        int getSpeed(){
            return speed;
        }
        void setCondition(string c){
            if(c == "new" || c == "used" || c == "wrecked"){
                condition = c;
            }else{
                cout<<"Not a valid condition"<<endl;
            }
        }
        void setSpeed(int s){
            if(s >= 0 && s <= topspeed){
                speed = s;
            }else{
                cout<<"Not a valid condition"<<endl;
            }
        }
        void Accelerate(int x){
            speed += x;
        }
};


int main(){
    Automobile prius("Toyota", "Prius", 2010, 1, 100);
    cout<<prius.getCondition()<<endl;
    //set condition
    //new, used, wrecked
    prius.setCondition("used");
    cout<<"Condition is: "<<prius.getCondition()<<endl;
    prius.setCondition("ugly");
    cout<<"Condition is: "<<prius.getCondition()<<endl;
    cout<<"Make: "<<prius.getMake()<<endl;
    cout<<"Model: "<<prius.getModel()<<endl;

    prius.setSpeed(200);
    prius.setSpeed(100);
    cout<<"Speed: "<<prius.getSpeed()<<endl;

    prius.Accelerate(100);
    cout<<"Speed: "<<prius.getSpeed()<<endl;





}
