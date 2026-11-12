#include <stdio.h> 

int main()
{
    int numbers[] = { 7, 0, 9, 7, 8, 26, 7, 12, 13, 3, 56, 7, 3, 6, 9, 12 };
    int* checkedNums;
    int checkedNumsIndex = 0;
    bool checked = false;
    int key;
    int value = 0;
    int count;

    // sizeof() liefert die Anzahl der bytes 
    // da ich aber nur die anzahl der Elemente benötige  
    // wird die summer der elementgrößen durch die größe von einem element dividiert
    // das Ergebnis ist dann die Anzahl der Elemente (ersetzt die .length() funktion aus z.b.Java)
    checkedNums = new int[sizeof(numbers) / sizeof(numbers[0])];
    key = numbers[0];

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        checked = false;
        count = 0;

        for (int j = 0; j < checkedNumsIndex; j++)
        {
            if (checkedNums[j] == numbers[i])
            {
                checked = true;
                break;
            }
        }

        if (checked)
        {
            continue;
        }

        for (int j = i; j < sizeof(numbers) / sizeof(numbers[0]); j++)
        {
            if (numbers[i] == numbers[j])
            {
                count++;
            }
        }

        if (count > value)
        {
            key = numbers[i];
            value = count;
        }

        checkedNums[checkedNumsIndex] = numbers[i];
        checkedNumsIndex++;
    }

    printf("%d kommt %d mal vor.", key, value);

    return 0;
}