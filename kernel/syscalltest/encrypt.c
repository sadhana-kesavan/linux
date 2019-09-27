#include<linux/kernel.h>
#include<linux/errno.h>
#include<linux/syscalls.h>

SYSCALL_DEFINE2(encrypt, char *,c,int,k)
{
        if(k > 5 || k < 1)
          return EINVAL;
        char *t=c;
        int i;
printk(KERN_DEBUG "the encrypted string is : %s",t);
        for(i =0;*(t+i) != '\0';i++)
        {
           *(t+i) = *(t+i) + k;
           printk(KERN_DEBUG "the encrypted char is : %c",*(t+i));
        }
        printk(KERN_DEBUG "the encrypted string is : %s",t);
        return 0;
}
