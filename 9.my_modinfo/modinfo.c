#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/delay.h>

void func(void)
{
	int i;
	for(i=0;i<50000L;i++)
	{
		printk("Hello from linux\n");
	}
}
static int my_init(void)
{
	printk("in init :%s \n",__func__);
	func();
	return 0;
}
static void my_exit(void)
{
	printk("In exit : %s \n",__func__);
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

