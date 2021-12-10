// SPDX-License-Identifier: GPL-2.0

#include <linux/init.h>
#include <linux/module.h>
#include "hello1.h"

MODULE_AUTHOR("Andrii Koreniuk");
MODULE_DESCRIPTION("Laboratory Work #5 (Advanced Level)");
MODULE_LICENSE("GPL");


static uint linecount = 1;
module_param(linecount, uint, S_IRUGO);
MODULE_PARM_DESC(linecount, "Count of 'Hello World' outputs.");

extern void print_hello(void);

extern void print_time(void);

static int __init initial_function(void)
{
	int step = 0;

	if (linecount > 10) {
		pr_err("[ERROR] Value of count more than 10!\n");
		return -EINVAL;
	}
	if (linecount == 0 || (linecount >= 5 && linecount <= 10))
		pr_warn("[WARN] Value of count: 0 OR [5;10]!\n");

	while (step < linecount) {
		print_hello();
		step = step + 1;
	}
	return 0;
}

static void __exit clean_function(void)
{
	int step = 0;

	while (step < linecount) {
		print_time();
		step = step + 1;
	}
}

module_init(initial_function);
module_exit(clean_function);
