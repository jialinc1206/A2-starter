/*
 * CSE30 S122 HW3
 * Username: cse30s122dv (Fill in your username)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int flagNum(char* flagStr) {
	char* flag_const = "-c";
	int flag_bool = strcmp(flagStr, flag_const);
	if(flag_bool == 0) {
				//printf("-c\n");
		return 1;
	}
	return 0;
}


int main(int argc, char* argv[]) {
	/* Local Variables */
	int in_col_num, out_col_num;
	int input_num = argc;
	char** inputs = argv;

	// flag = 1 if -c is passed in
	int flag = flagNum(argv[1]);
				//printf("flag = %d\n", flag);
				//printf("argc = %d\n", input_num);

	// stats
	int line_count = 0;
	int word_count = 1;
	int word_count_max = 0;



	// assign in/out put column number
	in_col_num = atoi(*(inputs+1+flag));
	out_col_num = argc - flag - 2;
				//printf("in_col_num = %d, out_col_num = %d\n", in_col_num, out_col_num);


	// read out_cols into int array
				//printf("out_cols = ");
	int *out_cols = malloc(out_col_num * sizeof(int));
	for(int i = 2+flag; i < input_num; i++) {
		if(atoi(*(inputs+i)) >= 0)
			out_cols[i-2-flag] = atoi(*(inputs+i));
		else
			out_cols[i-2-flag] = in_col_num + atoi(*(inputs+i));
				//printf("%d ", out_cols[i-2-flag]);
	}
				//printf("\n");

	// read from txt
	char *buffer = NULL;		// pointer to stirng
    size_t bufsize = 32;
    ssize_t input;				// string length

	// turn into array of pointers
	char* in_cols[in_col_num];
	int in_cols_num = 0;

			//printf("-------------\n\tOutput:\n");

	// read input 1st line
    buffer = (char *)malloc(bufsize * sizeof(char));
		if(buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
    input = getline(&buffer, &bufsize, stdin);

	while(input != -1) {
		// turn into array of pointers

		in_cols[0] = buffer;
		for(int i = 1; i < input; i++) {
			if(buffer[i] == ' ' || buffer[i] == '\n') {
				buffer[i] = '\0';
				in_cols_num++;
				in_cols[in_cols_num] = &buffer[i+1];
				i++;

				if(word_count > word_count_max)
					word_count_max = word_count;

				word_count = 0;
				// printf("i = %d word_count_max = %d\n", i, word_count_max);
			}
			word_count++;
		}
		word_count = 0;
		in_cols_num = 0;


		// out put
		printf("%s", in_cols[out_cols[0]]);
		for(int i = 1; i < out_col_num; i++) {
			printf(" %s", in_cols[out_cols[i]]);
		}

		line_count++;
		printf("\n");
		input = getline(&buffer, &bufsize, stdin);
	}
	
	
	/* Format string for output to be printed when -c option is given */
	if(flag == 1)
		printf("Number of lines: %d\nLongest field: %d characters\n", line_count, word_count_max);
	
	
	
	
	
	free(out_cols);
	free(buffer);


	// unsigned int* inputs = (unsigned) atoi(argv);
	

	return EXIT_SUCCESS;
}


