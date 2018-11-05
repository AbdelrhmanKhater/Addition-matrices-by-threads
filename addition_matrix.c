#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<pthread.h>
int arr1[20][20], arr2[20][20], arr3[20][20];
struct Node
{
    int i, j;
};
void* addMatrix(void* arg)
{
      struct Node *n = (struct Node*) arg;
      arr3[n->i][n->j] = arr1[n->i][n->j] + arr2[n->i][n->j];
}
int main()
{
    int r, c, i;
    pthread_t threads[400];
    struct Node *n1 = (struct Node*) malloc((void*)sizeof(struct Node));
    printf("Please, insert r and c\n");
    scanf("%d %d", &r, $c);
    printf("Please, insert mat1\n");
    for (i = 0; i < r * c; ++i)
        scanf("%d", &arr1[i / c][i % c]);
    printf("Please, insert mat2\n");
    for (i = 0; i < r * c; ++i)
        scanf("%d", &arr2[i / c][i % c]);
    for (i = 0;i < r * c; ++i)
    {
        n1->i = i / c;
        n1->j = i % c;
        pthread_create(&threads[i], NULL, addMatrix, (void*)n1);
        pthread_join(threads[i], NULL);
    }
    printf("Output =\n");
    for (i = 0; i < r * c; ++i)
    {    
        if ( i != 0 && (i % c) == 0)
           printf("\n");
        printf("%d ", arr3[i / c][i % c]);
    }
    printf("\n");
    return 0;
}
