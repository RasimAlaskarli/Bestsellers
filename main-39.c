#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct product{
    int num;
    int num2;
    char name[100];
    int amount;
};
int Compare(const void* a, const void* b)
{
    struct product arg1 = *(struct product*)a;
    struct product arg2 = *(struct product*)b;
 
    if (arg1.amount < arg2.amount) return 1;
    if (arg1.amount > arg2.amount) return -1;
    return 0;
}
struct product Indexing(struct product *items, long long int size){
    int from = 0;
    int to = -1;
    for (int i = 0; i < size; i++) {
        items[i].num = i+1;
        items[i].num2 = 0;
    }
    for (int i = 0; i<size-1; i++) {
        from = i;
        while(items[i].amount == items[i+1].amount){
            if(i >= size-1){
                break;
            }
            to = i+1;
            i++;

        }
        if(from <= to){
            for (int i = from; i <= to; i++) {
                int tmp = items[to].num;
                items[i].num = items[from].num;
                items[i].num2 = tmp;
            }
        }
    }
    
    return *items;
}
int main(void) {
    long long int max = 100;
    struct product *items = (struct product*)malloc(sizeof(*items)*max);

    int index = 0;
    long long int size = 0;
    int scan;
    char c;
    char newItem[101];

    int top;
    printf("Top N:\n");
    if(scanf("%d", &top)!= 1 || top < 1){
        printf("Invalid input.\n");
        free(items);
        items = NULL;
        return 0;
    }
    printf("Requests:\n");
    while((scan = (scanf(" %c", &c) != EOF)))
    {
        if(scan != 1){
            printf("Invalid input.\n");
            free(items);
            items = NULL;
            return 0;
        }
        if(c == '+'){
            if((scanf("%s", newItem)) != 1){
                printf("Invalid input.\n");
                free(items);
                items = NULL;
                return 0;
                
            }
            if(strlen(newItem) >= 100){
                printf("Invalid input.\n");
                free(items);
                items = NULL;
                return 0;
            }
            if(size == max){
                max*=2;
                items = (struct product*)realloc(items, sizeof(struct product)*max);

            }
            int tmp = 0;
            for (int i = 0; i < size; i++) {
                if(strcmp(items[i].name, newItem) == 0){
                    tmp++;
                    index = i;
                }
            }
            if(tmp > 0){
                items[index].amount++;
            }
            else{
                strcpy(items[size].name, newItem);
                items[size].amount = 1;
                size++;

            }

        }



        int topsellers = 0;
        if(c == '#'){
            qsort(items, size, sizeof(struct product), Compare);

            *items = Indexing(items, size);
            for (int i = 0; i < size; i++) {
                if(items[i].num <= top){
                    if(items[i].num2 == 0){
                        printf("%d. %s, %dx\n", items[i].num, items[i].name, items[i].amount);
                    }
                    else{
                        printf("%d.-%d. %s, %dx\n", items[i].num, items[i].num2, items[i].name, items[i].amount);
                    }
                    topsellers+=items[i].amount;
                }

            }
            printf("Top sellers: sold %d items\n", topsellers);
        }
        if(c == '?'){
            qsort(items, size, sizeof(struct product), Compare);
            *items = Indexing(items, size);
            for (int i = 0; i<size; i++) {
                if(items[i].num <= top){
                    topsellers+=items[i].amount;
                }
            }
            printf("Top sellers: sold %d items\n", topsellers);
        }
        if(c != '+' && c != '#' && c != '?'){
            printf("Invalid input.\n");
            free(items);
            items = NULL;
            return 0;
        }
    }
    free(items);
    items = NULL;
    return 1;
}
