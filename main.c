#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



int main(void) {
  int n;
  printf("Digite o numero de filhos desejado: ");
  scanf("%d",&n);
  pid_t pids[n];
  for (int i = 0; i < n; ++i) {
    if ((pids[i] = fork()) < 0) {
      perror("fork");
      abort();
    } 
    else if (pids[i] == 0) {
    printf("Filho com PID = %d criado\n",getpid());
    sleep(2);
    exit(0);
  }
}
pid_t pid;
while (n > 0) {
  pid = wait(NULL);
  printf("Filho com PID = %ld finalizado\n", (long)pid);
  --n;
}
wait(NULL);
printf("Pai finalizado");
}