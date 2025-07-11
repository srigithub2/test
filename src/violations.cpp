// violations.cpp
#include <stdexcept>
//TEST
class Unsafe {
    int *p;
public:
    Unsafe() {                   // Constructor throws without handling
        p = new int(42);
        if (*p == 42)
            throw std::runtime_error("ERR51: unhandled exception");   // triggers ERR51-CPP
    }

    ~Unsafe() {                  // Removed noexcept for clang compatibility
        delete p;
        int x = *p;              // ERR53-CPP: value referenced after destruction
        (void)x;
    }
};

int main() {
    try {
        Unsafe u;                // construction will throw
    } catch (...) {
        // Intentionally empty to keep program running
    }
    return 0;
}
