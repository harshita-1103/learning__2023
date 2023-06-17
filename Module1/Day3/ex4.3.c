#include <stdio.h>

void find_smallest_largest_digits(int *numbers, int n)
{
    if (n == 0)
    {
        printf("Not Valid\n");
        return;
    }

    int smallest_digit = 10;
    int largest_digit = -1;
    int i, j, digit;

    for (i = 0; i < n; i++)
    {
        int num = numbers[i];
        char num_str[20];
        sprintf(num_str, "%d", num);

        for (j = 0; num_str[j] != '\0'; j++)
        {
            if (num_str[j] >= '0' && num_str[j] <= '9')
            {
                digit = num_str[j] - '0';
                smallest_digit = (digit < smallest_digit) ? digit : smallest_digit;
                largest_digit = (digit > largest_digit) ? digit : largest_digit;
            }
        }
    }

    if (smallest_digit == 10 || largest_digit == -1)
    {
        printf("Not Valid\n");
    }
    else
    {
        printf("Smallest digit: %d\n", smallest_digit);
        printf("Largest digit: %d\n", largest_digit);
    }
}

int main()
{
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int numbers[100];
    int i;

    printf("Enter the values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    find_smallest_largest_digits(numbers, n);

    return 0;
}