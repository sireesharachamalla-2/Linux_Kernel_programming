#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched/signal.h>   // for_each_process(), task_struct
static int __init test_tasks_init(void)
{
    struct task_struct *task_list;
    unsigned int process_count = 0;

    pr_info("In init\n");

    for_each_process(task_list) {
        pr_info("Process: %s\t PID:%d\t State: %ld\n",task_list->comm,task_list->pid,task_list->state);

        process_count++;
    }
    pr_info("No. of processes: %u\n", process_count);
    return 0;
}
static void __exit test_tasks_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_tasks_init);
module_exit(test_tasks_exit);
MODULE_LICENSE("GPL");