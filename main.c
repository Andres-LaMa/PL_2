#include <stdio.h>
#include "IntVector.h"


int main(void)
{
    IntVector *Victor;
    Victor = int_vector_new(10);
    for (short i = 0; i < Victor->capacity; i++)
    {
        Victor->indicator[i] = i;
        Victor->size += 1;
    }
    for (short i = 0; i < Victor->capacity; i++)
    {
    printf("%d ", Victor->indicator[i]);
    }
    printf("\n");
    printf("%d %d\n", Victor->size, Victor->capacity);
    
    
    printf("Добро пожаловать в аттракцион невиданной щедрости!\n");
    printf("Здесь вы можете найти самые разные функции для Vector\n");
    printf("Уже создан Вектор Victor и вы можете провести как над ним так и над другими некоторые действия\n");
    printf("Выберете один из вариантов\n\n");
    printf("1. Создать новый вектор                       \t2. Скопировать старый вектор в новый\n3. Очистить структуру                    \t4. Вывести элемент по определенному индексу\n5. Присвоить значение элементу по индексу \t6. Показать size массива\n");
    printf("7. Показать capasity массива                \t8. Добавить элемент в конец массива\n9. Удалить последний элемент из массива \t10. Уменьшить capacity массиса до его size\n11. Изменить размер массива                \t12. Изменить capacity массива\n\n");
    
    printf("Выберите 1 вариант:\n");
    short choice;
    scanf("%hd", &choice);
    switch (choice)
    {
    case 1:;///создание нового вектора
        printf("Вы выбрали Создать новый массив!\nУкажите его capacity\n");
        int initial_capacity = 0;
        scanf("%d", &initial_capacity);
        IntVector *p_exampe = int_vector_new(initial_capacity);
        int_vector_free(p_exampe);
        break;
    case 2:; ///копирование
        IntVector *p = int_vector_new(10);
        for (short i = 0; i < p->capacity; i++)
        {
            p->indicator[i] = i;
            p->size += 1;
        }
        for (short i = 0; i < p->capacity; i++)
        {
            printf("%d ", p->indicator[i]);
        }
        printf("\n");

        IntVector *p_copy = int_vector_copy(p);
        for (short i = 0; i < p_copy->capacity; i++)
        {
            printf("%d ", p_copy->indicator[i]);
        }
        printf("\n");
        int_vector_free(p);
        int_vector_free(p_copy);
        break;
    case 3:; ///очистка памяти
        int_vector_free(Victor);
        break;
    case 4:; ///взятие эллемента по индексу
        short index = 0;
        scanf("%hd", &index);
        int result = int_vector_get_item(Victor, index);
        printf("%d \n", result);
        break;
    case 5:;///Присвоить значение элементу по индексу
        short index1, item;
        scanf("%hd %hd", &index1, &item);
        int_vector_set_item(Victor, index1, item);
        for (short i = 0; i < Victor->capacity; i++)
        {
        printf("%d ", Victor->indicator[i]);
        }
        printf("\n");
        break;
    case 6:;///Показать size массива
        size_t size = int_vector_get_size(Victor);
        printf("%ld\n", size);
        break;
    case 7:;///Показать capasity массива
        size_t capacity = int_vector_get_capacity(Victor);
        printf("%ld \n", capacity);
        break;
    case 8:;///Добавить элемент в конец массива
        short item1;
        scanf("%hd", &item1);
        int_vector_push_back(Victor,item1);
        for (short i = 0; i < Victor->capacity; i++)
        {
            printf("%d ", Victor->indicator[i]);
        }
        printf("\n");
        break;
    case 9:;///Удалить последний элемент из массива
        int_vector_pop_back(Victor);
        for (short i = 0; i < Victor->size; i++)
        {
            printf("%d ", Victor->indicator[i]);
        }
        printf("\n");
        break;
    case 10:;///Уменьшить capacity массиса до его size
        short check0 = int_vector_shrink_to_fit(Victor);
        printf("%hd \n", check0);
        printf("%d %d\n", Victor->capacity, Victor->size);
        break;
    case 11:;///Изменить размер массива
        short new_size;
        scanf("%hd", &new_size);
        short check1 = int_vector_resize(Victor, new_size);
        printf("%hd \n", check1);
        printf("%d %d\n", Victor->capacity, Victor->size);
        for (short i = 0; i < Victor->size; i++)
        {
            printf("%d ", Victor->indicator[i]);
        }
        printf("\n");
        break;
    case 12:;///Изменить capacity массива
        short new_capacity;
        scanf("%hd", &new_capacity);
        short check2 = int_vector_reserve(Victor, new_capacity);
        printf("%hd \n", check2);
        break;
    default:;
        printf("Вы выбрали несуществующий вариант\n");
        return 0;
        break;
    }
    int_vector_free(Victor);
    return 0;
}