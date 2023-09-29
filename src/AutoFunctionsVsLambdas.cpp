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
    cout << "         auto Functions versus Lambdas          " << endl;
    cout << "================================================" << endl;
    cout << endl;
}

struct Customer {
   std::string name;
   std::string homeTown;
};

bool lessByNameFunc( const auto & c1, const auto & c2 ) {
    return c1.name < c2.name;
}

auto greaterByNameLambda = [] ( const auto & c1, const auto & c2 ) {
    return c1.name > c2.name;
};

int main(int argc, char *argv[]) {
   printHeader();

   std::vector<Customer> customers = { { "Warszawski", "Warszawa"},
                                       { "Skierniewicki", "Skierniewice" },
                                       { "Grodziski", "Grodzisk Mazowiecki"},
                                       { "Opolski", "Opole"},
                                       { "Kutnowski", "Kutno"} };

   cout << std::endl << "Before sorting:" << std::endl;
   for ( auto & customer: customers ) {
       cout << customer.name << ", " << customer.homeTown << std::endl;
   }

   //std::sort( customers.begin(), customers.end(), lessByNameFunc ); // ERROR! can't deduce type of parameters in sorting criterion
   std::sort( customers.begin(), customers.end(),
              lessByNameFunc<Customer, Customer> );

   cout << std::endl << "After sorting with lessByNameFunc criterion:" << std::endl;
   for ( auto & customer: customers ) {
       cout << customer.name << ", " << customer.homeTown << std::endl;
   }

   std::sort( customers.begin(), customers.end(),
              greaterByNameLambda );

   cout << std::endl << "After sorting with greaterByNameLambda criterion:" << std::endl;
   for ( auto & customer: customers ) {
       cout << customer.name << ", " << customer.homeTown << std::endl;
   }


   return 0;
}

