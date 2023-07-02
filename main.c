#include <stdio.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define loop(arr, index)                                \
{                                                       \
    for (int i = index; i < ARR_SIZE(arr); index = i)   \
    {                                                   \
        i += 1;                                             

#define loop_end }}

int main(void) {
    int a[] = {1,2,3,5,7,0};
    int index = 0;

    loop(a, index)
        printf("item: %d\n", a[index]);
    loop_end
}