// src/violations.cpp
#include <iostream>
#include <stdexcept>

/* ─────────────────────────────────────────────
   1.  Guaranteed MEM50-CPP UseAfterFree hit
   ───────────────────────────────────────────── */
void use_after_free()
{
    int* ptr = new int(42);
    delete ptr;          // pointer freed
    *ptr = 7;            // ❗ use-after-free (write) – MEM50-CPP triggers
}

/* ─────────────────────────────────────────────
   2.  Guaranteed ERR53-CPP hit in destructor
   ───────────────────────────────────────────── */
class Bad
{
    int* p;
public:
    Bad() : p(new int(99)) {}

    ~Bad() noexcept        // destructor must be noexcept for this rule
    {
        delete p;
        int val = *p;      // ❗ dereference after delete – ERR53-CPP triggers
        (void)val;
    }
};

int main()
{
    try {
        Bad b;             // destructor runs at end of scope
        use_after_free();
    } catch (const std::exception&) {
        // swallow any exception – not relevant for these rules
    }
    return 0;
}
