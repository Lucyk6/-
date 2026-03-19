#include <iostream>
using namespace  std;
//class Transport {
//
//public :
//    virtual void move() = 0;
//};
//class car : public Transport {
//
//public: 
//    void move() {
//
//        cout << "is on" << endl;
//
//    }
//
//};
//class Bike : public Transport {
//
//public:
//    void move() {
//
//        cout << "is off" << endl;
//
//    }
//
//};
//
//int main()
//{
//    Transport* t;
//    car c;
//    Bike b;
//    t = &c;
//    t->move();
//    t = &b;
//    t->move();
//      
//}
//class Animal {
//
//public:
//	virtual void sound() = 0;
//
//};
//class Dog : public Animal {
//	
//public: 
//	 void sound() {
//	
//	        cout << "gaf" << endl;
//	
//	    }
//	
//	};
//class Cow : public Animal {
//	
//public:
//	void sound() {
//	
//	     cout << "muu" << endl;
//	
//	  }
//	
//};
//int main()
//{
//	Animal* A;
//	Cow c;
//	Dog d;
//	A = &c;
//	A->sound();
//	A = &d;
//	A->sound();
//}
//class Shape {
//public:
//    virtual void area() = 0; 
//};
//
//class Square : public Shape {
//private:
//    int side;
//public:
//    Square(int s) : side(s) {} 
//
//    void area() override {
//        cout << "s square: " << side * side << endl;
//    }
//};
//
//class Triangle : public Shape {
//private:
//    int base;   
//    int height;
//public:
//    Triangle(int b, int h) : base(b), height(h) {}
//    void area() override {
//        cout << "S triangle: " << (0.5 * base * height) << endl;
//    }
//};
//
//int main() {
//    Shape* S;
//    Square c(6);      
//    Triangle t(76, 66); 
//    S = &c;
//    S->area(); 
//    S = &t;
//    S->area(); 
//    return 0;
//}
//class Device {
//public:
//    virtual void turnOn() = 0; 
//
//};
//
//class Phone : public Device {
//public:
//    void turnOn() override {
//        cout << "turn off" << endl;
//    }
//};
//
//class Laptop : public Device {
//public:
//    void turnOn() override {
//        cout << "trun on" << endl;
//    }
//};
//int main() {
//    Phone phone;
//    Laptop laptop;
//
//    Device* devices[2];
//    devices[0] = &phone;
//    devices[1] = &laptop;
//
//    for (int i = 0; i < 2; ++i) {
//        devices[i]->turnOn();
//    }
//
//    return 0;
//}
//
//
//class Drink {
//public:
//    virtual void prepare() = 0;
//   
//};
//
//class Tea : public Drink {
//public:
//    void prepare() override {
//        cout << "hifdjf" << endl;
//    }
//};
//
//class Coffee : public Drink {
//public:
//    void prepare() override {
//        cout << "fkk." << endl;
//    }
//};
//int main() {
//    Tea tea;
//    Coffee coffee;
//
//    Drink* drinks[2];
//    drinks[0] = &tea;
//    drinks[1] = &coffee;
//
//    for (int i = 0; i < 2; ++i) {
//        drinks[i]->prepare();
//    }
//
//    return 0;
//}
//
//class Payment
//{
//public:
//    virtual void pay(double amount) = 0;
//};
//
//class CardPayment : public Payment
//{
//public:
//    void pay(double amount)
//    {
//        cout << "Paid " << amount << " by card\n";
//    }
//};
//
//class PayPalPayment : public Payment
//{
//public:
//    void pay(double amount)
//    {
//        cout << "Paid " << amount << " via PayPal\n";
//    }
//};
//
//class CryptoPayment : public Payment
//{
//public:
//    void pay(double amount)
//    {
//        cout << "Paid " << amount << " using crypto\n";
//    }
//};
//
//int main()
//{
//    CardPayment c;
//    PayPalPayment pa;
//    Payment* p[2];
//    p [0] = &c;
//    p[1] = &pa;
//
//    for (int i = 0; i < 2; ++i) {
//         p[i]->pay(67);
//       }
//
//}

