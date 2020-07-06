# C++笔记

[TOC]

## 4.表达式

#### decltype和auto的区别

- **auto**

**auto推断基本类型**：一条语句中可以声明多个变量，但是这些变量必须是一个类型，不然会报错。

**auto推断引用**：在涉及引用类型的推断的时候，编译器将引用对象的类型作为推断类型。

**auto与const相关的推断**：顶层 const 会被忽略，底层 const会被保留

**auto声明函数指针**：通过尾置返回类型来实现。

```c++
auto f()->int (*)(int,int) //返回一个指向int（int，int）的指针
// func接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组
auto func(int i) -> int (*) [10];
```

- **decltype**

**基本使用方法**：`decltype(f()) sum=x;  //sum的类型就是f返回值的类型`

**处理顶层const (与auto不相同)**：

```c++
const int ci=0;
decltype(ci) x=0;   //x的类型是const int
```

**decltype和引用 (与auto不相同)**：

​	如果 decltype 使用的表达式不是一个变量，则 *decltype* 返回表达式结果对应的类型

```c++
int i=42,*p=&i,&r=i;
decltype(r+0) b; //b为int
```

​	如果 *decltype* 使用表达式的结果类型可以作为一条赋值语句的**左值**，那么 *decltype* 返回一个引用类型，例如解引用操作和变量加括号的类型。

```c++
decltype(*p) c=n; //c为int&，必须初始化
decltype((i)) d;  //d为int&，必须初始化
```

​	如果表达式类型本身就是一个引用类型，那么 *decltype* 返回对应类型的引用类型。

```c++
const int &cj=ci;
decltype(cj) y=x;   //y的类型是const int&，y绑定到x上
```

**decltype与函数指针**：

​	*decltype* 声明函数指针的时，关键是要记住 *decltype* 返回的是一个函数的类型的，因此要加上 * 声明符才能构成完整的函数指针的类型。

```c++
string::size_type sumLength(const string&,const string&);
decltype(sumLength)* getFcn(cosnt string&);//返回指向sumLength的指针
```



### 类型转换 *cast-name<type\>(expression)*

- **static_cast**

  1. 当需要把一个较大算数类型赋值给较小的类型时，**static_cast**非常有用

     ```c++
     double slope = static_cast<double>(j) / i;
     ```

  2. 将指针从void*转换回原来的类型

     ```c++
     void* p = &d;
     double *dp = static_cast<double*>(p);
     ```

  3. 作类间基类子类指针引用的转换，但没有保证安全性；子转基类是安全的但是基类转子类没有动态类型检查不安全

- **const_cast**

  1. 只有**const_cast**可以改变表达式的常量属性
  2. 不能用**const_cast**改变表达式的类型

- **dynamic_cast**

  1. 用于将基类的指针或引用安全地转换成派生类的指针或引用

     ```c++
     dynamic_cast<type*>(e) // 若失败返回0
     dynamic_cast<type&>(e) // 若失败 抛出异常
     dynamic_cast<type&&>(e)
     ```

- **reinterpret_cast**

## 6. 函数

### 内联函数好处

调用函数一般比球等价表达式的值要慢一些。一次函数调用其实包含一系列工作：调用前要先保存寄存器，并在返回时恢复；可能需要拷贝实参；程序转向一个新的位置继续执行。

内联函数可以避免函数调用的开销。将函数指定为内联函数，通常就是将它在每个调用点上“内联的展开”。

一般来说内联机制用于优化规模较小、流程直接、频繁调用的函数



## 8. IO库

### IO类

#### 类型定义

- iostream定义了用于读写流的基本类型
- fstream定义了读写命名文件的类型
- sstream定义了读写内存string对象的类型

#### 我们不能拷贝或者对IO对象赋值：

```c++
ofstream out1, out2;
out1 = out2; // 错误：不能对流对象赋值
ofstream print(ofstream); // 错误：不能初始化ofstream参数
out2 = print(out2); // 错误：不能拷贝流对象
```

由于不能拷贝IO对象，因此我们也不能将形参或返回类型设置为流类型。进行IO操作的函数通常以引用的方式传递和返回流。

#### 管理缓冲输出

每个输出流都管理一个缓冲区，用来保存程序读写的数据
导致缓冲刷新（即，数据真正写到输出设备或文件）的原因有很多：

- 程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行
- 缓冲区满的时候，需要刷新缓冲，而后新的数据才能继续写入缓冲区
- 可以使用操纵符endl来显式刷新缓冲区。
- 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流的时候，关联到的流的缓冲区会被刷新。例如在默认情况下(标准库就是这样做的)，cin和cerr都关联到cout，因此读cin或者是写cerr都会导致cout的缓冲区被执行

#### 刷新输出缓冲区

- 操纵符endl完成换行并刷新缓冲区的工作。
- flush刷新缓冲区，但是不输出任何额外的字符
- ends向缓冲区插入一个空字符，然后刷新缓冲区

```c++
cout << "hi" << endl; // 输出hi和一个换行，然后刷新缓冲区
cout << "hi" << flush; // 输出hi，然后刷新缓冲区，不添加任何额外字符
cout << "hi" << ends; // 输出hi和一个空字符串，然后刷新缓冲区
```

### 文件输入输出

#### 类型定义

- ifstream从一个给定的文件读取数据
- ofstream向一个给定文件读入数据
- fstream可以读写给定文件

**当一个fstream对象被销毁时，close会自动被调用。即会自动构造和析构**

### string流

#### 类型定义

- istringstream 从string中读取数据
- ostringstream向string写入数据
- stringstream既可从string中读取数据也可向string中写数据
