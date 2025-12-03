#include<linux/kernel.h>
#include<linux/module.h>

extern int myadd(int a,int b);

static int module2_init(void)
{
	printk("in init..\n");
	printk("Add : %d\n",myadd(3,5));
	return 0;
}
static void module2_exit(void)
{
	printk("In exit...\n");
}
module_init(module2_init);
module_exit(module2_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

