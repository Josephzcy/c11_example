### log
1. WAL技术：
  + redolog 更新到内存，在"不忙的时候"更新到磁盘
2. crash_cache
2. redolog:物理日志
  + 循环队列：check_point和write_point
3. binlog：逻辑日志
4. redolog 和 binlog
  ![bin_log](../docs/images/bin_log.png)