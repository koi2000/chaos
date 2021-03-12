# Java

### 做题：

#### 1.

1.可以使用builder方法创建对象
2.工厂化创建 new Cat(name,age);
3.可以使用this(name,age);
4.long i1= (long) i+1;    强制类型转换
5.引用类型可以直接利用函数获得最大值最小值
    Float.MAX_VALUE
    Double.MAX_VALUE
    public static long maxLong = 9223372036854775807L;
6.基本数据类型比较的是值
   引用类型比较的是地址值
7.有BigDecimal引用类型
    高精度

```java
// 判断两个double是否相等
    public static boolean doubleEquals(double a, double b) {
        BigDecimal a1=new BigDecimal(a).setScale(4, RoundingMode.DOWN);
        BigDecimal b1=new BigDecimal(b).setScale(4,RoundingMode.UP);
        //System.out.println(a1);
        a=a1.doubleValue();
        b=b1.doubleValue();
        //System.out.println(b1);
        return a == b;
```

8.对象的初始化顺序

```java
public class Cat {
    public static int count = initStaticCount();

    int age = initAge();
    String name;
    
    public static int initStaticCount() {//静态方法第一
        System.out.println(1);
        return 0;
    }
    
    static {//static 方法排第二
        System.out.println(2);
    }

    public int initAge() {//非静态方法排第三
        System.out.println(3);
        return 0;
    }
    
    {//无修饰符方法排第四
        System.out.println(4);
    }

    {
        System.out.println(5);
    }

    public Cat(int age, String name) {//全参构造排第六
        this.age = age;
        this.name = name;
        System.out.println(6);
    }
    
    public Cat(String name) {//仅处理传进来的参数排第七
        this(0, name);
        System.out.println(7);
    }

    
```

10.数据类型的转换

```java
package com.github.hcsp.datatype;

import com.sun.jdi.LongType;

import java.util.function.LongToIntFunction;

public class Cast {
    // Cast an int to byte
    // 将int类型转换成byte
    public static byte int2byte(int i) {
        return (byte)i;
    }

    // Cast an int to short
    // 将int类型转换成short
    public static short int2short(int i) {
        return (short)i;
    }

    // Cast an int to char
    // 将int类型转换成char
    public static char int2char(int i) {
        return (char)i;
    }

    // Cast an int to String, e.g. 123 -> "123"
    // 将一个整数转换为字符串，例如，将123转换成字符串"123"
    public static String int2String(int i) {
        String a=Integer.toString(i);
        return a;
    }

    // Cast an String to int, e.g. "123" -> 123
    // 将一个字符串转换成整数，例如，将字符串"123"转换成整数123
    public static int string2int(String s) {
        int num1=Integer.parseInt(s);
        return num1;
    }

    // Cast an String to double, e.g. "1.23" -> 1.23
    // 将一个字符串转换成double类型，例如，将字符串"1.23"转换成1.23
    public static double string2double(String s) {
        double a=Double.parseDouble(s);
        return a;
    }

    // Cast an Long to int
    // 将Long类型转换成int
    public static int Long2int(Long l) {
        int a= l.intValue();
        return a;
    }

    // Cast an Double to long
    // 将Double类型转换成long
    public static long double2Long(Double d) {
        long a=d.longValue();
        return a;
    }

```

