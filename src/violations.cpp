// src/violations.cpp
class Test {
public:
    int *ptr;
    Test() {
        ptr = new int(10);
    }
    ~Test() {
        delete ptr;
        int x = *ptr;  // ❗ Use-after-delete: triggers ERR53-CPP
    }
};

int main() {
    Test t;
    return 0;
}
