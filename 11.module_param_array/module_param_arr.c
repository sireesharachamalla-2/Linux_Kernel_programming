#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *my_thread;
int thread_function(void *pv)
{
int i = 0;
printk(KERN_INFO "Kthread: Started\n");
while (!kthread_should_stop())
{
	printk(KERN_INFO "In Thread Function %d\n", i++);
	msleep(1000);
}
	printk(KERN_INFO "KThread: Stopped\n");
	return 0;
}

static int __init my_driver_init(void)
{
	printk(KERN_INFO "Kernel Thread Driver Init\n");
	my_thread = kthread_create(thread_function, NULL, "myThread");
	if (my_thread)
       	{
		wake_up_process(my_thread);
		printk(KERN_INFO "Kernel Thread created\n");
		return 0;
	}
       	else
       	{
		printk(KERN_ERR "not created kernel thread\n");
		return -1;
	}
}

static void __exit my_driver_exit(void)
{
	printk(KERN_INFO "KThread Driver Exit\n");
	if (my_thread)
		kthread_stop(my_thread);
	printk(KERN_INFO "Device Driver Removed.!!\n");
}
module_init(my_driver_init);
module_exit(my_driver_exit);
MODULE_LICENSE("GPL");
