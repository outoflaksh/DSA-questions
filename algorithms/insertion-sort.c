#include <stdio.h>

int main()
{
    int n = 5;
    int arr[5] = {11, 2, 1, 4, 23};

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        printf("\nState of array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}