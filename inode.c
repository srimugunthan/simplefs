



#include "common.h"

#if 0
/* In-memory inode. */
struct inode 
  {
    struct list_elem elem;              /* Element in inode list. */
    disk_sector_t sector;               /* Sector number of disk location. */
    int open_cnt;                       /* Number of openers. */
    bool removed;                       /* True if deleted, false otherwise. */
    int deny_write_cnt;                 /* 0: writes ok, >0: deny writes. */
    struct inode_disk data;             /* Inode content. */
  };
#endif

get_offset()
{
}

void set_bitmap(char *start_ptr, int bit) {
 	
	int bytenum = bit/8;
	int bitwithinbyte = bit%8;
	char *ptr;
	ptr = (start_ptr+bytenum)
	*ptr |= (1<<(bitwithinbyte));		
	
}

void clr_bitmap(char *start_ptr, int bit) { 
	int bytenum = bit/8;
	int bitwithinbyte = bit%8;
	char *ptr;
	ptr = (start_ptr+bytenum)
	*ptr &= ~(1<<(bitwithinbyte));		
	
	
}

int  check_bitmap(char *start_ptr, int bit) {
	int bytenum = bit/8;
	int bitwithinbyte = bit%8;
	char *ptr;
	ptr = (start_ptr+bytenum)
			
	return ((*ptr)&(1<<bitwithinbyte)); 
}

int find_first_bit(char *start_ptr, int bit) 
{
	
}

int search_free_inode_num()
{
	char *ptr;
	int inode_num=0;
	ptr = superblk->superblk->inode_bitmaparea_start;
	while(((*ptr) & 0x11 != 0x11)
	{
		ptr++;
		if(ptr > superblk->superblk->inode_bitmaparea_start + SECTOR_SIZE)
		{
			return -1;	
		}
		inode_num+=8;
	}
	
	inode_num = inode_num + find_first_bit(ptr);
	return inode_num;
			
	
}
struct inode *inode_create()
{
	/* mark inode bitmap
  	 * store default inode info
	 * 
 	 */
	int i;

	struct inode inode_tmp;
	
	inode_tmp.i_mode= 0;		/* file type, protection, etc. */
	inode_tmp.i_nlinks=0;		/* how many links to this file */
	inode_tmp.i_uid=0;			/* user id of the file's owner */
	inode_tmp.i_gid= 0;			/* group number */
	inode_tmp.i_size = 0;			/* current file size in bytes */
	inode_tmp.i_atime =0;		/* time of last access (V2 only) */
	inode_tmp.i_mtime=0;		/* when was file data last changed */
	inode_tmp.i_ctime=0;		/* when was inode itself changed (V2 only)*/
	//unsigned long i_zone[V2_NR_TZONES]; /* zone numbers for direct, ind, and dbl ind */
	for(i = 0; i < NUM_DIRECT_BLKS;i++)
		inode_tmp.dirblks[i] = NULL; 
	for(i = 0; i < NUM_INDIRECT_BLKS;i++)
		inode_tmp.in_dirblks[i]=NULL; 
	for(i = 0; i < NUM_DBL_INDIRECT_BLKS;i++)
		inode_tmp.dbl_in_dirblks[i]=NULL; 

	search_free_inode_num();

}

inode_read()
{
}
