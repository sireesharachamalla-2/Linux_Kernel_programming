#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
static struct task_struct *kthread1;
static struct task_struct *kthread2;
static int work_func1(void *data)
{
int i = 0;
	while (!kthread_should_stop()) 
	{
		pr_info("1 %d\n", i);
		usleep_range(1000000, 1000001);
		i++;
	if (i == 10)
		i = 0;
	}
return 0;
}
static int work_func2(void *data)
{
	int i = 0;
	while (!kthread_should_stop())
       	{
		pr_info("2 %d\n", i);
		usleep_range(1000000, 1000001);
		i++;
		if (i == 10)
			i = 0;
	}
return 0;
}
static int __init my_driver_init(void)
{
	pr_info("Dual Kernel Thread Driver Loading...\n");
	kthread1 = kthread_run(work_func1, NULL, "kthread1");
	if (IS_ERR(kthread1)) {
		pr_err("failed  kthread1\n");
		return PTR_ERR(kthread1);
	}
	kthread2 = kthread_run(work_func2, NULL, "kthread2");
	if (IS_ERR(kthread2)) {
		pr_err("failed kthread2\n");
		kthread_stop(kthread1);
		return PTR_ERR(kthread2);
	}
	pr_info("two threads created\n");
	return 0;
}
static void __exit my_driver_exit(void)
{
	pr_info("stop threads...\n");
	if (kthread1)
		kthread_stop(kthread1);
	if (kthread2)
		kthread_stop(kthread2);
	pr_info("two threads removed\n");
}
module_init(my_driver_init);
module_exit(my_driver_exit);
MODULE_LICENSE("GPL");
