#include <iostream>

#include <vector>
#include <set>
#include <ranges>
#include <map>
#include <list>


using std::cout;
using std::endl;

void printHeader() {
    cout << endl;
    cout << "================================================" << endl;
    cout << "  C++20 The Complete Guide by Nicolai Josuttis  " << endl;
    cout << "   Placeholder Types for Functions Parameters   " << endl;
    cout << "         Deferred Type Checks with auto         " << endl;
    cout << "================================================" << endl;
    cout << endl;
}

/*
// The second fix: use auto for C1::foo method parameter - forward declaration no needed anymore
class C2;
*/

class C1 {
public:

/*
   // Does not compile - compiler needs the complete definition of C2 to check c2.print call, not only forward declaration of C2 class
   void foo( const C2 & c2 ) const {
       std::cout << "C1::foo called" << std::endl;
       c2.print();
   }
*/

/*
   // The first fix: declare C1::foo here and define it outside, after C2 definition
   void foo( const C2 & c2 ) const;
*/

   // The second fix: use auto for method parameter
   void foo( const auto & c2 ) const {
       std::cout << "C1::foo called" << std::endl;
       c2.print();
   }

   void print() const {
       std::cout << "C1::print called" << std::endl;
   }
};

class C2 {
public:
   void foo( const C1 & c1 ) const {
       std::cout << "C2::foo called" << std::endl;
       c1.print();
   }

   void print() const {
       std::cout << "C2::print called" << std::endl;
   }
};

/*
// The first fix: define C1::foo it outside, after C2 definition
void C1::foo( const C2 & c2 ) const {
   std::cout << "C1::foo called" << std::endl;
   c2.print();
}
*/


int main(int argc, char *argv[]) {
   printHeader();

   C1 c1;
   C2 c2;

   c1.foo( c2 );
   std::cout << std::endl;
   c2.foo( c1 );

   return 0;
}

