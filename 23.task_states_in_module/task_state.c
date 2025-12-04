#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>      // for task_struct
#include <asm/current.h>      

MODULE_LICENSE("GPL");

static int __init current_init(void)
{
    printk("current pid : %d, current process : %s\n", current->pid,current->comm);
    return 0;
}
static void __exit current_exit(void)
{
    printk("current pid : %d, current process : %s\n" ,current->pid,current->comm);
}

module_init(current_init);
module_exit(current_exit);
MODULE_LICENSE("GPL");

