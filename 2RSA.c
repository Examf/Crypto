#include <stdio.h>
#include <stdlib.h>

int phi, M, n, e, d, c, Flag;

void encrypt(int M)
{
    int i;
    c = 1;
    for (i=0; i<e; i++)
    {
        c = c*M%n;
    }
    c = c%n;
    printf("\nThe Encrypted Value of Plain Text -> %d\n", c);
}

void decrypt(int c)
{
    int i;
    M = 1;
    for (i=0; i<d; i++)
    {
        M = M*c%n;
    }
    M = M%n;
    printf("\nThe Decrypted Value [Plain Test] -> %d\n", M);
}

int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not a prime number
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}

void main()
{
    int p, q, s, t, i, m, count;
    for(;;)
    {
        printf("Enter the two prime numbers ->\n");
        printf("P -> ");
        scanf("%d",&p);
        printf("Q -> ");
        scanf("%d",&q);
        if(isPrime(p) && isPrime(q))
        {
            break;
        }
        else{
            printf("***** ENTER THE PRIME NUMBER *****\n\n");
        }
    }

    n = p*q;
    phi = (p-1)*(q-1);
    printf("\n\nValue of n = p*q is           -> %d\n",n);
    printf("Value of phi = (p-1)*(q-1) is -> %d\n",phi);

    printf("\nEnter the Value of e : ");
    scanf("%d",&e);

    while(e<phi){
        count = gcd(e,phi);
        if(count==1)
            break;
        else
            e++;
    }

    do {
        s = (d*e)%phi;
        d++;
    } while (s != 1);

    d = d-1;

    printf("\nIf e = %d then the value of d is -> %d\n", e, d);
    printf("\nPublic Key  --> {%d, %d}",e,n);
    printf("\nPrivate Key --> {%d, %d}\n",d,n);
    printf("\nEnter the Plain Text : ");
    scanf("%d",&m);
    encrypt(m);
    decrypt(c);
}
