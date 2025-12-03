#include<linux/init.h>
#include<linux/module.h>
static int __init hello2_init(void)
{
        printk(KERN_INFO "Hello world22\n");
        return 0;
}
static void __exit hello2_exit(void)
{
        printk(KERN_INFO "!!!!!!!\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sireesha");
MODULE_DESCRIPTION("hello world module");
