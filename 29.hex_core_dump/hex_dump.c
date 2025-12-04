#include <linux/kernel.h>
#include <linux/module.h>
static int test_hello_init(void)
{
    char buffer[] = "Hello World!";
    print_hex_dump(KERN_ALERT, "buf: ", DUMP_PREFIX_ADDRESS,16, 1, buffer, sizeof(buffer), 1);
    return 0;
}
static void test_hello_exit(void)
{
    printk("in exit\n");
}
module_init(test_hello_init);
module_exit(test_hello_exit);
MODULE_LICENSE("GPL");