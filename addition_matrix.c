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
    int n, i;
    pthread_t threads[400];
    struct Node *n1 = (struct Node*) malloc((void*)sizeof(struct Node));
    scanf("%d", &n);
    for (i = 0; i < n * n; ++i)
        scanf("%d", &arr1[i / n][i % n]);
    for (i = 0; i < n * n; ++i)
        scanf("%d", &arr2[i / n][i % n]);
    for (i = 0;i < n * n; ++i)
    {
        n1->i = i / n;
        n1->j = i % n;
        pthread_create(&threads[i], NULL, addMatrix, (void*)n1);
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < n * n; ++i)
    {    
        if ( i != 0 && (i % n) == 0)
           printf("\n");
        printf("%d ", arr3[i / n][i % n]);
    }
    return 0;
}
