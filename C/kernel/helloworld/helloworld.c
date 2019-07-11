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

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");

