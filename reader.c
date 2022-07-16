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
		printf("-c\n");
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
		printf("flag = %d\n", flag);
		printf("argc = %d\n", input_num);



	// assign in/out put column number
	in_col_num = atoi(*(inputs+1+flag));
	out_col_num = argc - flag - 2;
		printf("in_col_num = %d, out_col_num = %d\n", in_col_num, out_col_num);


	// read out_cols into int array
		printf("out_cols = ");
	int out_cols[input_num];
	for(int i = 2+flag; i < input_num; i++) {
		if(atoi(*(inputs+i)) >= 0)
			out_cols[i] = atoi(*(inputs+i));
		else
			out_cols[i] = in_col_num + atoi(*(inputs+i));
		printf("%d ", out_cols[i]);
	}
		printf("\n");

	// read from txt
	char *buffer = NULL;		// pointer to stirng
    size_t bufsize = 32;
    ssize_t input;				// string length

	// read input 1st line
    buffer = (char *)malloc(bufsize * sizeof(char));
		if(buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
    input = getline(&buffer, &bufsize, stdin);
		printf("input = %s", buffer);
	
	// turn into array of pointers
	char* in_cols[in_col_num];
	int in_cols_num = 0;

	in_cols[0] = buffer;
	for(int i = 1; i < input; i++) {
		if(buffer[i] == ' ') {
			buffer[i] = '\0';
			in_cols_num++;
			in_cols[in_cols_num] = &buffer[i+1];
			i++;
		}
	}
		printf("inputs_char = %c\n", buffer[0]);
		printf("in_cols[0] = %s\n", in_cols[0]);
		printf("in_cols[1] = %s\n", in_cols[1]);


	// 
	
	
	
	
	
	
	
	
	free(buffer);


	// unsigned int* inputs = (unsigned) atoi(argv);
	

	return EXIT_SUCCESS;


	/* Format string for output to be printed when -c option is given

	   printf("Number of lines: %d\n"
	   "Longest field: %d characters\n",
	   insert your variable names here);
	*/
}


