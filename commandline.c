#include <getopt.h>
#include <stdio.h>
//#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
//#include <sys/wait.h>
//#include <stdlib.h>

int main(int argc, char** argv) {
  int c;
  char* PATH = getenv("PATH");

   // assume one program argument
  char *const *cmd = (char *const *) "echo \"Command ls -l\"";
  char* cmd2 = NULL;
  cmd2 = "hi";
  int pid = fork();
  if (pid == 0) {
    // initialize child context
    printf("%i\n", pid);
    execvp("echo", cmd2);
  } else {
    // This is the parent process. Wait for the child process to complete
    waitpid(pid, NULL, 0);
  }
//  while ( (c = getopt(argc, argv, "")) != -1 ) {
//
//  }


}