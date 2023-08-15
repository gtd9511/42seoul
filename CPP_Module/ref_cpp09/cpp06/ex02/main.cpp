#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int tryA(Base &p);
int tryB(Base &p);
int tryC(Base &p);
Base * generate(void);
void identify(Base& p);
void identify(Base* p);


int main(){
    
    srand(static_cast<unsigned int>(time(0)));
    {
        Base *objPtr1 = generate();
        identify(objPtr1);
        identify(*objPtr1);
        delete objPtr1;
    }
    {
        Base B;
        identify(B);
    }
}

Base * generate(void){

    int n = rand();
    int ret = n % 3;
    switch(ret){
        case 0:
            std::cout << "(A)" << "\n";
            return new A;
        case 1:
            std::cout << "(B)" << "\n";
            return new B;
        case 2:
            std::cout << "(C)" << "\n";
            return new C;
    }
    return nullptr;
}

void identify(Base* p) {
    std::cout << "idenfify by pointer result: ";
   if (dynamic_cast<A*>(p) != 0) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != 0) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != 0) {
        std::cout << "C" << std::endl;
    }
}

int tryA(Base &p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch( const std :: bad_cast &e ){
        return 1;
   }
   return 0;
}

int tryB(Base &p){
    try{
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
  }
  catch( const std :: bad_cast &e ) {
    return 1;
  }
  return 0;
}
 

int tryC(Base &p){
     try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
  }
  catch( const std::bad_cast &e) {
    return 1;
  }
  return 0;
}

void identify(Base& p) {
    std::cout << "idenfify by reference result: ";
    int candidate[3] = {0,0,0};
    char objs[3] = {'A', 'B', 'C'};
    if (tryA(p) == 1)
        candidate[0] = 1;
    if (tryB(p) == 1)
        candidate[1] = 1;
    if (tryC(p) == 1)
        candidate[2] = 1;
    int flag = 1;
    for (int i  = 0; i < 3; i++)
    {
        if(candidate[i] == 0)
        {
            flag = 0;
            std::cout << objs[i] << std::endl;
        }
    }
    if(flag)
        std::cout << "Base\n";
    std::cout << "\n";
}
