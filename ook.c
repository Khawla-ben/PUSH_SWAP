
void do_it(t_list	**stack_a, t_list	**stack_b, int *sum, int *p, int count)
{
	int middle;
	int	size;
	int	i;
	int j;

	size = ft_lstsize(*stack_a);
	middle = (size / 2);
	if ((size % 2) != 0)
		middle +=1;
		// printf("%d\n",count);
		// printf("%d-------",middle);
	// printf("....%d....\n",sum[count]);
	// puts("hhh");
	// printf("....%d....\n",sum[0]);
	// printf("....%d....\n",sum[1]);
	// i = sum[count];
	i = 0;
	j = sum[count] - 1 ;
	if (p[i] < middle) // i ghalaaaaaat
	{
			// puts("lll");
		while (j > 0)
		{
			ra(stack_a);
			j--;
		}
		pa(stack_b,stack_a);
	}
	else if (p[i] > middle)
	{
			// puts("ldcjdsc");
		while (j > 0)
		{
			rra(stack_a);
			j--;
		}
		pa(stack_b,stack_a);
	}
	// print_c(*stack_a,*stack_b);
}