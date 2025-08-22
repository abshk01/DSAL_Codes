

void BubbleSort(int[],int,int);
void swap(int*, int*);
void swapArth(int*, int*);

int Arr[MAXSIZE], size,order;
int main(){\
    printf("Bubble Sort - ");
    printf("Enter the no of elements: (Max size %d) -> ",MAXSIZE);

    scanf("%d",&size);
    for(int i = 0; i< size; i++){
        printf("Enter Element %d -> ", i+1);
        scanf("%d",&Arr[i]);
    }
    printf("Ascending or Descending (1/2) -> ");
    scanf("%d",&order);
    BubbleSort(Arr,size,order);
    return 0;

}
// Function with arguments but no Return Type
void BubbleSort(int Arr[],int n,int order){
    int i, j;

    if (order != 2) {
        if (order != 1) {
            printf("Invalid Order selected, Sorting in Acending Order");
        }
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (Arr[j] > Arr[j + 1]) {
                    swap(&Arr[j], &Arr[j + 1]);
                }}}}
    if (order == 2){
        printf("Sorting in Descending Order");
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (Arr[j] < Arr[j + 1]) {
                    swapArth(&Arr[j], &Arr[j + 1]);
                }}}}

    printf("\n List after sorting -> \n");
    for(int f = 0; f< n; f++){
        printf(" %d ", Arr[f]);}

}
// The following functions are used made to demonstrate diffrent methods for swapping
void swap(int* num1, int* num2){
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}
void swapArth(int* num1, int* num2){
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}
void swapBit(int* num1, int* num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}


