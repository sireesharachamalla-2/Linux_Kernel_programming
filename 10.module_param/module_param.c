#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
int arr[5];
static int cnt=0;
module_param_array(arr,int,&cnt,0644);

static int param_arr_init(void)
{
	int i=0;
	printk("In init.. module param array \n");
	printk("count=%d\n",cnt);
	printk("array elements\n");
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		printk("%d \n",arr[i]);
	}
	return 0;
}
static void param_arr_exit(void)
{
	printk("In exit...\n");
}
module_init(param_arr_init);
module_exit(param_arr_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sireesha");
MODULE_DESCRIPTION("module parameters");

