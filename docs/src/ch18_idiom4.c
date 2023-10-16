// https://programming-idioms.org/idiom/155/delete-file
#include <unistd.h>
int main(void)
{
	if (unlink("a.out") == -1)
		err(1, "unlink");
	return 0;
}