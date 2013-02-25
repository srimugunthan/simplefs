




get_ptr_to_inode(char *name)
{
	/*
	search in dir entry cache
	if search failed
		parse name by / (/x/y/z)
		read inode of x
		and check for y
		find y's inode
		recurse like this till you find the target inode
	*/

}



search_dir_entry_cache()
{
 /* simple linear search 
   or hash (name) search
 */
 
 /*  cache to be maintained in LRU manner
 */
}




