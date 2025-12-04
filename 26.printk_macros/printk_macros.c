#include <linux/kernel.h>
#include <linux/module.h>
static int test_hello_init(void)
{
    pr_info("In init\n");
    printk(KERN_ALERT "This is alert\n");
    printk(KERN_INFO "This is info\n");

    return 0;
}
static void test_hello_exit(void)
{
    pr_warn("In exit\n");
}
module_init(test_hello_init);
module_exit(test_hello_exit);
MODULE_LICENSE("GPL");