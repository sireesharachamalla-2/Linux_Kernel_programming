#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

static bool val=false;
module_param(val,invbool,0644);  //S_IRUGO -user,group,others->read-only

static int my_init(void)
{
        printk("inverse bool:%s\n",val?"true":"false");
        return 0;
}
static void my_exit(void)
{
        printk("In exit...\n");
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

