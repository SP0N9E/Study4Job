# Study4Job
为了准备秋招而做的准备

[TOC]

## 准备过程

想投图形学相关的岗位，在分析了之前实习面试时候的问题之后，我觉得应该将精力放在图形学、c++语言特性以及算法数据结构上。

c++：七月初开始一天看一章c++ primer，7.4回家之后花了五六天看完了cpp primer，但是其中还是有好多理解不到位的地方，于是接着看effective c++。看完之后做好总结，再去看其他人的面经，理解就更加深刻一点了。

图形学：因为四月自己就看过b站上GAMES101闫老师的图形学基础，当时做了笔记，于是最开始就先看了当时自己的笔记并且配套食用了闫老师放出来的课件。在这之后感觉3D数学不太好很多东西不理解，就去看了《3D数学基础 图形与游戏开发》。在这期间随手翻了翻《Fundamentals-of-Computer-Graphics-Fourth-Edition》。看完3D数学之后，本来想看原版的《Real-Time Rendering, Fourth Edition》，但是因为面试要来了，就只能去知乎上看浅墨总结的RTR核心知识提炼，了解更多的图形学知识(RTR这本书感觉像是论文汇编这样？)。之后本来觉得可以了，但是面试的时候被问会不会写shader，我只能说以前会但是现在我忘记了，很尴尬。回来后开始看《Unity shader入门精要》。看了之后对于管线的理解更深了一点，也了解了Unity里写shader 的方法。

算法数据结构：这方面其实我做的不咋地，面试最怕的就是问我算法的那个时候。目前刷了leetcode大概100道，也做了剑指offer。感觉《剑指offer》这本书还是很不错的，教了我很多之前我不重视的代码方面的注意事项，包括在写码之前要问清楚面试官输入的格式啊之类的。



## LeetCode



## c++ primer

花了一周差不多通读了一遍，以后得抽时间逐章细读一遍



## 计算机网络



## 面试记录

### 字节抖音互娱图形图像工程师

#### 一面 7/21

*面试大叔看起来不是很友善，但后来发现就是自己吓自己，可能刚好只是不爱笑的那种吧…*

手写代码解释多态（base 类 derive类等等）

冒泡 二分查找 输出二叉树第k层的节点

渲染管线

顶点/片元着色器做了什么，做了多少次

还有一些想不起来了…

#### 二面 7/22

*面试官小姐姐很友善，也很喜欢笑，所以面试的时候压力小了很多。然而牛客网面试也太不稳定了，重连了好多次…*

判断已知代码的输出，也是多态、继承的知识点

项目

渲染管线

具体如何推导矩阵变换（说出大概意思就可以

二叉树zigzag遍历

写过shader吗（写过 但是现在都忘记了…

八个球最少需要几次才能找到其中一个轻一点的球

圆上有三点，求这三点在一个半圆上的概率

函数返回时返回了`vector<vector<int>> `，可以在内存上进行一些优化吗？

#### hr面 7/26

*我也不知道为啥hr面放在中间了……*

自我介绍

对未来公司的薪资以及公司的其他方面有什么要求

自己的缺点

猜猜前面的面试官对你的印象，以及分析之前的面试表现中哪些是不足的？

期望工作的地点

其他有点忘记了…

#### 三面 7/27

*应该是最后一轮技术面了*

部门leader上来问了一些hr会问的问题，例如工作地点，平时除了上课会怎么安排自己的生活等

后来说因为是技术面所以得做两道题

手写一些变换对应的矩阵(MVP矩阵)

手写代码，将两个非递增数组合并成一个严格非递增数组（就是没有重复的意思）。刚开始没理解意思写错(重复)了，后来改了一下才对。

之后就是主动介绍了一些业务，然后我问了一些关于未来部门发展规划的问题，面试官又向我介绍了一下未来发展规划。

#### 7/30 

hr告诉我终面通过了。许愿offer

#### 8/5

拿到意向书啦





### 腾讯游戏客户端开发

####  一面 8/12

*一面面试官感觉是个年轻人，虽然戴着口罩但我还是觉得他有些不苟言笑，所以不清楚自己表现怎么样*

刚开始上来聊了聊现在在哪，然后自我介绍。

接下来花了大概半小时询问我简历上的每一个项目（几乎都问过了），然后对不理解的地方提出疑问

渲染管线介绍

如何把一张二维图像渲染到屏幕上(我讲了应该分情况来考虑，相机上的UI和世界坐标下的UI;虽然感觉思路上应该没差很多，但是表述应该不太好。 看看这个网页https://juejin.im/post/6844903937225523208)

fragment shader内的具体流程(使用了哪些数据做一个怎么样的计算)

在纹理相对较大的时候，如何把纹理贴上去(MSAA，Mipmap，各向异性)

如果有一堆数据，你会使用什么排序算法（我说我觉得得看数据量，数据量小就不用快排之类的，量大就用快排归并）

那你说的这些算法稳定吗

有一个玩家的排行榜，你觉得得用什么排序算法来进行排序（我觉得得用堆排序，用树状结构应该是对的，但距离答案应该还有差距。可以看看这个https://www.zhihu.com/question/27933771）

vector的sort函数你知道他是怎么实现的吗（我说我记得看到过这个sort函数有点像多个排序算法的结合，依照数据量的不同采用不同的排序算法）【STL中的sort()函数在数据量大的时候采用quick sort，分段后的数据量小于某一个门槛时便采用insertion sort。】

手撕代码 [小Q逛街](https://www.nowcoder.com/questionTerminal/35fac8d69f314e958a150c141894ef6a)

没想到用栈的方法，直接遍历只通过了60%的case…而且在面试官提醒用栈之后还是想不出来（捂脸）

感觉代码这块要拉跨了555 现在复盘下来感觉有些地方也回答不正确，有点担心

#### 二面 8/19

*二面面试官感觉是个香港/广东人，好多话我都听不懂（*

自我介绍

项目介绍

c和c++的区别

解释c++多态、继承

有虚函数的类内部的内存分布

调用函数地址的时候发生了什么事情（回答的极其简略  从这个问题开始就崩了）

TCP、HTTP的区别（我真的崩了  真的忘记了草草草草）

导航系统，假设从杭州到深圳，你怎么规划（回答最小割）

你有啥问题吗

本来这次面试13:30~14:10结果14:00就问我还有没有什么问题

我觉得我没了，腾讯复试真是永远滴痛，上次实习面试也是挂在复试，我吐了。

我觉得我必没了，蓝瘦香菇。

















