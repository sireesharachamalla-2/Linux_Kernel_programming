#include<linux/kernel.h>
#include <linux/kernel.h>
#include <linux/module.h>

void func(void)
{
    printk(KERN_INFO "In FUNC....\n");
}
EXPORT_SYMBOL(func);
static int __init func_init(void)
{
    printk(KERN_INFO "func module loaded.\n");
    func();
    return 0;
}
static void __exit func_exit(void)
{
    printk(KERN_INFO "func module unloaded.\n");
}
module_init(func_init);
module_exit(func_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("sireesha");
MODULE_DESCRIPTION("A simple kernel module");

