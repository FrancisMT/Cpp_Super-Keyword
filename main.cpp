#include<iostream>
#include<memory>


class BaseClass {

public:

    inline BaseClass()
        : x(0)
        {}

    inline int GetX() const {
        return x;
    }

    virtual inline void ChangeX(int newX) { 
        x = newX;
    };

protected:
    int x;

};

class DerivedClass : public BaseClass {

public:

    inline DerivedClass()
     : super()
     , y(0)
      {}

    virtual inline void ChangeX(int newX) override {
        super::ChangeX(newX);
        ++x;
    }

private:

    typedef BaseClass super;

    int y;

};

int main(){

    DerivedClass TestObject;

    TestObject.ChangeX(41);
    std::cout << TestObject.GetX() << std::endl;

    return 0;
}