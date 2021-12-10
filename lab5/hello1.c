// SPDX-License-Identifier: GPL-2.0

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/errno.h>
#include <linux/ktime.h>
#include <linux/slab.h>
#include "hello1.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrii Koreniuk");
MODULE_DESCRIPTION("Laboratory Work #5 (Advanced Level)");

struct time_node {
	struct time_node *next;
	ktime_t start;
	ktime_t end;
};

static struct time_node *first_time;
static struct time_node *last_time;
static bool is_need_time = true;

static void print_hello(void)
{
	if (is_need_time) {
		first_time = kmalloc(sizeof(struct time_node), GFP_KERNEL);
		last_time = first_time;
		is_need_time = false;
	}
	(*last_time).start = ktime_get();
	pr_info("Hello World!\n");
	(*last_time).end = ktime_get();
	(*last_time).next = kmalloc(sizeof(struct time_node), GFP_KERNEL);
	last_time = (*last_time).next;
}
EXPORT_SYMBOL_GPL(print_hello);

static void print_time(void)
{
	struct time_node *additional_time;

	if (!is_need_time) {
		pr_info("%lld ms\n", ktime_to_ns((*first_time).end - (*first_time).start));
		additional_time = first_time;
		first_time = (*first_time).next;
		kfree(additional_time);
	}
	if (first_time == last_time) {
		kfree(first_time);
		is_need_time = true;
	}
}
EXPORT_SYMBOL_GPL(print_time);

static int __init initial_function(void)
{
	return 0;
}

static void __exit clean_function(void)
{
}

module_init(initial_function);
module_exit(clean_function);
