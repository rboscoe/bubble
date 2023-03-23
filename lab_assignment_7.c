#include <stdio.h>

//Function utilizing bubble sort with swap counter array to track each index
void bubbleSort(int array[], int n, int swapC[])
{
    int i, j, temp;

    //Fill the swap count array with zeroes
    for (i = 0; i < n; i++) 
    {
        swapC[i] = 0;
    }
    
    //Perform bubble sort and count swaps during each pass and at which index
    for (i = 0; i < n - 1; i++) 
    {    
    //To count how many swaps occur during each pass, we reset to 0 on each pass
    int swapP = 0;

        for (j = 0; j < n - i - 1; j++) 
        {
            //Check whether an element at an index needs to be swapped with the next number
            if (array[j] > array[j + 1]) 
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                //Counts up the index location for each swap
                swapC[j]++;
                //Counts up the total amount of swaps that occur on each pass
                swapP++;
            }
        }
        //Prints swaps per pass
        printf("Amount of swaps in pass #%d: %d\n", i+1, swapP);
    }
}

//Function for printing the array
void printArray(int array[], int size)
{
    int i;
    printf("Sorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//Function for printing the amount of swaps needed per index
void printSwaps(int swapC[], int size)
{
    int i;
    printf("Total swaps per index:\n|| ");
    for (i = 0; i < size; i++) 
    {
        printf("Index %d: %d  || ", i, swapC[i]);
    }
    printf("\n");    
}

//Main
int main()
{
    int array[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size = sizeof(array) / sizeof(array[0]);
    int swapC[size];

    //We call each funtion to sort and then print the necessary information
    bubbleSort(array, size, swapC);
    printSwaps(swapC, size);
    printArray(array, size);    

    return 0;
}