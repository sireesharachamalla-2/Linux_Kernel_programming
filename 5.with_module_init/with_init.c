#include<linux/module.h>
#include<linux/init.h>
static int __init hello1_init(void)
{
        printk(KERN_INFO "Hello world11 \n");
        return 0;
}

module_init(hello1_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("Hello world Module");

