#include <iostream>

using namespace std;

class Animal{
    public:

    Animal(){}
    ~ Animal(){}

    virtual void eat() = 0;
};

class Dog : public Animal
{
    public:

    Dog(){}
    ~Dog(){}

    void eat()
    {
        cout << "dog eat." << endl;
    }
};

class Cat : public Animal
{
    public:
    Cat(){}
    ~ Cat(){}

    void eat()
    {
        cout << "cat eat." << endl;
    }
};

void Print(Animal* pAnimal)
{
    pAnimal->eat();
}

int main()
{
    Dog d;
    Cat c;
    Animal *a, *b;
    a = &d;
    b = &c;
    Print(a);
    Print(b);
    return 0;
}