#include<linux/module.h>
#include<linux/init.h>
static void __exit hello_exit(void)
{
        printk(KERN_INFO "exit module!!!!!!\n");
}

module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("Hello world Module");
