    #include <stdio.h>
    #include <stdlib.h>
    #define size 5

    int front[size] = {-1, -1, -1, -1, -1};
    int rear[size] = {-1, -1, -1, -1, -1};
    int pq[size][size] = {{'a', 'a', 'a', 'a', 'a'}, 
                            {'a', 'a', 'a', 'a', 'a'}, 
                            {'a', 'a', 'a', 'a', 'a'}, 
                            {'a', 'a', 'a', 'a', 'a'}, 
                            {'a', 'a', 'a', 'a', 'a'}};

    void show()
    {
        printf("Displaying Priority Queue:\n");
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(pq[i][j] == 'a')
                {
                    pq[i][j] = '_ ';
                    printf("%c ", pq[i][j]);
                }
                else
                    printf("%d ", pq[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void insert()
    {
        int temp,pr;
        printf("Enter number to be inserted into Queue:\n");
        scanf("%d", &temp);
        printf("Enter Priority:\n");
        scanf("%d", &pr);
        pr--;

        if(rear[pr] == size-1)
            printf("Overflow\n");
        else
        {
            if(rear[pr] == -1)
            {
                front[pr] = 0;
                rear[pr] = 0;
            }
            else
                rear[pr]++;

            pq[pr][rear[pr]] = temp;
            printf("Element is inserted into Queue\n");
        }
    }

    void delete()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(pq[i][j] != 'a')
                {
                    pq[i][j] = 'a';
                }
            }
        }
        printf("No element to be deleted\n");
    }

    int main()
    {
        label:;
        int choice;
        printf("Enter 1 to insert, 2 to delete, 3 to show status, 4 to exit program\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            {
                insert();
                break;
            }

            case 2: 
            {
                delete();
                break;
            }

            case 3: 
            {
                show();
                break;
            }

            case 4: 
            {
                exit(0);
            }
        }

        goto label;

        return 0;
    }
