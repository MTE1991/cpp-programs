#include <iostream>
using namespace std;

class Cat {
    public:
        virtual void response(void) {
            for (int i=0; i < 3; i++)
                cout << "Meow!\n";
        }
};

class Kitten : public Cat {
    public:
        void response(void) {
            for (int i=0; i < 3; i++)
                cout << "Meow! Meow\n";
        }
};

int main(void)
{
    Cat mother;
    Kitten child;
    
    cout << "Mother:\n";
    mother.response();
    
    cout << "Child\n";
    child.response();
    
    return 0;
};
