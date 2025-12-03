#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
static int mod_init(void)
{
	printk("in init..\n");
	dump_stack();
	return 0;
}
static void mod_exit(void)
{
	printk("In exit...\n");
}
module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

