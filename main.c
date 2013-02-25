#include "common.h"


void test(void) {
	//char buf[] = "hello";
	char buf[4096];
	char read_buf[4096+3];
	int i;
	
	for(i = 0; i < 4096; i++)
		buf[i] = 'h';

	fs_creat(0);
	fs_write(0, buf, sizeof(buf));
	fs_ls();
	fs_creat(1);
	fs_write(1, "world", 6);
	fs_write(0, "fs", 3);
	fs_ls();
	buf[0] ='a';
	buf[1] = 'b';
	buf[2] = 'c';
	fs_read(0, read_buf, 4099);
	//for(i = 0; i < 50; i++)
	printf("rdbuf %c\n",read_buf[4097]);
	printf("rdbuf %c\n",read_buf[4096]);
	printf("rdbuf %c\n",read_buf[4095]);
	printf("rdbuf %c\n",read_buf[4094]);
	printf("rdbuf %c\n",read_buf[4098]);
}


int main() 
{
	
	mk_myfs();
	fs_mount();
	
	test();
	fs_unmount();
	fs_mount();
	fs_ls();
			
}

