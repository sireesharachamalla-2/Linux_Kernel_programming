#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int my_init(void)
{
	printk("name = %s\n ",THIS_MODULE->name);
	printk("version = %s\n",THIS_MODULE->version);
	return 0;
}
static void my_exit(void)
{
	printk("In exit...\n");
}
module_init(my_init);
module_exit(my_exit);
MODULE_INFO(name ,"LINUX");
MODULE_VERSION("1.0");
MODULE_INFO(os,"linux");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

