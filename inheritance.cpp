#include <iostream>
using namespace std;
class Vehicle {
    double speed;
public:
    virtual void move() {
        cout << "is on" << endl;
    }
};
class Bicycle: public Vehicle {

public:
    void ringBell(){

        cout << "The bell is ringing" << endl;
    }

    void move() {

        cout << "Bicycle is moving" << endl;
    }

};
class Car : public Vehicle {
public:
    void move() {

        cout << "Car is on" << endl;
    }

    void honk() {

        cout << "car is honking" << endl;
    }

};
int main()
{
    Car s;
    s.move();
    s.honk();

    Bicycle b;
    b.move();
    b.ringBell();
   
}

2)
class Animal
{
public:
    virtual string sound()
    {
        return "Animal sound" ;
    }
};

class Dog : public Animal
{
public:
    string sound()
    {
        return "Dog barks";
    }
};
class Cat : public Animal
{
public:
    string sound()
    {
        return "Cat meows";

     }
};
int main() 
{
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();
    for (int i = 0; i < 2; i++) {
        string a = animals[i]->sound();
        cout << a << endl;
    }

    return 0;
}
3)

class shape {
public:
    virtual double area() const = 0;
};


class rectangle : public shape {
private:
    double width;
    double height;

public:
    rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

class circle : public shape {
private:
    double radius;

public:
    circle(double r) : radius(r) {}

    double area() const override {

        return 3.14 * radius * radius; 
    }
};

int main() {

    const int numshapes = 2;
    shape* shapes[numshapes];

    shapes[0] = new rectangle(5.0, 3.0);  
    shapes[1] = new circle(2.0);           
          
    for (int i = 0; i < numshapes; ++i) {
        cout << "shape is  " << i + 1 << ": " << shapes[i]->area() << endl;
    }

    return 0;
}
4)
class Character {
public:
	virtual string attack() {

		return "Is attacking" ;

	}

};
class Warrior :public Character {

public:
	string  attack() {

		return "Warrior attacks with sword" ;
	}

};
class Mage : public Character {

public :
	 string attack() {
		return "Mage casts spell";
	}

};
int main() {

	Character* characters[2];
	characters[0] = new Warrior();
	characters[1] = new Mage();
	for (int i = 0; i < 2; ++i) {
		cout << "process" << i + 1 << ": " << characters[i]->attack() << endl;
	}

	return 0;
}
5)
class  BankAccount {
public :
	virtual string  calculateInterest() {

		return "fdkjf";
	}

};
class SavingsAccount:public BankAccount {
	string  calculateInterest() {

		return "5%";
	}

};
class CurrentAccount: public BankAccount {

public:
	string  calculateInterest() {

		return "2%";
	}
};
int main() {

	BankAccount* B[2];

	B[0] = new SavingsAccount();
	B[1] = new CurrentAccount();
	for (int i = 0; i < 2; ++i) {
		cout << "process" << i + 1 << ": " << B[i]->calculateInterest() << endl;
	}
	
	return 0;
}
