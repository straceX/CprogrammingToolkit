#include <math.h>

/*A palindromic number or numeral palindrome is a number that remains
 the same when its digits are reversed. Like 16461 [1]
 [1]: https://en.wikipedia.org/wiki/Palindromic_number */
int is_palindrome(const int val)

/*Prime number query function*/
int is_prime(unsigned int );

/**/
int *division_steps(int);

/**/
int division_steps_sum(int);

/*Max 20! calculate x64 system*/
unsigned long long factorial(size_t);

/* nPr | n max 20*/
unsigned long long Permutations(size_t,size_t);

/* nCr | n max 20*/
unsigned long long Combinations(size_t,size_t);


/*The greatest common divisor is also known as the greatest common factor (gcf),
highest common factor (hcf),greatest common measure (gcm) or highest common divisor.*/
int greatest_common_divisor(int,int);

/* In arithmetic and number theory, the least common multiple 
(also called the lowest common multiple or smallest common multiple) of two integers a and b, usually denoted by LCM(a, b) */
int least_common_multiple(int,int);

/*Function return fibonacci number first second parameter length*/
int *get_fibonacci_numbers(int [], size_t);

/*Armstrong number query function*/
int is_armstrong_number(int number);

/*Inverse number like 1234->4321*/
int inverse_number(const int number);

/* 2620, 2924 are Niven (Harshed) numbers.
2620,divided by 10 : 10 = 2 + 6 + 2 + 0
2924,divided by 17 : 17 = 2 + 9 + 2 + 4
[1] : https://en.wikipedia.org/wiki/Harshad_number */
int is_harshad_numbers(const int,const int);

/*The binomial coefficients appear as the entries of Pascal's triangle where each entry is the sum of the two above it.*/
int *binomial_coefficients(const int level);