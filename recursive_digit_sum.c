#include <stdio.h>
#include <string.h>

long long sum_of_digits(long long num) {
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

long long super_digit(long long num) {
    if (num < 10) {
        return num;
    }
    return super_digit(sum_of_digits(num));
}

int main() {
    char n[100001];
    int k;
    scanf("%s %d", n, &k);

    long long initial_sum = 0;
    for (int i = 0; i < strlen(n); i++) {
        initial_sum += n[i] - '0';
    }

    long long total_sum = initial_sum * k;
    printf("%lld\n", super_digit(total_sum));

    return 0;
}

