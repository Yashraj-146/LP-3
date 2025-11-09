#include <iostream>
using namespace std;

class Fibonacci {
    public:
    int iterative(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        int prev2 = 0, prev1 = 1, current = 0;

        for(int i = 2; i <= n; i++) {
            current = prev2 + prev1;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }

    int recursive(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;

        return recursive(n-1) + recursive(n-2);
    }
};

int main() {
    int n;
    cout<<"Enter the number: ";
    cin >> n;

    Fibonacci fib;
    int result1 = fib.iterative(n);
    cout<<"Fibonacci of ("<<n<<") = "<<result1<<" [Iterative]"<<endl;

    cout<<"Fibonacci of ("<<n<<") = "<<fib.recursive(n)<<" [Recursive]"<<endl;

    return 0;
}
