#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>


int main(){
  char buf1[20];
  struct stat sb;
  
  int fd1 = open("sampletext1.txt", O_RDONLY);
  if (stat("csci341_temp.txt", &sb) >= 0){
      remove("csci341_temp.txt");
    }
  
  int fd2 = open("csci341_temp.txt", O_RDWR | O_CREAT, S_IRUSR);

  read(fd1, buf1, 19);
  buf1[19] = '\0';

  write(fd2, buf1, 19);

  fstat(fd2, &sb);

  printf("Last file modification to csci341_temp.txt:   %s", ctime(&sb.st_mtime));
  

}
