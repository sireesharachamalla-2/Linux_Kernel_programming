#include<linux/module.h>
#include<linux/init.h>
static int __init hello1_init(void)
{
        printk(KERN_INFO "Hello world11 \n");
        return 0;
}
static void __exit hello1_exit(void)
{
        printk(KERN_INFO "exit module!!!!!!\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("Hello world Module");
