#include"ef.h"

#ifdef TEST_CPP_STATIC_ARGS
DLL_PUBLIC Ef::Ef() : x(99) {
}
#else
#error TEST_CPP_STATIC_ARGS not defined
#endif

#ifdef TEST_CPP_ARGS
int DLL_PUBLIC Ef::get_x() const {
    return x;
}
#else
#error TEST_CPP_ARGS not defined
#endif
