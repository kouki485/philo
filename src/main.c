#include "../include/philo.h"

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q philo");
//}


void	terminate_program(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->shared_mutex);
	data->is_finished = 1;
	pthread_mutex_unlock(&(data->shared_mutex));
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks_mutex[i]);
		i++;
	}
	pthread_mutex_unlock(&(data->shared_mutex));
	pthread_mutex_destroy(&data->shared_mutex);
/*	while(i < data->number_of_philo)
	{
		pthread_mutex_destroy(&(data->forks_mutex[i]));
		if (data->philos[i] != NULL)
			free(data->philos[i]);
		if (data->monitors[i] != NULL)
			free(data->monitors[i]);
		i++;
	}
	if (data->philos != NULL)
		free(data->philos);
	if (data->monitors != NULL)
		free(data->monitors);*/
}

int	main(int argc, char **argv)
{
	t_data data;

	memset(&data, 0, sizeof(t_data));
	if ((argc != 5 && argc != 6) || ft_isnum(argc - 1, argv) == false)
	{
		printf(RED"Invalid input!\n");
		print_help();
		return (0);
	}
	if(check(argc, argv) == false || init_data(&data, argc, argv) == false)
		return (0);
	create_thread(&data);
	join_thread(&data);
}

/*
memsetの追加。

mallocのエラー処理を足した。

atoiをft_atoiに変更。

put_errorをprintfに変更し関連を削除。

見やすくするために色付け。

200人以上philoのエラー処理の追加。

整合性を高めるために、voidからboolに変更。

make時にphiloの絵が出るようにした。(makeするたびechoされるのでこれは審議)

.hのインデント周りの修正。

atoiの0~INT_MAX以外を弾くようにした。

usageを追加。

atoiの文字が入ってきた場合のエラー処理を追加。(001などは弾く必要ないと思ってるので追加していない)

ヘッダーファイルを見やすくした。

アンダーバーの追加　（putdownなど)。

actionごとに色付けした。
*/
