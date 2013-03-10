int file_open( char *name)
{
/* 
 * get_ptr_to_inode(name)
 * fd = add inode to list of open fds
 * return fd
 */
}

int file_write(int fd, char data[], int size)
{
 /* inode = openfds[fd]
 * based on offset, decide to alloc a block or overwrite
 * if (blockalloc)
 *    fs_blk_alloc()
 *    offset = new block
 * else
	offset = findoffsetfrom inode
 * disk_write(offset,data)
 */
}


int file_read(int fd, char read_buf[], int size)
{
}


int file_close(int fd)
{
}