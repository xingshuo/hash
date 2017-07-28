Hash
========
    integer key hash algorithm lib
Wiki
-----
    该算法和lua table的hash算法类似，提供一种简单有效的针对整数key实现哈希的方案.
    很多开源库使用该算法作为其内部的hash实现，但都与其内部逻辑耦合太深.
    为了避免重复造轮子，独立成库方便其它项目使用.
    该算法不负责哈希节点value值的内存释放，但插入,查询,删除的接口会返回value，使用者可自由处理
For Linux
-----
    make run