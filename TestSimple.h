#include <string>

#ifndef TEST_SIMPLE_H
#define TEST_SIMPLE_H

class TestSimple {
    public:
        TestSimple ( std::string name = 0, int planned_tests = -1 )
            : test_name(name),
              plan(planned_tests),
              test_num(0),
              passed(0),
              failed(0),
              done(false),
              tests_after_done(0)  { preface(); }
        ~TestSimple()              { summary(); }
        void ok( bool test, std::string message = "" );
        void done_testing() { done = true; }
    private:
        std::string test_name;
        int  plan;
        int  test_num;
        int  passed;
        int  failed;
        bool done;
        int  tests_after_done;
        
        int  test_plan();
        void preface();
        void summary();
};

#endif
