#include <stdio.h>

int main()
{
    int n = 5;
    int arr[5] = {11, 2, 1, 4, 23};

    int curr = 0;

    while (curr < n)
    {
        printf("\nPass %d\n", curr + 1);
        for (int i = curr + 1; i < n; i++)
        {
            if (arr[i] < arr[curr])
            {
                int temp = arr[i];
                arr[i] = arr[curr];
                arr[curr] = temp;
            }
        }
        printf("State of array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        curr++;
    }
}