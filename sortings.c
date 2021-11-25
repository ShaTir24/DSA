/* Program to implement all sorting algorithms in C
    By - Tirth Shah
    Date - 25-11-2021
    Time - 18:20
*/
#include<stdio.h>

int arr[100], cap;  //arr storing the user-input array, cap stores the size of the array

void printArr(int arr[], int n) {   //member method to display the array
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//quick sort [DESCENDING]
int partition(int l, int h, int arr[]) {    //method to find the correct sorted position of the element in array
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j) { //condition untill final swap is done
        while(pivot < arr[i])   //moving i forward until element lesserr than pivot is found
            i++;    
        while(pivot >= arr[j])  //moving j backward until element greater than pivot is found
            j--;
        if(i < j) { //no need to swap if it is already in sorted position
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
   int temp = arr[j];
   arr[j] = arr[l];
   arr[l] = temp;
    return j;   //j denotes the final correct sorted position of element
}
void quickSort(int l, int h) {  //method to sort the other elements in recursive manner
    if(l < h) {
        int j = partition(l, h, arr);   //correct position of element
        quickSort(l, j);    //sorting first part(with greater elements than pivot)
        quickSort(j + 1, h);    //sorting second part(with lesser elements than pivot)
    }
}

//merge sort [ASCENDING]
void merge(int arr[], int l, int m, int r) {    //method to merge the two arrays into original array by comparing the values from both arrays
    int n1 = m - l + 1; //n1 stores the size of first half
    int n2 = r - m; //n2 stores the size of second half
    int ar1[n1], ar2[n2];   //respective arrays

    for(int i = 0; i < n1; i++) //copying elements in array 1
        ar1[i] = arr[l + i];

    for(int i = 0; i < n2; i++) //copying elements in array 2
        ar2[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;    //i - pointer variable for ar1, j - pointer variable for ar2, k - pointer variable for arr
    while(i < n1 && j < n2) {   //stop merging if any one array is reached to its end
        if(ar1[i] > ar2[j]) {
            arr[k] = ar2[j];    //condition for element of ar2 will be smaller
            j++;
        }
        else {
            arr[k] = ar1[i];    //condition for element of ar1 will be smaller
            i++;
        }
        k++;
    }
    while(i < n1) { //if ar1 remains incomplete and ar2 completes in above process
        arr[k] = ar1[i];    //copying the elements in original array
        i++;
        k++;
    }
    while(j < n2) { //if ar2 remains incomplete and ar1 completes in above process
        arr[k] = ar2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {   //member method to sort array using recursive approach by dividing it into two equal halves
    if(l >= r)
        return;
    int m = l + (r - l) / 2;    //m denotes mid index
    mergeSort(arr, l, m);   //first half
    mergeSort(arr, m + 1, r);   //second half
    merge(arr, l, m, r);    //to sort individual arrays
}

void main() {
    printf("Enter the size of array : ");
    scanf("%d", &cap);
    for(int i = 0; i < cap; i++) {
        printf("Enter the element %d : ", (i + 1));
        scanf("%d", &arr[i]);
    }
    //bubble sort [ASCENDING]
    for(int i = 0; i < cap; i++) {  //each occurence of it represents a pass to sort one element
        for(int j = 0; j < cap - i - 1; j++) {  //loop to compare adjacent elements
            if(arr[j] > arr[j+1]) {
                arr[j + 1] = arr[j] + arr[j + 1];   //swapping
                arr[j] = arr[j + 1] - arr[j];
                arr[j + 1] = arr[j + 1] - arr[j];
            }
        }
    }
    printf("\nSorting Ascending using Bubble sort : \n");
    printArr(arr, cap);

    //selection sort [DESCENDING]
    for(int i = 0; i < cap - 1; i++) {  //each pass gives one sorted element
        int max = arr[i];   //for comparing
        int loc = i;    //for storing index
        for(int j = i + 1; j < cap; j++) {  //compring elements from next index
            if(arr[j] > max) {
                max = arr[j];   //storing greater element in max
                loc = j;    //storing its position
            }
        }
        int temp = arr[loc];    //finally swapping the greates element with element at i
        arr[loc] = arr[i];
        arr[i] = temp;
    }
    printf("\nSorting Descending using Selection sort : \n");
    printArr(arr, cap);

    //insertion sort [ASCENDING]
    for(int i = 1; i < cap; i++) {  //passes till last element
        int curr = arr[i];  //storing a copy of element for comparing and restoring
        int j = i - 1;  //position of element who is being compared
        while(j >= 0 && arr[j] > curr) {    //utill a lesser element is not found, 
            arr[j + 1] = arr[j];            //elements are being replaced in ascending order
            j--;
        }
        arr[j + 1] = curr;  //restoring the element in sorted position
    }
    printf("\nSorting Ascending using Insertion sort : \n");
    printArr(arr, cap);

    //quick sort
    quickSort(0, cap - 1);
    printf("\nSorting in Descending order using Quick sort : \n");
    printArr(arr, cap);

    //merge sort
    mergeSort(arr, 0, cap - 1);
    printf("\nSorting in Ascending order using Merge sort : \n");
    printArr(arr, cap);
}