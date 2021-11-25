//S21233_Ganesh Shelar
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct School
{
    int id;
    char name[20];
    float marks;
} stud;
void create(stud s[20], int n)
{
    printf("\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter a name :");
        scanf(" %s", &s[i].name);
        printf("Enter a Roll no. :");
        scanf(" %d", &s[i].id);
        printf("Enter a Marks :");
        scanf(" %f", &s[i].marks);
        printf("\n");
    }
}

void display(stud s[20], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("[%d.] --> NAME : %s\tROLL_No. : %d\tMARKS : %f\n", i + 1, s[i].name, s[i].id, s[i].marks);
    }
}

void bubble_sort(stud s[20], int n)
{
    stud temp;
    int i, j;
    printf("\n");
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (s[j].id > s[j + 1].id)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void insertionSort(stud s[20], int n)
{
    stud temp;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, temp.name) > 0)
        {
            s[j + 1] = s[j];
            --j;
        }
        s[j + 1] = temp;
    }
}

void lsearch(stud s[20], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (key == s[i].marks)
            printf(" NAME : %s\tROLL_No. : %d\tMARKS : %f\n", s[i].name, s[i].id, s[i].marks);
    }
}

int bsearch(stud s[20], char ch[20], int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(ch, s[mid].name) == 0)
        {
            return mid;
        }
        else if (strcmp(ch, s[mid].name) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int partition(stud s[20], int l, int u)
{
    int i, j;
    stud temp, p;
    p = s[l];
    i = l;
    j = u + 1;
    do
    {
        do
        {
            i++;
        } while (s[i].marks < p.marks && i <= u);
        do
        {
            j--;
        } while (p.marks < s[j].marks);

        if (i < j)
        {
            temp = s[j];
            s[i] = s[j];
            s[j] = temp;
        }
    } while (i < j);
    s[l] = s[j];
    s[j] = p;

    return (j);
}

void quick_sort(stud s[20], int l, int u)
{
    int j;
    if (l < u)
    {
        j = partition(s, l, u);
        quick_sort(s, l, j - 1);
        quick_sort(s, j + 1, u);
    }
}

void dash(int n)
{
    int s;
    for (s = 0; s < n; s++)
        printf("-");
}
int main()
{
    stud s[20];
    int choice, n, count, key, result, i;
    char ch[20];
    printf("\n<<----REPORT OF THE STUDENT DATA---->>\n");
    printf("\nEnter a No. of records to be stored:");
    scanf("%d", &n);
    dash(30);
    create(s, n);
    dash(30);
    do
    {
        printf("\n1:Display the database.\t\t4:LinearSearch.\n2:Perform BubbleSort.\t\t5:BinarySearch.\n3:InsertionSort.\t\t6:QuickSort.\n\t\t7:EXIT.");
        printf("\nSelect a choice(1,2,3,4,5,6,7) :");
        scanf("%d", &choice);
        dash(50);
        switch (choice)
        {
        case 1:
            printf("\n<--DISPLAYING THE DATA-->\n");
            display(s, n);
            printf("\n");
            break;
        case 2:
            printf("\n<--BubbleSort Operation on RollNo-->\n");
            bubble_sort(s, n);
            for (i = 0; i <= n - 1; i++)
            {
                printf("[%d.] --> NAME : %s\tROLL_No. : %d\tMARKS : %f\n", i + 1, s[i].name, s[i].id, s[i].marks);
            }
            break;
        case 3:
            printf("\n<--Insertion Operation on Name-->\n");
            insertionSort(s, n);
            for (i = 0; i < n; i++)
            {
                printf("[%d.] --> NAME : %s\tROLL_No. : %d\tMARKS : %f\n", i + 1, s[i].name, s[i].id, s[i].marks);
            }
            break;
        case 4:
            printf("\n<--LinearSearch (MARKs)-->\n");
            printf("\nEnter a Mark u want to search :");
            scanf("%d", &key);
            lsearch(s, n, key);
            break;
        case 5:
            printf("\n<--BinarySearch (MARKs)-->\n");
            printf("\nEnter a NameOfStudent u want to search :");
            scanf(" %s", &ch);
            insertionSort(s, n);
            result = bsearch(s, ch, 0, (n - 1));
            if (result == -1)
            {
                printf("Invalid Student Name !!!\n");
            }
            else
            {
                printf("The student -'%s' is in the list.\nMarks:%f\tRollNo.:%d\n", s[result].name, s[result].marks, s[result].id);
            }

            break;
        case 6:
            printf("\n<--QuickSort-->\n");
            quick_sort(s, 0, n - 1);
            for (i = n - 1; i >= n - 10; i--)
            {
                printf(" NAME : %s\tROLL_No. : %d\tMARKS : %f\n", s[i].name, s[i].id, s[i].marks);
            }
            break;
        case 7:
            printf("\n<--Exit-->");
            break;
        default:
            printf("\nINVALID SELECTION!!\n");
            break;
        }
        printf("\nEnter 0 - 'QUIT' and 1 - 'CONTINUE' -->");
        scanf("%d", &count);
        dash(50);
    } while (count == 1);
    dash(50);
    printf("\nThanks !!\n");
    return 0;
    getch();
}
