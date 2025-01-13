#include "../exercise.h"

/*
constexpr用于声明常量表达式,可以在编译时求值的表达式. 
当函数为递归函数时,递归调用constexpr函数时,constexpr编译器会超过默认的操作计数限制,导致出错
*/



// constexpr unsigned long long fibonacci(int i) {
//     switch (i) {
//         case 0:
//             return 0;
//         case 1:
//             return 1;
//         default:
//             return fibonacci(i - 1) + fibonacci(i - 2);
//     }
// }

// 非递归调用版本
constexpr unsigned long long fibonacci(int i) {
    unsigned long long a = 0, b = 1;
    for (int j = 0; j < i; ++j) {
        unsigned long long temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    // error: 05_constexpr/main.cpp:16:54: error: ‘constexpr’ evaluation operation count exceeds limit of 33554432 (use ‘-fconstexpr-ops-limit=’ to increase the limit)
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
