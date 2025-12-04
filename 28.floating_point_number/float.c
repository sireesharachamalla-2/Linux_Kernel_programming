#include <linux/kernel.h>
#include <linux/module.h>
static int test_hello_init(void)
{
    float f = 3.156;
    printk("In init, value of f is %f\n",f);
    return 0;
}
static void test_hello_exit(void)
{
    printk("In exit\n");
}
module_init(test_hello_init);
module_exit(test_hello_exit);
MODULE_LICENSE("GPL");