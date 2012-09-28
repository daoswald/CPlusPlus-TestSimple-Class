#include <iostream>
#include <string>
#include <iomanip>

#include "TestSimple.h"

using namespace std;

void TestSimple::preface() {
    cout << "Running tests: " << test_name << endl;
    cout << "Plan: ";
    if( plan >= 0  )
        cout << plan;
    else
        cout << "No plan";
    cout << "." << endl << endl;
}


void TestSimple::summary () {
    int plan_failures = test_plan();
    cout << "\n\nTest summary:\n" << endl;
    cout << "\tTests run:     "   << setw(3) << test_num      << endl;
    cout << "\t   Passed:     "   << setw(3) << passed        << endl;
    cout << "\t   Failed:     "   << setw(3) << failed        << endl;
    cout << "\tPlan failures: "   << setw(3) << plan_failures << endl;
    cout  <<  "\nResult:\t"
          <<  ( failed || plan_failures ? "FAIL\n" : "PASS\n" );
}

int TestSimple::test_plan() {
    int plan_failures = 0;
    if( ! done || tests_after_done || ( plan >=0 && plan != test_num ) )
        cout << endl;
    if( ! done ) {
        plan_failures++;
        cout << "Not OK- Plan error: done_testing() wasn't called." << endl;
    }
    if( tests_after_done ) {
        plan_failures++;
        cout << "Not OK- Plan error: " << tests_after_done 
             << " tests ran after calling done_testing()." << endl;
    }
    if( plan >= 0 && plan != test_num ) {
        plan_failures++;
        cout << "Not Ok- Plan error: Planned " << plan 
             << " tests but ran " << test_num << "." << endl;
    }
    return plan_failures;
}



void TestSimple::ok ( bool test, string message ) {
    test_num++;
    if ( done ) tests_after_done++;
    if( test ) {
        cout << "Ok-" << setw(3) << test_num << ". " << message << endl;
        passed++;
    }
    else {
        cout << "Not Ok-" << setw(3) << test_num << ". " << message << endl;
        failed++;
    }
}

