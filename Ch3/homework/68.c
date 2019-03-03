/* void setVal(str1 *p, str2 *q)
 * p in %rdi, q in %rsi
 *
 * setVal:
 *     movslq  8(%rsi),%rax      &q->t = p + 8
 *     addq    32(%rsi),%rax     &q->u = p + 32
 *     movq    %rax,184(%rdi)    &p->y = p + 184
 *     ret
 *
 * 考虑结构元素地址的对齐:
 * 1. S1 = A * B * 4 <= 184 同时必须为8的倍数,即176 < S1 <= 184,可得44 < A * B <= 46
 * 2. 4 < B <= 8
 * 3. S3 = B + 4 + A * 2 <= 32 同时必须为8的倍数,即24 < S3 <= 32,可得6 < A <= 10
 * 综合上式：A取7，B值无效；A取8,B无效；A取9，B取5；A取10，B无效
 */
/* 对上述不等式的下限说明：对于S1，应保证S1加上间隙空间是8的倍数，若S1小于等于176，那么此时编译器为避免浪费空间，使p+176来满足对齐要求，而不是p+186,其余类似*/
#define A 9
#define B 5
 
 
