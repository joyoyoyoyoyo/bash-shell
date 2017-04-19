
// used for commandline parsing of default arguments (e.g. argc, argv)
#include <getopt.h>

// used for print statements, which is implicitly used for logging as well
#include <stdio.h>

// used to parse command line arguments and build an argument list for the executing commands
#include <regex.h>

// allows for unix system calls (e.g. fork(), execvp() )
#include <unistd.h>

// allows for waitpid(), which waits for a process to complete
#include <sys/wait.h>

// used to retrieve our PATH directory and contents within the bin and other path variables
// methods included in the header: getenv() and exit()
#include <stdlib.h>
#include <string.h>

// process handling
#define IS_CHILD_PROCESS 0

// pipe buffer constants
#define MAX_BUFFER_SIZE 2024

// tokens
#define TOKEN_PIPE "|"
#define TOKEN_WRITE ">"
#define TOKEN_READ "<"
#define BASH_REGEX "(ls)"


// memory buffer sizes
#define MAX_MATCHES 20
#define MAX_ARG_BUFFER 2024

// helper for arbitary no flag provided argument
#define NO_FLAG 0
#define TOTAL_POSSIBLE_NUM_MATCHES 16


#define MAX_POSSIBLE_OFFSET_CAPTURES 2;
#define MAX_POSSIBLE_CAPTURES 64

//typedef int condition
char* mergeArguments(int argc, char* argv[]) {

  char *merged_arguments = malloc(sizeof(char)*MAX_ARG_BUFFER);

  // String helpers to concatenate program arguments
  int arg_index;
//  merged_arguments = getcwd(0,0);
  printf("%s", merged_arguments);
  for (arg_index = 0; arg_index < argc; arg_index++) {
    strcat(merged_arguments, argv[arg_index]);
  }
  printf("%s\n", merged_arguments);
  return merged_arguments;
}


int main(int argc, char* argv[], char* env[]) {

  char *READ_ARGS = "([a-zA-Z])\\w+|\\w+([a-zA-Z])\\w+|\\w+([a-zA-Z])";
  char *MAX_ALLOWABLE_PIPES = "([a-zA-Z])\\w+|\\w+([a-zA-Z])\\w+|\\w+([a-zA-Z])";
  char *READ_ALL_WORDS = "([a-zA-Z]+) ";
  char *CAPTURE_MAX_ALLOWABLE_PIPES = "([a-zA-Z]+)\\s+\\|\\s+([a-zA-Z]+)\\s+\\|\\s+([a-zA-Z]+)";
  char *READ_FILE = "(.*)\\s+<\\s+"; // this is probably better
//  char *READ_FILE_IN = "<\\s+(.*)";

  char *WRITE_TO_FILE = ">\\s+(.*)";
  char *WRITE_FROM_FILE = "(.*)\\s+>";

  regex_t pattern;
  int number_of_parenthesized_expressions = (int) pattern.re_nsub;
  regmatch_t match;
  int byte_offset_from_start_of_string_to_substring = (char) match.rm_so;
  int byte_offset_from_end_of_string_to_substring = (char) match.rm_eo;

  int response;
  // place the string pointed to by the pattern into the first argument
//  response = regcomp(&pattern, "([^|<>])+\\s?[<|>]", REG_EXTENDED); // only try: | !REG_NOSUB)
  response = regcomp(&pattern, WRITE_FROM_FILE, REG_EXTENDED);


  if (response == 0) {
    printf("Sucessful compilation\n");
  } else {
    printf("Pattern is undefined\n");
    exit(1);
  }

  int t;
  char *input = "helloworld helloworld";
  input = "echo \"Hello World!\"";
  input = "ls -l  > temp > temp2";
  regmatch_t matches_found[TOTAL_POSSIBLE_NUM_MATCHES][2024];
  int offsets[TOTAL_POSSIBLE_NUM_MATCHES][2];
//  regmatch_t temp_name_experiment[MAX_POSSIBLE_CAPTURES][MAX_POSSIBLE_OFFSET_CAPTURES];
  int q;
//  for(q = 0; q < TOTAL_POSSIBLE_NUM_MATCHES; q++) {
//    matches_found[q] = malloc(2024* sizeof(regmatch_t));
//  }
//  char matched_string_buffer[2024];

//  char *matched_string_buffer =  (char *) malloc(sizeof(char) * 2024);
//  char *matched_string_buffer = (char*) malloc(2024 * sizeof(char));
  char array[2024];
  char *temp;
  int number_of_matches_found = 0;
  char* matched_string_buffer[TOTAL_POSSIBLE_NUM_MATCHES];

  input = "cat < inputfile | sort | wc > temp "; // MAX_ALLOWABLE_PIPES

  for (t = 0; t < TOTAL_POSSIBLE_NUM_MATCHES; t++) {

    /**
     * 1st arg: the compiled pattern compared with the second argument
     * 2nd arg: Null terminated string to compare to
     * 3rd arg:
     */
    int match_response;

    match_response = regexec(&pattern,
                             input, // takes a pointer to my string
                             (size_t) TOTAL_POSSIBLE_NUM_MATCHES,
                             matches_found[t], NO_FLAG);
    if (match_response == 0) {
//      printf("Match success!\nStarting character: %c\nEnding character: %c\n",
//             input[matches_found[t]->rm_so],
//             input[matches_found[t]->rm_eo - 1]
//      );
      offsets[number_of_matches_found][0] = (int) matches_found[t]->rm_so;
      offsets[number_of_matches_found][1] = (int) matches_found[t]->rm_eo;
      int input_size = offsets[number_of_matches_found][1] - offsets[number_of_matches_found][0];
      matched_string_buffer[t] = malloc(input_size + 1);

      strncpy(matched_string_buffer[t],input+matches_found[t]->rm_so, input_size + 1);

      char pipe_character =  input[matches_found[t]->rm_eo - 1];
      matched_string_buffer[t][input_size ] = '\0';
      printf("%s\n", matched_string_buffer[t]);
      input += matches_found[t]->rm_eo; // do pointer arithmetic to the end of the string
//      matched_string_buffer[t] = matched_string_buffer[t] + input_size + 1;
      number_of_matches_found++;
    }
    else {
      printf("We didn't find a match in the provided string; %s\n", input);
      break;
    }


  }

  // split on white space and create a string args element


  // parse inbetween pipe characters, since for each function called inside the piping
  // use getopt inside each program declaration




  // syntax conventions
  regfree(&pattern);
  char *exec_sample_args[] = {"ls", "-l", ">", "temp", NULL};
  char *quora_example_1st_command[] = {"ls", "-l", "-h", NULL}; // note: no pipe is passed
  char *quora_example_2nd_command[] = {"wc", "-l", NULL};
  int exec_response;
  char pipe_buffer[MAX_BUFFER_SIZE]; // any flushing?


  // create pipes
  int pipe_read_in[2], pipe_write_out[2], pipe_error_out[2];
  int response_from_pipe1, response_from_pipe2;

  // connect the pipe ends to the current processes file descriptors
  pipe(pipe_read_in);
  pipe(pipe_write_out);
  pipe(pipe_error_out);

  // We have created the file descriptors in the parent process table.


  pid_t pid = fork();


  if (pid < 0) {
    perror("error");
    return EXIT_FAILURE;
  }
  else if(pid == 0) {
    printf("my process ID is %d\n", getpid());
//    printf("my parent's process ID is %d\n", getppid());
//    printf("my child's process ID is %d\n", child_pid);
    /**
     * Child Process
     *
     * 0: File Descriptor index of pipe = Read End
     * 1: File Descriptor index of pipe = Write End
     * */

    /**
     * Before parent process can receive input, the child processes must
     * close its corresponding file descriptors so that the pipe does
     * not assume there may still be input or output coming from the
     * child process
     */
    close(pipe_read_in[1]);  // close write end of std_input
    close(pipe_write_out[0]);  // close read end of std_output
    close(pipe_error_out[0]);  // close read end of std_error

    /**
     * Switch and reassign file descriptors, because at the moment our
     * current file descriptors are not referencing the correct processes
     */
    dup2(pipe_read_in[0], STDIN_FILENO); // read end will use pipes
    dup2(pipe_write_out[1], STDOUT_FILENO); // write end will use pipes
    dup2(pipe_error_out[1], STDERR_FILENO); // write end will use pipes


    /**
     * Execute the given program
     */
    exec_response = execvp(quora_example[1],quora_example+1);
    if (exec_response == -1) {
      perror("Failure to execute subprocess");
      return EXIT_FAILURE;
    }


  } else {
    /**
     * Parent Process
     *
     * 0: File Descriptor index of pipe = Read End
     * 1: File Descriptor index of pipe = Write End
     */


    /**
     * Before parent process can receive input, the child processes must
     * close its corresponding file descriptors so that the pipe does
     * not assume there may still be input or output coming from the
     * child process
     */
    close(pipe_read_in[0]);  // close read end of std_input
    close(pipe_write_out[1]);  // close write end of std_output
    close(pipe_error_out[1]);  // close write end of std_error

    /**
     * Direct the program input to the child process
     *
     * STDIN_FILENO: file descriptor for std_input
     *
     */

    /**
     * Write End of Std_in will be directed to the pipe_buffer
     */
    read(
        STDIN_FILENO, // read from standard input
        pipe_buffer,
        MAX_BUFFER_SIZE
    );

    write (
        pipe_read_in[1],
        pipe_buffer,
        MAX_BUFFER_SIZE
    );
    close(pipe_read_in[1]);

    wait(NULL); // or waitpid(pid, NULL, 0);


    puts("\nchild's stdout:");
    fflush(stdout);

    /**
     * Write End of Std_in will be directed to the pipe_buffer
     */
    read(
        pipe_write_out[0], // read from standard input
        pipe_buffer,
        MAX_BUFFER_SIZE
    );

    write (
        STDOUT_FILENO,
        pipe_buffer,
        MAX_BUFFER_SIZE
    );
    close(pipe_write_out[0]);



    puts("\nchild's stderr:");
    fflush(stdout);

    read(
        pipe_error_out[0],
        pipe_buffer,
        MAX_BUFFER_SIZE
    );

    write (
        STDOUT_FILENO,
        pipe_buffer,
        MAX_BUFFER_SIZE
    );
    close(pipe_error_out[0]);
    return EXIT_SUCCESS;


  }
  // man 2 write
//  execvp()
//
//  read(pipe_read_from_fd1[0], pipe_buffer, 15);
//  printf("Parent Process %d\t%s\n", getpid(), pipe_buffer);
//  printf("Child Process: %d\n", getpid(), pipe_buffer);
//  write(pipe_read_from_fd1[1], "Hey there", 12); // what is 12?
//  execvp("ls -l", testfile2_line2);



  exit(0);




//  stuff_to_fork();





  // handle the filehandler for the passing of inputs into the argument list
//  = dup2
//  execvp()





/**
 * My debug commands:
 * gdb bash
 * break 171
 */










///** **********************
//
//
//  // My regular expression
//  char bash_regex_tokenizer[2024] = "(ls)";
//  char token_buffer[2024];
//  char* select;
//  regmatch_t token_matches[MAX_MATCHES];
//
//
//  // Match these test cases
//  char *testfile_line1[] = {"echo", "\"Command ls -l\" hi ls hi", NULL};
//  char *testfile_1ine2[] = {"ls", "-l", "-f", NULL};
//  char *testfile_line3[] = {"echo", "\"Command ls\"", NULL};
//  char *testfile_line4[] = {"ls", "-al", NULL};
//  char *testfile_line5[] = {"exit"};
//
//  // memory for matches
//
//  int length_of_token;
//  int err, isFound;
//  int buffer_count;
////  regex_t bash_r; // regex for parsing bash
//
//
//  // compile pattern
//  if( regcomp(&pattern, bash_regex_tokenizer,REG_EXTENDED) == 0) // number of parenthesized subexpressions
//    printf("Compiled the RegularExpression\n");
//  // FOR SOME STUPID REASON, mergeArguments had to be after regex compilation
//  select = mergeArguments(2, testfile_line1);
//  printf("%s\n", select);
//  int i;
//    int sub = pattern.re_nsub;
//    err = regexec(&pattern, select, sub, token_matches, 0);
//
//      if (err == REG_NOMATCH)
//        printf("Test\n");
//      buffer_count = (int)token_matches[i].rm_eo - (int)token_matches[i].rm_so;
//      strncpy(token_buffer,select+token_matches[i].rm_so,buffer_count);
//      token_buffer[buffer_count] = '\0';
//      printf("From %d to %d (%s)\n",(int)token_matches[i].rm_so,
//             (int)token_matches[i].rm_eo,token_buffer);
//
//      printf("Match: %s\n", (select + 1) + (token_matches[0].rm_so - 1));
//
//
////  if(isFound == 0) {
////    int i;
////    for(i = 0; i < MAX_MATCHES; i++) {
////      if ((int) token_matches[i].rm_so < 0) break;
//////      length_of_token = ((int) token_matches[i].rm_eo - (int) token_matches[i].rm_so);
//////      strncpy(token_buffer, *testfile_1ine2 + token_matches[i].rm_so, (size_t) length_of_token);
//////      token_buffer[length_of_token] = '\0';
////      printf("String Match: %s\n", select);  regfree(&pattern);
////
////    }
////  }
//
//  regfree(&pattern);
//
//  return 0;
//  **/

////  if(isFound == 0) {
//  for(int i = 0; i < MAX_MATCHES; i++) {
//    int start_index;
//    int end_index;
//    start_index = token_match[i].rm_so + (*testfile_line1 -
//    printf("%c", *testfile_line1[1]);
//  }
//    printf("%s", "Success");
//  else
//    if (compile_sucess == REG_NOMATCH)
//      printf("No match");
//    else
//      regerror(comp);
//    printf("error");

//  pid_t pid = getpid(); // get the current process




  // stuff to fork
//    stuff_to_fork();

}

void stuff_to_fork() {
  // get the current process ID
  pid_t pid = getpid();

  // gets the current processes parent ID
  pid_t parent_pid = getppid();

//    printf("my process ID is %d\n", getpid());
//    printf("my parent's process ID is %d\n", getppid());
//    printf("my child's process ID is %d\n", child_pid);


  /** fork() run parent process, then exit() and call child process **/

  // everything after fork() executes everything from the start all over again
  // get the child process identifier of the current process
  pid_t child_pid = fork();

  if (child_pid == IS_CHILD_PROCESS) {
      // note cannot use child_pid to getcurrentprocessid, use getpid instead
      printf("my child's process ID is %d\n", getpid());

  } else {
      printf("I am the parent process: pid=%d, child pid=%d\n", getpid(), pid);
  }

  exit(0);
}
