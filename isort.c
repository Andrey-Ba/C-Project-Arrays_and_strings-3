#include <stdio.h>

#define N 50

void shift_element(int* arr, int i)
{
    for(int j = i-1; j>=0; j--)
    {
        *(arr+j+1) = *(arr+j);
    }
}

void insertion_sort(int* arr, int len)
{
    for(int i = 1; i<len; i++)
    {
        if(*(arr+i) < *(arr+i-1))
        {
            int j = i-1;
            while (j > 0 && *(arr+j-1) > *(arr+i))
            {
                j--;
            }
            int temp = *(arr+i);
            shift_element(arr+j,i-j);
            *(arr+j) = temp;
        }
        
    }
}

void print_array(int *arr, int len)
{
    for(int i = 0; i<len-1; i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+len-1));
}

int main()
{
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        //Make sure that the input is a number
        if(scanf(" %d",arr+i)<=0)
        {
            //"Swallow" the char
            getchar();
            i--;
        }
    }
    insertion_sort(arr, N);
    print_array(arr,N);

    return 0;
}