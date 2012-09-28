#include <typeinfo>
#include <string>
#include <limits>

using namespace std;

#include "TestSimple.h"


// Foo: The class we want to test.

class Foo {
  public:
    Foo (int x) : n(x) {}
    void add_a_foo () { n++; }
    void subtract_a_foo () { n--; }
    int  get_foo () { return n; }
    void set_foo ( int x ) { n = x; }
  private:
    int n;
};



int main () {
    TestSimple test( "Foo tests" );
    test.ok(1, "Initial state.");
    
    Foo myfoo(5);
    
    test.ok(1, "Instantiated a Foo.");
    test.ok( typeid( myfoo ) == typeid( Foo ), "'myfoo' is a Foo." );
    test.ok( myfoo.get_foo() == 5, "Initialization of 'myfoo' is correct." );
    
    myfoo.add_a_foo();
    
    test.ok( myfoo.get_foo() == 6, "add_a_foo() added a foo." );
    
    myfoo.subtract_a_foo();
    
    test.ok( myfoo.get_foo() == 5, "subtract_a_foo() subtracted a foo." );
    
    myfoo.set_foo(0);
    
    test.ok( myfoo.get_foo() == 0, "set_foo() set myfoo to zero foos." );
    
    myfoo.subtract_a_foo();
    
    test.ok( myfoo.get_foo() == -1, "Negative quantity of foos works." );
    
    myfoo.set_foo( numeric_limits<int>::min() );
    
    test.ok( myfoo.get_foo() == numeric_limits<int>::min(),
             "A negative Foo count can be at least that of min type int." );
    
    myfoo.set_foo( numeric_limits<int>::max() );
    
    test.ok( myfoo.get_foo() == numeric_limits<int>::max(),
             "A positive Foo count can be at least that of max type int." );

    test.done_testing();
    test.ok(0);
    return 0;
}
