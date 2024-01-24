#include <stdio.h>

int main()
{
    int arr[10] = {3,67,23,12,35,84,8,1,16,28};

    int size = sizeof(arr)/sizeof(arr[0]);
    // printf("%d", size);
    for (int i = 0; i < size; i++)
    {
        int flag = -1;
        for (int j = 0; j < (size-i-1); j++)
        {
            if (arr[j]>arr[j+1])
            {
                flag = 1;
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
            
        }
        
        if (flag == -1)
        {
            break;
        }
        
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}