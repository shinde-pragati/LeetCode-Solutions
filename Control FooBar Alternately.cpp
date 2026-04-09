#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool foo_turn;

public:
    FooBar(int n) {
        this->n = n;
        foo_turn = true;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{ return foo_turn; });

            // printFoo() outputs "foo".
            printFoo();

            foo_turn = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{ return !foo_turn; });

            // printBar() outputs "bar".
            printBar();

            foo_turn = true;
            cv.notify_all();
        }
    }
};