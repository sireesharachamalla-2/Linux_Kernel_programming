#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>      // for task_struct
#include <asm/current.h>      // for current pointer
static int __init current_init(void)
{
    printk("current pid : %d, current process : %s\n",current->pid, current->comm);
    return 0;
}
static void __exit current_exit(void)
{
    printk("current pid : %d, current process : %s\n",current->pid,current->comm);
}
module_init(current_init);
module_exit(current_exit);
MODULE_LICENSE("GPL");
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/dcache.h>
#include <linux/path.h>
#include <linux/slab.h>
#define PID 1
static void print_vm_file(struct vm_area_struct *vma)
{
    struct file *vmfile = NULL;
    struct dentry *dentry = NULL;
    struct dentry *pPath = NULL;
    char file_path[256];
    char *start = NULL, *end = NULL;
    if (!vma->vm_file) {
        printk("\tIt's not a file map\n");
        return;
    }
    vmfile = vma->vm_file;
    dentry = vmfile->f_path.dentry;
    if (!dentry) {
        printk("\tNo dentry available\n");
        return;
    }
    memset(file_path, 0, sizeof(file_path));
    for (pPath = dentry; pPath != NULL; pPath = pPath->d_parent) {
        if (strcmp(pPath->d_name.name, "/") != 0) {
            strcat(file_path, pPath->d_name.name);
            strcat(file_path, "/");
        }
        if (pPath == pPath->d_parent)
            break;
    }
    start = file_path;
    end = file_path + strlen(file_path) - 1;
    while (start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    printk("\tFILE: %s\n", file_path);
}
static void print_vma_node(struct vm_area_struct *vma)
{
    printk("0x%lx - 0x%lx\t", vma->vm_start, vma->vm_end);
    printk("%c", (vma->vm_flags & VM_READ)  ? 'r' : '-');
    printk("%c", (vma->vm_flags & VM_WRITE) ? 'w' : '-');
    printk("%c", (vma->vm_flags & VM_EXEC)  ? 'x' : '-');
    printk("%c\t", (vma->vm_flags & VM_SHARED) ? 's' : 'p');
    print_vm_file(vma);
    printk("\n");
}
static int __init vma_test_init(void)
{
    struct task_struct *task;
    struct mm_struct *mm;
    struct vm_area_struct *vma;
    printk(KERN_INFO "VMA Module Loaded\n");
    task = pid_task(find_get_pid(PID), PIDTYPE_PID);
    if (!task) 
    {
        printk("PID %d not found\n", PID);
        return -1;
    }
    printk("Found Task: %s (PID = %d)\n", task->comm, task->pid);
    mm = task->mm;
    if (!mm) 
    {
        printk("No mm_struct\n");
        return -1;
    }
    printk("VMA list start\n");
    for (vma = mm->mmap; vma != NULL; vma = vma->vm_next)
     {
        print_vma_node(vma);
    }
    printk("VMA end\n");
    return 0;
}
static void __exit vma_test_exit(void)
{
    printk("VMA exit\n");
}
module_init(vma_test_init);
module_exit(vma_test_exit);
MODULE_LICENSE("GPL");