#include <linux/kernel.h>
#include <linux/module.h>

static int test_hello_init(void)
{
    printk("\001" "4" "In init\n");
    return 0;
}
static void test_hello_exit(void)
{
    printk("\001" "2" "In exit\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);
MODULE_LICENSE("GPL");