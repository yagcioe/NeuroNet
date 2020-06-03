//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_TEST_H
#define NEURONET_TEST_H


#include <c++/4.8.3/string>
#include "GenericList.h"

class Test {


public:
    class UnexpectedValueException : public std::exception {
        char *e;
        char *g;
    public:
        UnexpectedValueException(char *expected, char *given);
        ~UnexpectedValueException() override;

        char *what();

    };

    typedef void (*func )(void *args);

    struct result {
    public:
        std::string *name;
        unsigned long start;
        unsigned long end;
        unsigned long duration;
        bool success;
        std::exception *e;

        ~result() {
            delete (name);
        }

        std::string *toString();
    };

protected:
    class TestCase {
    public:
        std::string *name;
        func f;

        TestCase(std::string *name, func f);
    };

public:
    int count();
    static void eq(void *a, void *b);
    static void neq(void *a, void *b);
    explicit Test(void *params[]);

    ~Test();

    /**
     *
     * @param args array of length of number of tests
     * @return array of results length of number of tests
     */
    void run(void *args[]);

    result *getResult();

    void addTest(std::string *name, func);

private:
    void **params;
    GenericList<TestCase> *tests;
    result *r;


};


#endif //NEURONET_TEST_H
