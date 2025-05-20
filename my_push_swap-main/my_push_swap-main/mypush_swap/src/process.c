#include "push_swap.h"
#include <stdlib.h>

int	is_sorted(t_stack *stack)
{
    t_stack *current;

    if (!stack)
        return (1); // Boş liste sıralı kabul edilir
    current = stack;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0); // Sıralı değil
        current = current->next;
    }
    return (1); // Sıralı
}


void	exit_if_sorted(t_stack **stack_a, t_stack **stack_b)
{
    if (is_sorted(*stack_a))
		exit(1);
    
}

int get_stack_size(t_stack *stack)
{
    int     count;
    t_stack *current;

    count = 0;
    current = stack;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

void assign_indices(t_stack *stack, int size)
{
    t_stack *current;
    int     *array;
    int     i;
    int     j;
    int     temp;

    // Bellek ayırma
    array = (int *)malloc(sizeof(int) * size);
    if (!array)
        return;
    
    // Stack değerlerini diziye kopyala
    current = stack;
    i = 0;
    while (current)
    {
        array[i++] = current->value;
        current = current->next;
    }
    
    // Diziyi sırala (Bubble Sort kullanarak)
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    // Her stack elemanına sıralanmış dizideki konumlarını indeks olarak ata
    current = stack;
    while (current)
    {
        for (i = 0; i < size; i++)
        {
            if (current->value == array[i])
            {
                current->index = i;
                break;
            }
        }
        current = current->next;
    }
    
    // Belleği temizle
    free(array);
}

void sort_three(t_stack **a)
{
    t_stack *first, *second, *third;
    
    // Stack boş veya eleman sayısı 3'ten azsa işlem yapma
    if (!*a || !(*a)->next || !(*a)->next->next || (*a)->next->next->next)
        return;
    
    first = *a;
    second = first->next;
    third = second->next;
    
    // İlk eleman en büyükse
    if (first->value > second->value && first->value > third->value)
    {
        ra(a);  // İlk elemanı en sona gönder
    }
    // İkinci eleman en büyükse
    else if (second->value > first->value && second->value > third->value)
    {
        rra(a); // Son elemanı başa getir
    }
    
    // İlk iki elemanın sırası yanlışsa
    if ((*a)->value > (*a)->next->value)
    {
        sa(*a);   // İlk iki elemanı değiştir
    }
}

// En küçük değerin indeksini bulma fonksiyonu
int find_min_index(t_stack *a)
{
    t_stack *current;
    int min_value;
    int min_index;
    int current_index;
    
    if (!a)
        return (-1);
    
    min_value = a->value;
    min_index = 0;
    current_index = 0;
    current = a->next;
    
    while (current)
    {
        current_index++;
        if (current->value < min_value)
        {
            min_value = current->value;
            min_index = current_index;
        }
        current = current->next;
    }
    
    return (min_index);
}

void sort_small(t_stack **a, t_stack **b)
{
    int min_index;
    int size;
    
    while (get_stack_size(*a) > 3)
    {
        // En küçük elemanın indeksini bul
        min_index = find_min_index(*a);
        size = get_stack_size(*a);
        
        // En küçük eleman başa gelene kadar döndür
        while (min_index > 0)
        {
            if (min_index <= size / 2) // Eğer en küçük eleman ortadan önce ise
                ra(a);               // İleri döndür
            else
                rra(a);              // Geri döndür
            
            // İndeksleri güncelle
            min_index = find_min_index(*a);
        }
        
        // En küçük eleman stack b'ye aktar"
        pb(a, b);
    }
	    // Kalan 3 elemanı sırala
    if (get_stack_size(*a) == 3)
        sort_three(a);
    else if (get_stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
        sa(*a);
    
    // B'deki elemanları A'ya geri aktar
    while (*b)
        pa(a, b);
}

void    start_process(t_stack **a, t_stack **b)
{
    int	size;

	size = get_stack_size(*a);
	assign_indices(*a, size);
	if (size == 2)
		sa(*a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
	{
		sort_large_stack(a, b, size);
		push_back_to_a(a, b);
	}
}