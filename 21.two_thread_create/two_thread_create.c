#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/jiffies.h>


void print_jiffies(void)
{
	printk(KERN_INFO "jiffies:%ld\n",jiffies);
}
static int my_init(void)
{
	printk("my init ...");
	return 0;
}
static void my_exit(void)
{
	printk("In exit...\n");
}
EXPORT_SYMBOL_GPL(print_jiffies);
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

