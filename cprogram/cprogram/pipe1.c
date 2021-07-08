//
//  pipe1.c
//  cprogram
//
//  Created by shunqing wang on 2021/6/19.
//

#include <stdio.h>
#include <unistd.h>
int pipe_test(void)
{
    int fds[2];
    char str[] = "who are you?";
    char buf[30];
    pid_t pid;
    pipe(fds);
    pid = fork();
    if(pid == 0){
        write(fds[1], str, sizeof(str));
    }
    else {
        read(fds[0], buf, 30);
        puts(buf);
    }
    return 0;
}
