#include<linux/kernel.h>
#include<linux/module.h>

int myadd(int a,int b)
{
	printk("Adding %d + %d =%d \n",a,b,a+b);
	return a+b;
}
EXPORT_SYMBOL(myadd);
static int module1_init(void)
{
	printk("in init..\n");
	return 0;
}
static void module1_exit(void)
{
	printk("In exit...\n");
}
module_init(module1_init);
module_exit(module1_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

