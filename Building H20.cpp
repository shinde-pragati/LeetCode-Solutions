#include <mutex>
#include <condition_variable>
using namespace std;

class H2O {
private:
    mutex mtx;
    condition_variable cv;
    int hydrogenCount = 0;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{ return hydrogenCount < 2; });

        // releaseHydrogen() outputs "H"
        releaseHydrogen();
        hydrogenCount++;

        if (hydrogenCount == 2)
            cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{ return hydrogenCount == 2; });

        // releaseOxygen() outputs "O"
        releaseOxygen();

        hydrogenCount = 0;
        cv.notify_all();
    }
};