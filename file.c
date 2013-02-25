int file_open( char *name)
{
/* 
 * get_ptr_to_inode(name)
 * fd = add inode to list of open fds
 * return fd
 */
}

file_write(int fd, offset, data[])
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
