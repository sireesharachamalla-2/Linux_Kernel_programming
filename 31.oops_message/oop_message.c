#include<linux/init.h>
#include<linux/module.h>
static int __init hello_init(void)
{
        *(int *)0x12='a';
         printk(KERN_INFO "in init..\n");
        return 0;
}
static void __exit hello_exit(void)
{
        printk(KERN_INFO "in exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("sireesha");
MODULE_DESCRIPTION("hello world module");
