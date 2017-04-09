
// used for commandline parsing of default arguments (e.g. argc, argv)
#include <getopt.h>

// used for print statements, which is implicitly used for logging as well
#include <stdio.h>

// allows for unix system calls (e.g. fork(), execvp() )
#include <unistd.h>

// allows for waitpid(), which waits for a process to complete
#include <sys/wait.h>

// used to retrieve our PATH directory and contents within the bin and other path variables
// methods included in the header: getenv() and exit()
#include <stdlib.h>


#define IS_CHILD_PROCESS 0

int main(int argc, char* argv[]) {

    // parse command line arguments
    parse(argc, argv);

    // stuff to fork
//    stuff_to_fork();

}
// See: http://stackoverflow.com/questions/189972/argument-parsing-helpers-for-c-unix/
void parse(int argc, char* argv[]) {
    int opt;
    int index;
    char *test;
    while ( (opt = getopt(argc, argv, "|:<>:")) != -1 ) {
        switch (opt) {
            case '|':
                break;
            case '<':
                break;
            case '>':
//                command.source_ip_address = optarg; //must be required
//                num_of_optparams_specified += 2;
                break;
            default:
                test = optarg;
                if (test != NULL) {
                    execvp(optarg, argv);
                    exit(0); // terminate the program
                }
        }
    }
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
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

void tree() {
    // the list and hierarchical execution
}