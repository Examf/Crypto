#include <stdio.h>
#include <math.h>

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, a, b;

    printf("Enter a prime number (p): ");
    scanf("%lld", &p);

    printf("Enter a primitive root modulo %lld (g): ", p);
    scanf("%lld", &g);

    printf("Enter private key for user 1 (a): ");
    scanf("%lld", &a);

    printf("Enter private key for user 2 (b): ");
    scanf("%lld", &b);

    long long A = power(g, a, p);
    long long B = power(g, b, p);

    long long secretA = power(B, a, p);
    long long secretB = power(A, b, p);

    printf("User 1's public key: %lld\n", A);
    printf("User 2's public key: %lld\n", B);

    printf("Shared secret for user 1: %lld\n", secretA);
    printf("Shared secret for user 2: %lld\n", secretB);

    return 0;
}
