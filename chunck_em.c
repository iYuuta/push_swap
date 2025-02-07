#include "push_swap.h"

int get_largest(t_stack *a)
{
    int     t;
    t_stack *temp;

    temp = a;
    t = a->data;
    while (temp)
    {
        if (t < temp->data)
            t = temp->data;
        temp = temp->next;
    }
    return (t);
}
void chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
    int chunk_size;
    int len = ft_ft_lstsize(*stack_a);
    int num_chunks = 3;  // Divide the stack into 3 chunks
    chunk_size = len / num_chunks;  // Determine size of each chunk (adjust if necessary)

    // Iterate through the chunks
    while (*stack_a)
    {
        // Define the chunk range (this is just an example, adjust for your logic)
        int smallest = get_smallest(*stack_a);  
        int largest = get_largest(*stack_a);  

        // Move the elements into stack_b until we have a chunk
        while (*stack_a && (*stack_a)->data <= largest && (*stack_a)->data >= smallest)
        {
            pa_pb(stack_b, stack_a, "pb\n");
        }

        // Sort the chunk in stack_b
        int chunk_len = ft_ft_lstsize(*stack_b);
        
        if (chunk_len > 3 && chunk_len <= 5)
            sort_five(stack_b, stack_a);  // Sort the chunk using your 3-5 function
        else if (chunk_len >= 6 && chunk_len <= 9)
            sort_less_than_10(stack_b, stack_a);  // Sort the chunk using your 6-9 function

        // Push the sorted chunk back to stack_a
        while (*stack_b)
        {
            pa_pb(stack_a, stack_b, "pa\n");
        }
    }
}
