// src/violations.cpp
class Bad {
public:
    int *x;
    Bad() {
        x = new int(42);
    }
    ~Bad() {
        delete x;
        int y = *x;  // ❗ ERR53-CPP should be triggered here
    }
};

int main() {
    Bad b;
    return 0;
}
