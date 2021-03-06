#include "cstring"

struct NonPODStruct {
    int a, b;

    NonPODStruct() : a(0), b(1) {}
    NonPODStruct(int a_, int b_) : a(a_), b(b_) {}
    NonPODStruct(const NonPODStruct& o) {
        a = o.a;
        b = o.b;
    }
};

class Buffer {
    NonPODStruct non_pds_field;
};

void bar(Buffer& a) {
    std::memset(&a, 0, sizeof(a)); // предупреждение
}

void foo() {
    Buffer a, b;
    std::memset(&a, 0, sizeof(a)); // предупреждение
    std::memchr(&a, 0, sizeof(a)); // предупреждение
    std::memcmp(&a, &b, sizeof(b)); // предупреждение
    std::memcpy(&a, &b, sizeof(b)); // предупреждение
    std::memmove(&a, &b, sizeof(b)); // предупреждение
    bar(a);
}
