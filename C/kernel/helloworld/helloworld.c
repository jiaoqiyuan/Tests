#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int helloworld_init(void) {
    printk(KERN_INFO "hello world!\n");
    return 0;
}

static void helloworld_exit(void) {
    printk(KERN_INFO "see you.\n");
}

void export_test(void){
	return;
}

EXPORT_SYMBOL_GPL(export_test);

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");

