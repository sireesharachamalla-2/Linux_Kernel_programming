#include<linux/module.h>
#include<linux/init.h>
void func(void);
static int __init hello_init(void)
{
        printk(KERN_INFO "In init %s \n",__func__);
        func();
        return 0;
}
static void __exit hello_exit(void)
{
        printk(KERN_INFO "exit module %s \n",__func__);
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("Hello world Module");

