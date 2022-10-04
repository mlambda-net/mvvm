
#include "observer/console.h"
#include <gtest/gtest.h>
#include <reactive/global.h>
#include <reactive/operations.h>

TEST(ObservableTest, Subject) {
    auto subject = reactive::ToSubject<int>(1);
    subject->Next(1);


    auto release = subject->Subscribe([](int value) {
        std::cout << value << std::endl;
    });

    subject->Next(4);

    subject->Next(2);
    subject->Complete();

    subject->Next(3);
    subject->Complete();

    release->Dispose();
}

TEST(ObservableTest, Range) {
    auto m = reactive::Range<int>(1, 10) >> reactive::Skip<int>(5);
    m->Subscribe([](int value) {
        //std::cout << value << std::endl;
    });



   auto f = []( Box<reactive::Observable<int>> value) {
       value->Subscribe([](int n) {
           std::cout << n << std::endl;
       });

       return value;
   };




    auto r = reactive::Range<int>(1,3) >> reactive::Skip<int>(0) >> f;

    r->Subscribe([](int n) {
        //std::cout << n << std::endl;
    });

}