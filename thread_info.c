#include <sys/syscall.h>

#include "ruby.h"

VALUE thread_tid(VALUE self) {
	pid_t tid = syscall(SYS_gettid);
	return INT2NUM(tid);
}

void Init_thread_info() {
	VALUE rb_cThread = rb_const_get(rb_cObject, rb_intern("Thread"));
	rb_define_method(rb_cThread, "tid", thread_tid, 0);
}
