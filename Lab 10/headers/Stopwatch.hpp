#ifndef Stopwatch_hpp
#define Stopwatch_hpp

#include <chrono>

using namespace std;

class Stopwatch {
    private:
        chrono::steady_clock::time_point start_time;    
        chrono::steady_clock::time_point end_time;
        bool running = false;

    public:
        Stopwatch() : running(false) {}

        // Start the stopwatch
        void start() {
            start_time = chrono::steady_clock::now();
            running = true;
        }

        // Stop the stopwatch
        void stop() {
            if (running) {
                end_time = chrono::steady_clock::now();
                running = false;
            }
        }

        // Reset the stopwatch
        void reset() {
            running = false;
        }

        // Get elapsed time in seconds
        double get_elapsed_time_seconds() const {
            if (running) {
                auto now = chrono::steady_clock::now();
                return chrono::duration<double>(now - start_time).count();
            } else {
                return chrono::duration<double>(end_time - start_time).count();
            }
        }

        // Get elapsed time in milliseconds
        double get_elapsed_time_milliseconds() const {
            if (running) {
                auto now = chrono::steady_clock::now();
                return chrono::duration<double, milli>(now - start_time).count();
            } else {
                return chrono::duration<double, milli>(end_time - start_time).count();
            }
        }
};

#endif // Stopwatch_hpp
