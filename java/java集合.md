﻿# java集合

标签（空格分隔）： 未分类

---
##List接口
1. List接口可以存放任意的数据，而且List接口中的内容是可以重复的
2. List接口常用的子类  

 - [ ] ArrayList
 - [ ] Vector   

### 常用操作
- [ ] 判断集合是否为空：boolean isEmpty();
- [ ] 查找指定婧对象是否存在： int indexOf(Object o);
```java
package cn.ynnu.corejava.collection;

import java.util.ArrayList;
import java.util.List;

public class LIstDemo01 {
	public static void main(String[] args) {
		List<String> lists = null;//声明
		lists = new ArrayList<String>();//引用
		lists.add("a");
		lists.add("b");
		for(int i = 0; i < lists.size(); i++) {
			System.out.println(lists.get(i));
		}
		
	}
}

```
#### 比较
| 比较        | ArrayList     | Vector     |
| ----------- |:-------------:| -----:     |
| 推出时间    | JDK1.2        | JDK1.0     |
| 性能        | 采用异步处理方式，高性能|       采用同步处理方式，低性能|
| 线程安全    |属于非线程安全| 属于线程安全|

## Set接口
1. Set接口中不能加入重复的元素，但是可以排序
2. Set接口中常用的子类

 - 散列存放：HashSet
 - 有序存放：TreeSet     

## Iterator接口
- 集合输出的标准操作
- 操作原理： Iterator专门的迭代输出接口，迭代输出就是将元素一个个进行判断，判断其是否有内容，如果有内容则把内容取出
- Collection接口扩展了Iterator接口，所以对于标准类库中的任何集合都可以使用for each循环;
常用操作：isRmputy, indexOf()
```java
package cn.ynnu.corejava.collection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class ListDemo02 {
	public static void main(String[] args) {
		List<String> list = new ArrayList<String>();
		list.add("A");
		list.add("B");
		list.add("C");
		list.add("D");
		list.add("E");
		list.add("F");
		
		Iterator<String> iter = list.iterator();
		while(iter.hasNext()) {
			System.out.println(iter.next());
		}
		
		list.remove(5);//传入下标
		Iterator<String> iter2 = list.iterator();
		while(iter2.hasNext()) {
			System.out.println(iter2.next());
		}
	}
}

```
**注意**： List，Collection，Set都有一个remove方法，
在进行迭代输出时一定不能使用集合自带的remove方法，要用迭代输出自带的remove进行操作;
如果由多个迭代器同时对同一个集合进行操作，如果有一个使用了迭代器的remove方法，也会抛出异常;

## java.util.Map

存放Hash键值对对象

key both unique

实现:

- HashTable 不允许有null值（key和value）线程安全
- HashMap 允许有null值（key 和value都可以）非线程安全