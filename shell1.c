//
// Created by bahamut on 4/19/17.
//
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH_OF_LINE 512

// for each child process, execute their appropriate command and pipe their input, outputs
void call(int src,int dest, char* command[]) {

}


// extra optional boilerplate
typedef struct {
  char *left[MAX_LENGTH_OF_LINE];
  char *middle[MAX_LENGTH_OF_LINE];
  char *right[MAX_LENGTH_OF_LINE];
  char *read[MAX_LENGTH_OF_LINE];
  char *write[MAX_LENGTH_OF_LINE];
  int num_commands;

} GlobalCommand;

// boiler plate for initialize my commands
void initialize_command(GlobalCommand* command, char**left, char** middle, char** right, char**read, char**write) {
//  *commands.left = *left_of_pipe;
//  *commands.middle = *midd_of_pipe;
//  *commands.right = *righ_of_pipe;
  command->num_commands = 0;
//  if (left == 0)
    memset(command->left, NULL, sizeof(command->left));
//  else {
    *command->left = *left;
    command->num_commands++;
//  }
//  if (middle == 0)
    memset(command->middle, NULL, sizeof(command->middle));
//  else {
    *command->middle = *middle;
    command->num_commands++;
//  }
//  if (right == 0)
    memset(command->right, NULL, sizeof(command->right));
//  else {
    *command->right = *right;
    command->num_commands++;
//  }
  if (read == 0)
    memset(command->read, NULL, sizeof(command->read)); // or command->read[0] = 0;
  else {
    *command->read = *read;
    command->num_commands++;
  }
  if (write == 0)
    memset(command->write, NULL, sizeof(command->write));
  else {
    *command->write = *write;
    command->num_commands++;
  }

}

int run( int src, int dest, char** command) {
  char *test = getenv("PATH");

  pid_t child1 = fork();
  if (child1 == 0) {// child process
    dup2(src, 0);
    dup2(dest, 1);
    printf("\n[Running] PID: %d\tArgs: %s", getpid(), command[0]);
    execvp(command[0], command);
    return EXIT_SUCCESS;
  }
  else {
    waitpid(getpid(), NULL, 0);
  }


}

int main() {
  // full command: "ls | grep shell | sort"
  // Test:  cat colors.txt | sed 's/e/E/' | sort
  char *left_of_pipe[] = {"cat", "colors2.txt", NULL};
  char *midd_of_pipe[] = {"sed", "s/e/E/", NULL};
  char *righ_of_pipe[] = {"sort", NULL};

  GlobalCommand commands = {0}; // memset to 0 or memset(&commands, 0, sizeof(commands))
//  commands = {0};
  initialize_command(&commands, left_of_pipe, midd_of_pipe, righ_of_pipe, 0, 0);
  printf("PID: %d\tArgs: %s, %s, %s, %s, %s\tCommand Count: %d\n", getpid(),*commands.left,*commands.middle,*commands.right, *commands.read, *commands.write, commands.num_commands);

  // parent process

  // Create file descriptors for pipes
  int fd1[2];
  int fd2[2];
  int num_pipes = commands.num_commands - 1;

  pipe(fd1);
  run(0, fd1[1], left_of_pipe);
  close(fd1[1]);

  pipe(fd2);
  run(fd1[0], fd2[1], midd_of_pipe);
  close(fd2[1]);

  run(fd2[0], 1, *righ_of_pipe);
  wait(NULL);
  return EXIT_SUCCESS;
  // begin process 1

}

