#include <stdio.h>

# define SIZE 100

float	compute_disorder(int *arr)
{
	int	mistakes;
	int	total_pairs;
	int i;
	int j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < SIZE)
	{
		j = i + 1;
		while (j < SIZE)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	printf("Mistakes = %d, Total pairs = %d\n", mistakes, total_pairs);
	return ((float)mistakes / (float)total_pairs);
}


int	main()
{
	// Ordered array - disorder should be 0
	int 	arr_0[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
	// Disordered array - disorder should be > 0 and < 1
	int 	arr_rand[SIZE] = {42, 17, 89, 5, 63, 28, 91, 34, 76, 12, 55, 3, 98, 21, 47, 69, 14, 82, 36, 7, 93, 25, 60, 11, 78, 44, 1, 86, 31, 52, 19, 73, 8, 95, 40, 66, 23, 84, 15, 57, 99, 30, 71, 4, 88, 26, 62, 10, 45, 79, 18, 96, 33, 54, 2, 81, 39, 67, 13, 90, 24, 58, 6, 75, 41, 97, 20, 64, 9, 85, 37, 50, 16, 92, 29, 70, 43, 100, 22, 61, 35, 80, 48, 94, 27, 56, 68, 32, 87, 46, 72, 38, 59, 83, 49, 74, 53, 65, 77, 0};
	// Disordered array - disorder should be 1
	int		arr_1[SIZE] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 90,89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	// Variables to store result of compute_disorder
	float	disorder_metric_0;
	float	disorder_metric_rand;
	float	disorder_metric_1;

	printf("\n---METRICS TO COMPUTE [ORDERED ARRAY (0)]---\n");
	disorder_metric_0 = compute_disorder(arr_0);
	printf("\n---METRICS TO COMPUTE [DISORDERED ARRAY (rand)]---\n");
	disorder_metric_rand = compute_disorder(arr_rand);
	printf("\n---METRICS TO COMPUTE [DISORDERED ARRAY (1)]---\n");
	disorder_metric_1 = compute_disorder(arr_1);

	printf("\n---CALCULATING DISORDER METRIC---\n");
	printf("[ORDERED ARRAY (0)]         : %f\n", disorder_metric_0);
	printf("[DISORDERED ARRAY (rand)]   : %f\n", disorder_metric_rand);
	printf("[DISORDERED ARRAY (1)]      : %f\n", disorder_metric_1);

	return (0);
}