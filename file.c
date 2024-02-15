	int number_of_num;
	int i;
	t_data *data_start;
	int b;
	my_data = (t_data *)malloc(sizeof(t_data));
	data_start = my_data;
	while (i < number_of_num - 1)
	{
		my_data->next = (t_data *)malloc(sizeof(t_data));
		my_data = my_data->next;
		i++;
	}




void parsing_data(char **argv, int argc, t_data *my_data)