#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char **argv)
{
    pid_t my_pid, parent_pid;
    uid_t my_uid, my_euid;
    gid_t my_gid, my_egid;
    struct passwd *my_info;

    my_pid     = getpid();
    parent_pid = getppid();
    my_uid     = getuid();
    my_euid    = geteuid();
    my_gid     = getgid();
    my_egid    = getegid();
    my_info    = getpwuid(my_uid);

    printf("\n");
    printf("Process ID         = %d\n", my_pid);
    printf("Parent ID          = %d\n", parent_pid);
    printf("\n");
    printf("User ID            = %d\n", my_uid);
    printf("Effective User ID  = %d\n", my_euid);
    printf("Group ID           = %d\n", my_gid);
    printf("Effective Group ID = %d\n", my_egid);
    printf("\n");

    if(my_info)
    {
        printf("My Login Name : %s\n", my_info->pw_name);
        printf("My Password   : %s\n", my_info->pw_passwd);
        printf("My User ID    : %d\n", my_info->pw_uid);
        printf("My Group ID   : %d\n", my_info->pw_gid);
        printf("My Real Name  : %s\n", my_info->pw_gecos);
        printf("My Home Dir   : %s\n", my_info->pw_dir);
        printf("My Work Shell : %s\n", my_info->pw_shell);
    }
}

