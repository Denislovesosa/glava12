#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void error(char *msg)
{
	fprintf(stderr, "%S: %s\n", msg, strerror(errno));
	exit(1);
}

void* function1()
{
	puts("первая функция запустилась");
	sleep(5);
	puts("первая функция завершилась");
	return NULL;
}

void* function2()
{
	puts("вторая функция запустилась");
	sleep(3);
	puts("вторая функция завершилась");
	return NULL;
}

int main() {
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, function1, NULL) == -1)
		error("не могу создать поток t1");
	if (pthread_create(&t2, NULL, function2, NULL) == -1)
		error("не могу создать поток t2");
	
	void* result;
	if (pthread_join(t1, &result) == -1)
		error("cont join t1");
	if (pthread_join(t2, &result) == -1)
		error("cant join t2");

	return 0;
}
