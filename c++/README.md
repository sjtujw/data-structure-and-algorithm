# C++ 面试知识点
## 多态<br>
C++的多态性用一句话概括：在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数。如果对象类型是派生类，就调用派生类的函数；如果对象类型是基类，就调用基类的函数。<br>
1. 用virtual关键字申明的函数叫做虚函数，虚函数肯定是类的成员函数； 
2. 存在虚函数的类都有一个一维的虚函数表叫做虚表，类的对象有一个指向虚表开始的虚指针。虚表是和类对应的，虚表指针是和对象对应的；
3. 多态性是一个接口多种实现，是面向对象的核心，分为类的多态性和函数的多态性。；
4. 多态用虚函数来实现，结合动态绑定.；
5. 纯虚函数是虚函数再加上 = 0； 
6. 抽象类是指包括至少一个纯虚函数的类；<br>
纯虚函数：virtual void fun()=0;即抽象类，必须在子类实现这个函数，即先有名称，没有内容，在派生类实现内容。<br>
## 虚函数实现（虚函数表）
## 内存分配<hr>
分为5个区：堆、栈、全局/静态存储区、常量存储区和代码区<br>
1. 栈：就是那些由编译器在需要的时候分配，在不需要的时候自动清除的变量的存储区，里面的变量通常是**局部变量、函数参数**等。
2. 堆：就是那些由**new**分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。
3. 全局/静态存储区：全局变量和静态变量被分配到同一块内存中，在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区。
4. 常量存储区：这是一块比较特殊的存储区，他们里面存放的是**常量**，不允许修改（当然，你要通过非正当手段也可以修改）。
5. 代码区（.text段）：存放代码（如函数），不允许修改（类似常量存储区），但可以执行（不同于常量存储区）。
内存模型组成部分：自由存储区，动态区，静态区<br>
- 自由存储区：局部非静态变量的存储区域，即平常所说的**栈**；
- 动态区： 用**new ，malloc**分配的内存，即平常所说的**堆**；
- 静态区：全局变量，静态变量，字符串常量存在的位置；
## 协程、线程和进程