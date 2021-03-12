varchar//字符串
bigint//long类型
sql语句
DQL（数据查询语言）查询语句 select
DML（数据操作语言）对表中数据进行增删改 insert deldete update 
DDL（数据定义语言）对表结构增删改 create drop alter
TCL(事物控制语言) commit提交事务 rollback回滚事务 savepoints
DCL（数据控制语言） grant授权 revoke撤销权限
4.导入数据
  1.登录
  2.show databases; (MySQL命令语句，非SQL语句)
  3.create database bjnode; (MySQL命令语句，非SQL语句)
  4.use bjnode; (MySQL命令语句，非SQL语句)
  5.查看当前使用的数据库中有那些表格 show tables; (MySQL命令语句，非SQL语句)
  6.初始化数据
  7.show tables; 查看表 desc查看表结构
  8.表中的数据
  9.select database(); 查看当前使用的数据库
    select version();  查看当前使用的数据库版本  
    \c 结束一条语句
    exit 退出MySQL
    desc 查看表结构
  10.查看创建表的语句
    show create table emp; 
  11. 简单的查询语句

    select 字段名1，字段名2，字段名3 from 表名 
    sql语句以“；”结尾    sql语句不区分大小写
    查询年薪 （字段可以参与数学运算）
    给查询结果的列重命名 select ename sal*12 as yearsal from emp;
    标准sql语句中仅支持名称中有中文要用‘’括起来；
    MySQL中可以用“”括起来表示字符串
    可以省略as用空格来代替
    select *from emp; (可以查看表中所有元素) （尽量少用，*效率较低）
  12.条件查询
    语法格式
        select 
           字段名1，字段名2，字段名3
        from
           表名
        where
           条件；
        （查询工资等于5000的员工的姓名） select ename from emp where sal=5000;      
         (查询SMITH的工资) select sal from emp where ename='SMITH';
         (找出工资高于3000的员工) select ename,sal from emp where sal>3000;  
         (找出工资不等于3000) select ename,sal from emp where sal<>3000;
                             select ename,sal from emp where sal ！= 3000; （貌似不可用？）       
        （找出工资在1100和3000之间的员工，包括1100和3000）
         select ename,sal from emp where sal>=1100 and sal<=3000;
         between and
         select ename,sal from emp where sal between 1100 and 3000;(闭区间)
         还可以用于字符串（左闭右开）
         找出那些人津贴为NULL （在数据库中NULL不是一个值）
         select ename from emp where comm is null;
         select ename from emp where comm is not null;
         select ename from emp where comm is null or comm = 0;
         找出工作为manger和为salesmen的员工
         select ename ,job from emp where job ='MANGER' or job ='SALESMAN';
         and和or联合使用
         找出薪资大于1000的并且部门编号为20或30部门的员工
         select ename, deptno from emp where sal >1000 and (deptno =20 or deptno =30);  
         and 优先级高 优先级不确定的加小括号
         in 相当于or select ename,job from emp where sal in(1000,5000);  
                    (找出工资为1000和5000的)
         not in (不在这几个值之间的)
         like (模糊查询)
          找出名字中有o的
    13.排序（升序，降序）
        select *from t_studentgrade order by sum; (默认升序排列) （asc升序 desc降序）
        select *from t_studentgrade order by sum desc;
        (按工资的降序排，工资相同按名字的升序排)
        select ename,sal from emp order by sal desc ,ename asc;
        select 字段名 from 表名 where 条件 order by 字段 排序方式；      

    14. 分组函数
          count 计数 
          sum   求和
          avg   平均值
          max   最大值
          min   最小值
          分组函数对"某一组"数据操作
          找出工资总和
              select max(sal) from emp;
          分组函数只有五个 （也叫多行处理函数，输入多行，输出一行）
          分组函数自动忽略NULL
          SQL语句中分组函数不可直接使用在where字句中 
          count(*) 和 count(具体的字段)的区别 
          count(*):不是统计某个字段中数据的个数，而是统计总记录的条数（与字段无关）
          count(comm):表示统计comm字段中不为NULL的数据总数量
          分组函数可以组合起来使用
        15.单行处理函数
         计算每个员工的年薪  (所有数据库中如果与null计算结果为null)
         select ename,(sal+comm)*12 as yearsal from emp;
         ifnull(可能为NULL的数据,被当作什么处理);    (空处理函数)
        16.group by 和 having
              group by ：按照某个字段或者某些字段进行分组 (执行顺序小于where,
              分完组后才能执行分组函数)
              having :  having是对分组之后的数据进行再次过滤
              select job,avg(sal) from emp group by job having avg(sal) >2000;
              当一条sql语句中没有group by语句时整张表的数据自成一组。
             找出每个工作岗位的最高薪资
             select ename,max(sal) from emp group by job;
              找出工资高于平均工资的员工
        第一步：找出平均工资
                select avg(sal) from emp;
                +-------------+
                | avg(sal)    |
                +-------------+
                | 2073.214286 |
                +-------------+
        第二步：找出高于平均工资的员工
                select ename,sal from emp where sal>2073.214286;
        17.完整的sql语句                       
              select   5
              .....
              from     1
              .....
              where    2
              .....
              group by 3
              .....
              having   4
              .....
              order by 6
              .....;
              一些简单的句子
              ctrl c 强行终止
    1.查询结果集的去重
        distinct只能出现在所有字段的最前面
        select distinct deptno ,job from emp;    (加到最前面的的意思是联合起来去重) 
        统计岗位数量
        select count(distinct job) from emp;
    2.连接查询
        2.1 什么是连接查询
            大多数情况下都不是单表查询 实际中一个业务对应多张表
        2.2 连接查询的分类
          根据语法出现的年代来划分  
            SQL92（一些老的DBA可能还在使用这种语法）
            DBA: DataBase Administrator  数据库管理员
            SQL99(较新的语法)    
          根据表的连接方式来划分
            内连接
              等值连接
              非等值连接
              自连接
            外连接
              左外连接（左连接）
              右外连接（右连接）
            全连接（用的较少） 
        2.3 表的连接查询方面有一种现象被称为（笛卡尔积现象） 也叫（笛卡尔乘积现象）
            案例：找出每个员工的部门名称，要求显示员工名和部门名
            select ename,deptno from emp;
            select ename,dname from emp,dept;
            (如果两张表连接查询而没有任何限制，查询结果条数为两张表中记录条数的乘积)
            关于表的别名
              select e.ename,d.dname from emp e,dept d;
              (执行效率高，可读性强)
        2.4 避免笛卡尔积现象  加条件进行过滤
            （避免了笛卡尔积现象，并不会减少记录的匹配次数）          
            案例：找出每个员工的部门名称，要求显示员工名和部门名
                  select 
                    e.ename,d.dname
                  from
                    emp e,dept d
                  where
                    e.deptno=d.dept  
                  (92语法，以后不用)     
        2.5 内连接之等量连接
            最大特点：条件是等量关系
            案例：查询每个员工的部门名称，要求显示员工名和部门名
            SQL92 (太老了，不常用)
                 select 
                 e.ename,d.dname
                 from 
                 emp e,dept d
                 where 
                 e.deptno=d.deptno; 
            SQL99
                 select 
                   e.ename,d.dname
                 from 
                   emp e
                 inner join
                   dept d
                 on 
                   e.deptno=d.deptno;
                 (on后跟连接条件，后面可以继续加where)
                （inner可以省略，带着inner可读性强）
        2.6 内连接之非等值连接
            案例：找出每个员工的工资等级，要求显示员工名、工资、工资等级。
            select 
               e.ename,e.sal,s.grade
            from 
               emp e
            join
               salgrade s
            on
               e.sal between s.losal and s.hisal; 
        2.7 自连接
          最大特点：一张表看作两张表 自己连接自己
          (inner可以省略)
          案例：找出每个员工的上级领导，要求显示员工和对应领导名
          select 
            a.ename,b.ename
          from
            emp a
          inner join
            emp b
          on 
            a.mgr=b.empno;       
        2.8 外连接
          内连接：假设A与B进行连接，凡是A与B能匹配上的记录查询出来，这就是内连接
                  无主副之分
          外连接：有一张表为主表，一张为副表，主要查询主表，捎带着查询副表
                  副表中的数据无与主表匹配的，自动匹配NULL；  
                  主表中的数据无条件的全部查询出来
                分类：
                    左外连接（左连接）：左边的表为主表
                    右外连接（右连接）：右边的表为主表
                    左连接有右连接的写法
                    右连接有左连接的写法
                    案例：找出每个员工的上级领导？（所有员工都必须查出来）
                    内连接写法：（king不会显示出来）
                    select 
                       a.ename,b.ename
                    from 
                       emp a
                    join 
                       emp b
                    on
                       a.mgr=b.empno; 
                    外连接写法：
                    select 
                       a.ename,b.ename
                    from 
                       emp a
                    left join 
                       emp b
                    on
                       a.mgr=b.empno; 
                    (带left说明左边是主表)
                    select 
                       a.ename,b.ename
                    from 
                       emp b
                    right outer join 
                       emp a
                    on
                       a.mgr=b.empno;
                    (outer可以省略)
                    案例：找出哪个部门没有员工？
                    select 
                      e.*,d.* 
                    from 
                      emp e  
                    right join 
                      dept d 
                    on 
                      e.deptno=d.deptno; 
        2.9 三张表的连接查询？
          案例：找出每个员工的部门名称以及工资等级
          ......
               A
            join
               B
            join
               C
              on
            ....
            表示：A表先和B表连接再和C表连接。         
          dept d
        
        ```
                  +--------+---------+--------+-------+
                  | ename  | sal     | deptno | grade |
                  +--------+---------+--------+-------+
                  | SMITH  |  800.00 |     20 |     1 |
                  | ALLEN  | 1600.00 |     30 |     3 |
                  | WARD   | 1250.00 |     30 |     2 |
                  | JONES  | 2975.00 |     20 |     4 |
                  | MARTIN | 1250.00 |     30 |     2 |
                  | BLAKE  | 2850.00 |     30 |     4 |
                  | CLARK  | 2450.00 |     10 |     4 |
                  | SCOTT  | 3000.00 |     20 |     4 |
                  | KING   | 5000.00 |     10 |     5 |
                  | TURNER | 1500.00 |     30 |     3 |
                  | ADAMS  | 1100.00 |     20 |     1 |
                  | JAMES  |  950.00 |     30 |     1 |
                  | FORD   | 3000.00 |     20 |     4 |
                  | MILLER | 1300.00 |     10 |     2 |
                  +--------+---------+--------+-------+
        ```
        
        ​          select 
        ​            e.ename,avg(s.grade)
        ​          from  
        ​            emp e
        ​          join
        ​            salgrade s
        ​          on  
        ​            e.sal between s.losal and s.hisal
        ​          group by 
        ​            e.deptno;  
        ​        4.select 后面嵌套子循环
        ​        案例：找出每个员工所在的部门名称，要求显示员工名和部门名
        ​        select 
        ​            e.ename,d.dname
        ​        from
        ​            emp e
        ​        join 
        ​            dept d
        ​        on 
        ​            e.deptno =d.deptno 
        | DEPTNO | DNAME | LOC  |
        | ------ | ----- | ---- |
        |        |       |      |
          +--------+------------+----------+
        | 10   | ACCOUNTING | NEW YORK |
        | ---- | ---------- | -------- |
        |      |            |          |
        | 20   | RESEARCH | DALLAS |
        | ---- | -------- | ------ |
        |      |          |        |
        | 30   | SALES | CHICAGO |
        | ---- | ----- | ------- |
        |      |       |         |
        | 40   | OPERATIONS | BOSTON |
        | ---- | ---------- | ------ |
        |      |            |        |
          +--------+------------+----------+
          salgrade s
          +-------+-------+-------+
        | GRADE | LOSAL | HISAL |
        | ----- | ----- | ----- |
        |       |       |       |
          +-------+-------+-------+
        | 1    | 700  | 1200 |
    | ---- | ---- | ---- |
        |      |      |      |
        | 2    | 1201 | 1400 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 3    | 1401 | 2000 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 4    | 2001 | 3000 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 5    | 3001 | 9999 |
        | ---- | ---- | ---- |
        |      |      |      |
          +-------+-------+-------+
          emp e
          +-------+--------+-----------+------+------------+---------+---------+--------+
        | EMPNO | ENAME | JOB  | MGR  | HIREDATE | SAL  | COMM | DEPTNO |
        | ----- | ----- | ---- | ---- | -------- | ---- | ---- | ------ |
        |       |       |      |      |          |      |      |        |
          +-------+--------+-----------+------+------------+---------+---------+--------+
        | 7369 | SMITH | CLERK | 7902 | 1980-12-17 | 800.00 | NULL | 20   |
        | ---- | ----- | ----- | ---- | ---------- | ------ | ---- | ---- |
        |      |       |       |      |            |        |      |      |
        | 7499 | ALLEN | SALESMAN | 7698 | 1981-02-20 | 1600.00 | 300.00 | 30   |
        | ---- | ----- | -------- | ---- | ---------- | ------- | ------ | ---- |
        |      |       |          |      |            |         |        |      |
        | 7521 | WARD | SALESMAN | 7698 | 1981-02-22 | 1250.00 | 500.00 | 30   |
        | ---- | ---- | -------- | ---- | ---------- | ------- | ------ | ---- |
        |      |      |          |      |            |         |        |      |
        | 7566 | JONES | MANAGER | 7839 | 1981-04-02 | 2975.00 | NULL | 20   |
        | ---- | ----- | ------- | ---- | ---------- | ------- | ---- | ---- |
        |      |       |         |      |            |         |      |      |
        | 7654 | MARTIN | SALESMAN | 7698 | 1981-09-28 | 1250.00 | 1400.00 | 30   |
        | ---- | ------ | -------- | ---- | ---------- | ------- | ------- | ---- |
        |      |        |          |      |            |         |         |      |
        | 7698 | BLAKE | MANAGER | 7839 | 1981-05-01 | 2850.00 | NULL | 30   |
        | ---- | ----- | ------- | ---- | ---------- | ------- | ---- | ---- |
        |      |       |         |      |            |         |      |      |
        | 7782 | CLARK | MANAGER | 7839 | 1981-06-09 | 2450.00 | NULL | 10   |
        | ---- | ----- | ------- | ---- | ---------- | ------- | ---- | ---- |
        |      |       |         |      |            |         |      |      |
        | 7788 | SCOTT | ANALYST | 7566 | 1987-04-19 | 3000.00 | NULL | 20   |
        | ---- | ----- | ------- | ---- | ---------- | ------- | ---- | ---- |
        |      |       |         |      |            |         |      |      |
        | 7839 | KING | PRESIDENT | NULL | 1981-11-17 | 5000.00 | NULL | 10   |
        | ---- | ---- | --------- | ---- | ---------- | ------- | ---- | ---- |
        |      |      |           |      |            |         |      |      |
        | 7844 | TURNER | SALESMAN | 7698 | 1981-09-08 | 1500.00 | 0.00 | 30   |
        | ---- | ------ | -------- | ---- | ---------- | ------- | ---- | ---- |
        |      |        |          |      |            |         |      |      |
        | 7876 | ADAMS | CLERK | 7788 | 1987-05-23 | 1100.00 | NULL | 20   |
        | ---- | ----- | ----- | ---- | ---------- | ------- | ---- | ---- |
        |      |       |       |      |            |         |      |      |
        | 7900 | JAMES | CLERK | 7698 | 1981-12-03 | 950.00 | NULL | 30   |
        | ---- | ----- | ----- | ---- | ---------- | ------ | ---- | ---- |
        |      |       |       |      |            |        |      |      |
        | 7902 | FORD | ANALYST | 7566 | 1981-12-03 | 3000.00 | NULL | 20   |
        | ---- | ---- | ------- | ---- | ---------- | ------- | ---- | ---- |
        |      |      |         |      |            |         |      |      |
        | 7934 | MILLER | CLERK | 7782 | 1982-01-23 | 1300.00 | NULL | 10   |
        | ---- | ------ | ----- | ---- | ---------- | ------- | ---- | ---- |
        |      |        |       |      |            |         |      |      |
          +-------+--------+-----------+------+------------+---------+---------+--------+
                select 
                  e.ename,d.dname,s.grade
                from 
                  emp e
                join 
                  dept d
                on 
                  e.deptno=d.deptno
                join
                  salgrade s
                on  
                  e.sal between s.losal and s.hisal;      
          案例：找出每个员工的部门名称、工资等级以及上级领导。
                select 
                  e.ename,d.dname,s.grade,e1.ename
                from 
                  emp e
                join 
                  dept d
                on 
                  e.deptno=d.deptno
                join
                  salgrade s
                on  
                  e.sal between s.losal and s.hisal
                left join 
                  emp e1
                on
                e.mgr=e1.empno;
            3 子查询
        1.什么是子查询？子查询用在哪里？
          select语句中嵌套select语句，被嵌套的select语句是子查询
          select
             ....(select)
          from 
             ....(select)
          where
             ....(select).
        2.where语句中使用子查询
          案例：找出工资高于平均工资的员工信息
          select *from emp where sal>avg(sal);  //错误，where语句中不能直接使用分组函数。
          第一步：找出平均工资
             select avg(sal) from emp;
          第二步：找出高于平均工资的员工
             select *from emp where sal >2073.214286;   
          合并：select *from emp where sal >(select avg(sal) from emp);
        3.from 后面加子查询
          案例：找出每个部门平均薪水的薪资等级。
          第一步：找出每个部门平均工资（按照部门编号分组，求出sal的平均值）
          select deptno,avg(sal) as avgsal from emp group by deptno;
          第二步：将以上的查询结果当作一张新表 将两张表和其他表做连接
          select 
            t.*,s.grade
          from
            (select deptno,avg(sal) as avgsal from emp group by deptno) t
          join 
            salgrade s
          on 
            t.avgsal between s.losal and s.hisal;    
          案例：找出每个部门薪资等级的平均值。
          第一步：找出每个员工的薪水等级。
          第二步：基于以上结果，继续按照deptno分组，求grade的平均值
          select 
            e.ename,e.sal,e.deptno,s.grade
          from  
            emp e
          join
            salgrade s
          on  
            e.sal between s.losal and s.hisal;               
        

    14. 分组函数
          count 计数 
          sum   求和
          avg   平均值
          max   最大值
          min   最小值
          分组函数对"某一组"数据操作
          找出工资总和
              select max(sal) from emp;
          分组函数只有五个 （也叫多行处理函数，输入多行，输出一行）
          分组函数自动忽略NULL
          SQL语句中分组函数不可直接使用在where字句中 
          count(*) 和 count(具体的字段)的区别 
          count(*):不是统计某个字段中数据的个数，而是统计总记录的条数（与字段无关）
          count(comm):表示统计comm字段中不为NULL的数据总数量
          分组函数可以组合起来使用
        15.单行处理函数
         计算每个员工的年薪  (所有数据库中如果与null计算结果为null)
         select ename,(sal+comm)*12 as yearsal from emp;
         ifnull(可能为NULL的数据,被当作什么处理);    (空处理函数)
        16.group by 和 having
              group by ：按照某个字段或者某些字段进行分组 (执行顺序小于where,
              分完组后才能执行分组函数)
              having :  having是对分组之后的数据进行再次过滤
              select job,avg(sal) from emp group by job having avg(sal) >2000;
              当一条sql语句中没有group by语句时整张表的数据自成一组。
             找出每个工作岗位的最高薪资
             select ename,max(sal) from emp group by job;
              找出工资高于平均工资的员工
        第一步：找出平均工资
                select avg(sal) from emp;
                +-------------+
                | avg(sal)    |
                +-------------+
                | 2073.214286 |
                +-------------+
        第二步：找出高于平均工资的员工
                select ename,sal from emp where sal>2073.214286;
        17.完整的sql语句                       
              select   5
              .....
              from     1
              .....
              where    2
              .....
              group by 3
              .....
              having   4
              .....
              order by 6
              .....;
              一些简单的句子
              ctrl c 强行终止
    1.查询结果集的去重
        distinct只能出现在所有字段的最前面
        select distinct deptno ,job from emp;    (加到最前面的的意思是联合起来去重) 
        统计岗位数量
        select count(distinct job) from emp;
    2.连接查询
        2.1 什么是连接查询
            大多数情况下都不是单表查询 实际中一个业务对应多张表
        2.2 连接查询的分类
          根据语法出现的年代来划分  
            SQL92（一些老的DBA可能还在使用这种语法）
            DBA: DataBase Administrator  数据库管理员
            SQL99(较新的语法)    
          根据表的连接方式来划分
            内连接
              等值连接
              非等值连接
              自连接
            外连接
              左外连接（左连接）
              右外连接（右连接）
            全连接（用的较少） 
        2.3 表的连接查询方面有一种现象被称为（笛卡尔积现象） 也叫（笛卡尔乘积现象）
            案例：找出每个员工的部门名称，要求显示员工名和部门名
            select ename,deptno from emp;
            select ename,dname from emp,dept;
            (如果两张表连接查询而没有任何限制，查询结果条数为两张表中记录条数的乘积)
            关于表的别名
              select e.ename,d.dname from emp e,dept d;
              (执行效率高，可读性强)
        2.4 避免笛卡尔积现象  加条件进行过滤
            （避免了笛卡尔积现象，并不会减少记录的匹配次数）          
            案例：找出每个员工的部门名称，要求显示员工名和部门名
                  select 
                    e.ename,d.dname
                  from
                    emp e,dept d
                  where
                    e.deptno=d.dept  
                  (92语法，以后不用)     
        2.5 内连接之等量连接
            最大特点：条件是等量关系
            案例：查询每个员工的部门名称，要求显示员工名和部门名
            SQL92 (太老了，不常用)
                 select 
                 e.ename,d.dname
                 from 
                 emp e,dept d
                 where 
                 e.deptno=d.deptno; 
            SQL99
                 select 
                   e.ename,d.dname
                 from 
                   emp e
                 inner join
                   dept d
                 on 
                   e.deptno=d.deptno;
                 (on后跟连接条件，后面可以继续加where)
                （inner可以省略，带着inner可读性强）
        2.6 内连接之非等值连接
            案例：找出每个员工的工资等级，要求显示员工名、工资、工资等级。
            select 
               e.ename,e.sal,s.grade
            from 
               emp e
            join
               salgrade s
            on
               e.sal between s.losal and s.hisal; 
        2.7 自连接
          最大特点：一张表看作两张表 自己连接自己
          (inner可以省略)
          案例：找出每个员工的上级领导，要求显示员工和对应领导名
          select 
            a.ename,b.ename
          from
            emp a
          inner join
            emp b
          on 
            a.mgr=b.empno;       
        2.8 外连接
          内连接：假设A与B进行连接，凡是A与B能匹配上的记录查询出来，这就是内连接
                  无主副之分
          外连接：有一张表为主表，一张为副表，主要查询主表，捎带着查询副表
                  副表中的数据无与主表匹配的，自动匹配NULL；  
                  主表中的数据无条件的全部查询出来
                分类：
                    左外连接（左连接）：左边的表为主表
                    右外连接（右连接）：右边的表为主表
                    左连接有右连接的写法
                    右连接有左连接的写法
                    案例：找出每个员工的上级领导？（所有员工都必须查出来）
                    内连接写法：（king不会显示出来）
                    select 
                       a.ename,b.ename
                    from 
                       emp a
                    join 
                       emp b
                    on
                       a.mgr=b.empno; 
                    外连接写法：
                    select 
                       a.ename,b.ename
                    from 
                       emp a
                    left join 
                       emp b
                    on
                       a.mgr=b.empno; 
                    (带left说明左边是主表)
                    select 
                       a.ename,b.ename
                    from 
                       emp b
                    right outer join 
                       emp a
                    on
                       a.mgr=b.empno;
                    (outer可以省略)
                    案例：找出哪个部门没有员工？
                    select 
                      e.*,d.* 
                    from 
                      emp e  
                    right join 
                      dept d 
                    on 
                      e.deptno=d.deptno; 
        2.9 三张表的连接查询？
          案例：找出每个员工的部门名称以及工资等级
          ......
               A
            join
               B
            join
               C
              on
            ....
            表示：A表先和B表连接再和C表连接。         
          dept d
          +--------+------------+----------+
        
        | DEPTNO | DNAME | LOC  |
        | ------ | ----- | ---- |
        |        |       |      |
          +--------+------------+----------+
        | 10   | ACCOUNTING | NEW YORK |
        | ---- | ---------- | -------- |
        |      |            |          |
        | 20   | RESEARCH | DALLAS |
        | ---- | -------- | ------ |
        |      |          |        |
        | 30   | SALES | CHICAGO |
        | ---- | ----- | ------- |
        |      |       |         |
        | 40   | OPERATIONS | BOSTON |
        | ---- | ---------- | ------ |
        |      |            |        |
          +--------+------------+----------+
          salgrade s
          +-------+-------+-------+
        | GRADE | LOSAL | HISAL |
        | ----- | ----- | ----- |
        |       |       |       |
          +-------+-------+-------+
        | 1    | 700  | 1200 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 2    | 1201 | 1400 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 3    | 1401 | 2000 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 4    | 2001 | 3000 |
        | ---- | ---- | ---- |
        |      |      |      |
        | 5    | 3001 | 9999  |
        | ---- | ---- | ----- |
        |      |      | emp e |
        ```
          +-------+--------+-----------+------+------------+---------+---------+--------+
          | EMPNO | ENAME  | JOB       | MGR  | HIREDATE   | SAL     | COMM    | DEPTNO |
          +-------+--------+-----------+------+------------+---------+---------+--------+
          |  7369 | SMITH  | CLERK     | 7902 | 1980-12-17 |  800.00 |    NULL |     20 |
          |  7499 | ALLEN  | SALESMAN  | 7698 | 1981-02-20 | 1600.00 |  300.00 |     30 |
          |  7521 | WARD   | SALESMAN  | 7698 | 1981-02-22 | 1250.00 |  500.00 |     30 |
          |  7566 | JONES  | MANAGER   | 7839 | 1981-04-02 | 2975.00 |    NULL |     20 |
          |  7654 | MARTIN | SALESMAN  | 7698 | 1981-09-28 | 1250.00 | 1400.00 |     30 |
          |  7698 | BLAKE  | MANAGER   | 7839 | 1981-05-01 | 2850.00 |    NULL |     30 |
          |  7782 | CLARK  | MANAGER   | 7839 | 1981-06-09 | 2450.00 |    NULL |     10 |
          |  7788 | SCOTT  | ANALYST   | 7566 | 1987-04-19 | 3000.00 |    NULL |     20 |
          |  7839 | KING   | PRESIDENT | NULL | 1981-11-17 | 5000.00 |    NULL |     10 |
          |  7844 | TURNER | SALESMAN  | 7698 | 1981-09-08 | 1500.00 |    0.00 |     30 |
          |  7876 | ADAMS  | CLERK     | 7788 | 1987-05-23 | 1100.00 |    NULL |     20 |
          |  7900 | JAMES  | CLERK     | 7698 | 1981-12-03 |  950.00 |    NULL |     30 |
          |  7902 | FORD   | ANALYST   | 7566 | 1981-12-03 | 3000.00 |    NULL |     20 |
          |  7934 | MILLER | CLERK     | 7782 | 1982-01-23 | 1300.00 |    NULL |     10 |
          +-------+--------+-----------+------+------------+---------+---------+--------+
        ```
        
        ​        select 
        ​          e.ename,d.dname,s.grade
        ​        from 
        ​          emp e
        ​        join 
    ​          dept d
        ​        on 
        ​          e.deptno=d.deptno
        ​        join
        ​          salgrade s
        ​        on  
        ​          e.sal between s.losal and s.hisal;      
          案例：找出每个员工的部门名称、工资等级以及上级领导。
        ​        select 
        ​          e.ename,d.dname,s.grade,e1.ename
        ​        from 
        ​          emp e
        ​        join 
        ​          dept d
        ​        on 
        ​          e.deptno=d.deptno
        ​        join
        ​          salgrade s
        ​        on  
        ​          e.sal between s.losal and s.hisal
        ​        left join 
        ​          emp e1
        ​        on
        ​        e.mgr=e1.empno;
        ​    3 子查询
        1.什么是子查询？子查询用在哪里？
          select语句中嵌套select语句，被嵌套的select语句是子查询
          select
        ​     ....(select)
          from 
        ​     ....(select)
          where
        ​     ....(select).
        2.where语句中使用子查询
          案例：找出工资高于平均工资的员工信息
          select *from emp where sal>avg(sal);  //错误，where语句中不能直接使用分组函数。
          第一步：找出平均工资
        ​     select avg(sal) from emp;
          第二步：找出高于平均工资的员工
        ​     select *from emp where sal >2073.214286;   
          合并：select *from emp where sal >(select avg(sal) from emp);
        3.from 后面加子查询
          案例：找出每个部门平均薪水的薪资等级。
          第一步：找出每个部门平均工资（按照部门编号分组，求出sal的平均值）
          select deptno,avg(sal) as avgsal from emp group by deptno;
          第二步：将以上的查询结果当作一张新表 将两张表和其他表做连接
          select 
        ​    t.*,s.grade
          from
        ​    (select deptno,avg(sal) as avgsal from emp group by deptno) t
          join 
        ​    salgrade s
          on 
        ​    t.avgsal between s.losal and s.hisal;    
          案例：找出每个部门薪资等级的平均值。
          第一步：找出每个员工的薪水等级。
          第二步：基于以上结果，继续按照deptno分组，求grade的平均值
          select 
        ​    e.ename,e.sal,e.deptno,s.grade
          from  
        ​    emp e
          join
        ​    salgrade s
          on  
        ​    e.sal between s.losal and s.hisal;               
        
        ​        select 
        ​          e.ename,d.dname,s.grade
        ​        from 
        ​          emp e
        ​        join 
        ​          dept d
        ​        on 
        ​          e.deptno=d.deptno
        ​        join
        ​          salgrade s
        ​        on  
        ​          e.sal between s.losal and s.hisal;      
          案例：找出每个员工的部门名称、工资等级以及上级领导。
        ​        select 
        ​          e.ename,d.dname,s.grade,e1.ename
        ​        from 
        ​          emp e
        ​        join 
        ​          dept d
        ​        on 
        ​          e.deptno=d.deptno
        ​        join
        ​          salgrade s
        ​        on  
        ​          e.sal between s.losal and s.hisal
        ​        left join 
        ​          emp e1
        ​        on
        ​        e.mgr=e1.empno;
        ​    3 子查询
        1.什么是子查询？子查询用在哪里？
          select语句中嵌套select语句，被嵌套的select语句是子查询
          select
        ​     ....(select)
          from 
        ​     ....(select)
          where
        ​     ....(select).
        2.where语句中使用子查询
          案例：找出工资高于平均工资的员工信息
          select *from emp where sal>avg(sal);  //错误，where语句中不能直接使用分组函数。
          第一步：找出平均工资
        ​     select avg(sal) from emp;
          第二步：找出高于平均工资的员工
        ​     select *from emp where sal >2073.214286;   
          合并：select *from emp where sal >(select avg(sal) from emp);
        3.from 后面加子查询
          案例：找出每个部门平均薪水的薪资等级。
          第一步：找出每个部门平均工资（按照部门编号分组，求出sal的平均值）
          select deptno,avg(sal) as avgsal from emp group by deptno;
          第二步：将以上的查询结果当作一张新表 将两张表和其他表做连接
          select 
        ​    t.*,s.grade
          from
        ​    (select deptno,avg(sal) as avgsal from emp group by deptno) t
          join 
        ​    salgrade s
          on 
        ​    t.avgsal between s.losal and s.hisal;    
          案例：找出每个部门薪资等级的平均值。
          第一步：找出每个员工的薪水等级。
          第二步：基于以上结果，继续按照deptno分组，求grade的平均值
          select 
        ​    e.ename,e.sal,e.deptno,s.grade
          from  
        ​    emp e
          join
        ​    salgrade s
          on  
        ​    e.sal between s.losal and s.hisal;               
        
          select 
            e.ename,avg(s.grade)
          from  
            emp e
          join
            salgrade s
          on  
            e.sal between s.losal and s.hisal
          group by 
            e.deptno;  
        4.select 后面嵌套子循环
        案例：找出每个员工所在的部门名称，要求显示员工名和部门名
        select 
            e.ename,d.dname
        from
            emp e
        join 
            dept d
        on 
            e.deptno =d.deptno 

        select 
           e.ename,e.deptno,
           (select d.dname from dept d where e.deptno=d.deptno) 
        as
           dname 
        from 
           emp e;                     
    4.union (可以将查询结果集相加)
           案例：找出工作岗位为SALSMAN和MANAGER的员工
           第一种：select ename,job from emp where job='MANAGER' or job='SALESMAN';
           第二种：select ename,job from emp where job in ('MANAGER','SALESMAN');
           第三种：select ename,job from emp where job='MANAGER'
                   union
                   select ename,job from emp where job='SALESMAN';
           案例：两张不相干的表中的数据拼接在一起显示
                 select ename from emp
                 union
                 select dname from dept;
                 特点：两个语句中的列数必须相同     
    5.limit (重点，以后用于分页查询)
           5.1 limit 是MySQL特有的，其他数据库中没有 Oracle中有个相似的
           5.2 limit取结果中的部分数据
           5.3 语法机制:
                  startIndex,length
                  startIndex表示起始位置(从零开始)
                  length表示取几个
           案例：取出工资前五名（思路：降序取前五个）
                select ename,sal from emp order by sal desc limit 0,5;   
                （只写一个数字，第一个默认是0） limit是最后执行的环节
          完整的sql语句
          select   5
             ...
            from   1
             ...
           where   2
             ...
        group by   3
             ...
          having   4
             ...   
        order by   6
             ...
           limit   7
             ...
           案例：找出工资排名在第四到第九名的员工？
                 select ename,sal from emp order by sal desc limit 3,6;
           5.6 通用的标准分页sql？
               每一页显示3条记录：
               第一页：0，3
               第二页：3，3
               第三页：6，3
               每页显示pagesize条记录：
               第pageno页：（pageno-1）*pagesize,pagesize      

6.创建表
  1.create table 表名(
    字段名1 数据类型，
    字段名2 数据类型，
    字段名3 数据类型，
    。。。。
  )
  数据类型
    int         整数型
    bigint      长整型
    float       浮点型
    char        定长字符串
    varchar     可变长字符串 
    date        日期类型
    BLOB        二进制大对象（存储图片，视频等流媒体信息）（无法用insert插入）
    CLOB        字符大对象（存储较大文本，比如，可以存储4G的字符串）
  char和varchar如何选择  
  varchar可以动态分配 定长的用char 不定的用varchar
  表名在数据库中一般建议以t_或者tbl_开头；
  创建学生表
    姓名 varchar
    学号 int
    高数成绩 int
    线代成绩 int
    英语成绩 int
    create table t_student(
      id bigint,
      name varchar(255),
      hima int,
      liner int,
      en int
    );
    create table t_studentgrade(
      id bigint,
      name varchar(255),
      hima int,
      liner int,
      en int,
      sum int
    );  
7.insert 语句
  语法格式：
    insert into 表名（字段名1，字段名2，字段名3，。。。）values（值1，值2，值3）；
    （要求：字段的数量和值的数量相同，并且数据类型要对应）
    insert into t_student(id,name,hima,liner,en) values(202000130061,'koi',89,89,89);    
    若仅插入一个其他的自动补NULL；
    insert语句执行成功后必然会多一行
    drop table if exists t_student;(如果存在这张表就删掉)
    create table t_student(
      id bigint,
      name varchar(255),
      hima int, default(1);(默认值会改成1)
      liner int,
      en int
    );
    insert into t_student values(); (这样写顺序不能变)
    insert into t_student values(54123,'zhangsan',23,58,64),(54122,'lisi',100,100,100),(54823,'wangwu',8,5,4);  (可以一次插入多个)
    create table emp1 as select *from emp; (复制一张表)
8.表的复制
  语法
    create table 表名 as select语句；
    将查询结果当作表创建出来
9.将查询结果插入一张表中    
  insert into dept1 select *from dept;
10.修改数据
   语法格式
     update 表名 set 字段名1=值1，字段名2=值2.....where;
     (没有条件整张表数据全部更新)   6
     案例
         将部门10
         update dept1 set loc="shanghai",dname = "renshibu" where deptno ="10";  
         update t_student set id=51789 where name="koi";
         update t_student set en=61 where name="koi";
11.删除数据
      格式
      delete from 表名 where 条件；
       （没有条件全部删除）   (delete 可以恢复)
      删除表
      drop if exists 表名 //MySQL仅有
      drop 表名；//通用 如果表不存在则报错
      删除大表
      truncate table emp1;  (无法恢复) //表被截断 不可回滚
12.修改表结构（使用工具）  
       navicat
   select insert update 需要写到java中
   （表的结构修改较少，不会出现在java中）
   增删改查有术语：CRUD操作
   create retrive update delete 
13.约束（constraint）
   13.1 什么是约束？常见的约束有哪些
        表格
        id  username（唯一性约束）  password（非空约束）
        在创建表的时候，可以给表添加上相应的约束，添加约束的目的是为了保证表中数据的合法性
        有效性，完整性
        常见约束有哪些？                                                                                                                                    
        非空约束（not null）：约束的字段不能为null
        唯一约束（unique）：约束的字段不能重复
        主键约束（primary key）：约束的字段不能为NULL也不能重复
        外键约束（foreign key）：0000000000000000000000000000000000000000000000000000000000000000000000
        检查约束（check）：oracle中有，MySQL没有
   13.2 非空约束 not null
          仅有列级约束，无表级约束
          drop table if exists t_user;
          create table t_user(
            id int,
            username varchar(255) not null,
            password varchar(255)
          );
          insert into t_user(id,password) values(1,'123');   
day 3
1.约束
  1.1 唯一性约束
      *唯一约束修饰的字段具有唯一性，不能重复，但可以为NULL；
      案例：给某一列添加unique
          drop table if exists t_user;
          create table t_user(
            id int,
            username varchar(255) unique  //列级约束
          );
          insert into t_user values(1,'zhangsan');
          insert into t_user values(2,'zhangsan');
          insert into t_user(id) values(2);     
          insert into t_user(id) values(3);  
          insert into t_user(id) values(4);  
          (唯一性可以为NULL，NULL不是值)
      案例：给多个列添加unique
          drop table if exists t_user;
          create table t_user(
            id int,
            username varchar(255),
            usercode varchar(255),
            unique(usercode,username)  //多个字段联合添加约束【表级约束】
          );
          insert into t_user values(1,'111','zs');
          insert into t_user values(2,'111','ls');
          insert into t_user values(3,'222','zs');

          drop table if exists t_user;
          create table t_user(
            id int,
            username varchar(255) unique,
            usercode varchar(255) unique
          );
  1.2 主键约束
        *怎么给一张表添加主键约束
        drop table if exists t_user;
        create table t_user(
          id int primary key,
          username varchar(255),
          email varchar(255)
        );
        insert into t_user(id,username,email) values(1,'zs','zs.123.com');
        insert into t_user(id,username,email) values(2,'ls','ls.123.com');
        insert into t_user(id,username,email) values(3,'ww','ww.123.com');

        insert into t_user(id,username,email) values(1,'jack','jack.123.com');
        (给某个字段添加主键约束后为主键，主键字段数据不能为NULL也不能重复) 列级约束
        *主键相关的术语
           主键约束：primary key 
           主键字段：id添加primary key后，id叫做主键字段
           主键值：id字段中的每个值叫做主键值
        *主键有什么用?
         表的设计三范式
         第一范式：任何一张表都要有主键
         主键的作用：主键为一行记录的唯一标识，
        *主键的分类
        根据主键字段的字段数量来划分
            单一主键
            复合主键（多个字段联合起来添加一个主键约束） 不建议使用（违背三范式）
            drop table if exists t_user;
            create table t_user(
              id int,
              username varchar(255),
              password varchar(255),
              primary key(id,username)
            );
        根据主键性质来划分
            自然主键：主键值最好是一个与业务没有任何关系的自然数。（推荐）
            业务主键：主键值和系统的业务挂钩，（最好不要使用这种方法。
            因为以后的业务一旦发生改变，主键值也可能会随着发生变化，但很多时候没有办法变化，
            因为变化会导致主键值重复）
        （只能有一个主键）    
        （最好不要拿和业务挂钩的字段做主键，主键值最好是无关的自然数）
        *MySQL提供主键值自增
        drop tables if exists t_user;
        create table t_user(
          id int primary key auto_increment,  //id字段自动维护一个自增的数字，从1开始，以1递增
          username varchar(255)
        );
        insert into t_user(username) values('a');
        insert into t_user(username) values('b');
        insert into t_user(username) values('c');
        insert into t_user(username) values('d');
        insert into t_user(username) values('e');
        insert into t_user(username) values('f');
        insert into t_user(username) values('g');
        select *from t_user;
        提示:Oracle中也有个自增，叫做序列。
  1.3 外键约束
        *关于外键约束的相关术语：
             外键约束：foreign key
             外键字段：添加右外间约束的字段
             外键值：外键字段中的每一个值

        *业务背景：
           请设计数据库表，用于维护学生和班级的信息？
             第一种方案：一张表存储所有数据
             no(pk)       name      classno     classname
             -----------------------------------------------
             1            zs1       101         第一幼儿园一班
             2            zs2       102         第一幼儿园二班
             3            zs3       102         第一幼儿园二班
             4            zs4       102         第一幼儿园二班
             缺点：数据大量冗余
             第二种方案：两张表（班级表和学生表）
             t_class 班级表    
             cno(pk)    classname
             ------------------------------------------------
             101        第一幼儿园一班
             102        第一幼儿园二班
    
             t_student 学生表
             (如果有外键约束，则可以随便写)
             sno(pk)    sname      classno(该字段添加外键约束)
             ------------------------------------------------
             1          zs1       
             2          zs2
             3          zs3 
             4          zs4
        *写建表语句
           t_student中的classno字段引用t_class表中的cno字段
           （t_student表叫做子表,t_class表叫做父表）
           （删表时先删子再删父，添加数据时先加父表再加子表）
           drop table if exists t_student;
           drop table if exists t_class;
           create table t_class(
             cno int,
             cname varchar(255),
             primary key(cno)
           );
           create table t_student(
             sno int,
             sname varchar(255),
             classno int,
             foreign key(classno) references t_class(cno)
           ); 
           insert into t_class values(101,'wx');
           insert into t_class values(102,'wx');    
           insert into t_student values(1,'zs1','101');
           insert into t_student values(2,'zs2','102');
           insert into t_student values(3,'zs3','102');
           insert into t_student values(4,'zs4','102');
           select *from t_student;
           select *from t_class;
        (sql命令可以写在sql脚本中，然后source)
        被引用的不一定是主键但引用的必须是唯一的
  2. 存储引擎（了解内容）
        2.1 完整的建表语句
        +-------+---------------------------------------------------------------------------------------+
        
        | Table | Create Table |
        | ----- | ------------ |
        |       |              |
        +-------+---------------------------------------------------------------------------------------+
        | t_x   | CREATE TABLE `t_x` (
          `id` int(11) DEFAULT NULL
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8 |
        +-------+---------------------------------------------------------------------------------------+
         CREATE TABLE `t_x` (
          `id` int(11) DEFAULT NULL
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8;   
        注意：MySQL中标识符均可以加`号，Oracle中不可用
        建表时可以指定存储引擎，也可以指定字符集。
        默认存储引擎为InnoDB方式
        默认采用的字符集为UTF-8
        2.2 什么是存储引擎
        存储引擎仅在MySQL中存在。Oracle中有对应机制，但不叫做存储引擎。叫存储方式
        MySQL支持很多存储引擎，每种都对应一中不同的存储方式。
每个存储引擎都有各自的优缺点。
      2.3 查看当前MySQL支持的存储引擎
     show engines\G
     *************************** 1. row ***************************
Engine: FEDERATED
     Support: NO
  Comment: Federated MySQL storage engine
Transactions: NULL
          XA: NULL
       Savepoints: NULL
     *************************** 2. row ***************************
 Engine: MRG_MYISAM
     Support: YES
  Comment: Collection of identical MyISAM tables
Transactions: NO
          XA: NO
       Savepoints: NO
     *************************** 3. row ***************************

     ```
        Engine: MyISAM
     Support: YES
          Comment: MyISAM storage engine
     Transactions: NO
               XA: NO
  Savepoints: NO
     ```
  
*************************** 4. row ***************************
      Engine: BLACKHOLE
     Support: YES
     Comment: /dev/null storage engine (anything you write to it disappears)
Transactions: NO
          XA: NO
    Savepoints: NO
*************************** 5. row ***************************
      Engine: CSV
     Support: YES
     Comment: CSV storage engine
Transactions: NO
          XA: NO
    Savepoints: NO
*************************** 6. row ***************************
      Engine: MEMORY
     Support: YES
     Comment: Hash based, stored in memory, useful for temporary tables
Transactions: NO
          XA: NO
    Savepoints: NO
*************************** 7. row ***************************
      Engine: ARCHIVE
     Support: YES
     Comment: Archive storage engine
Transactions: NO
          XA: NO
    Savepoints: NO
*************************** 8. row ***************************
      Engine: InnoDB
     Support: DEFAULT
     Comment: Supports transactions, row-level locking, and foreign keys
Transactions: YES
          XA: YES
    Savepoints: YES
     *************************** 9. row ***************************
      Engine: PERFORMANCE_SCHEMA
     Support: YES
     Comment: Performance Schema
     Transactions: NO
          XA: NO
       Savepoints: NO
        2.4 常见的存储引擎？
             Engine: MyISAM
            Support: YES
            Comment: MyISAM storage engine
       Transactions: NO（代表不支持事务）
                 XA: NO
    Savepoints: NO
             MySQL中最常用的，但不是默认的
             使用三个文件表示一张表
                   表结构.frm
                   表数据.MYD
                   表索引.MYI 
             优点：可以被压缩，节省空间，可以转换为只读表提高效率 
     
     *************************** 4. row ***************************
      Engine: BLACKHOLE
     Support: YES
     Comment: /dev/null storage engine (anything you write to it disappears)
     Transactions: NO
     XA: NO
       Savepoints: NO
     *************************** 5. row ***************************
      Engine: CSV
     Support: YES
     Comment: CSV storage engine
     Transactions: NO
          XA: NO
       Savepoints: NO
     *************************** 6. row ***************************
      Engine: MEMORY
     Support: YES
     Comment: Hash based, stored in memory, useful for temporary tables
     Transactions: NO
          XA: NO
       Savepoints: NO
     *************************** 7. row ***************************
      Engine: ARCHIVE
     Support: YES
     Comment: Archive storage engine
     Transactions: NO
          XA: NO
       Savepoints: NO
     *************************** 8. row ***************************
      Engine: InnoDB
     Support: DEFAULT
     Comment: Supports transactions, row-level locking, and foreign keys
     Transactions: YES
          XA: YES
       Savepoints: YES
     *************************** 9. row ***************************
      Engine: PERFORMANCE_SCHEMA
     Support: YES
     Comment: Performance Schema
     Transactions: NO
          XA: NO
       Savepoints: NO
        2.4 常见的存储引擎？
             Engine: MyISAM
            Support: YES
            Comment: MyISAM storage engine
       Transactions: NO（代表不支持事务）
                 XA: NO
         Savepoints: NO
             MySQL中最常用的，但不是默认的
             使用三个文件表示一张表
                   表结构.frm
                   表数据.MYD
                   表索引.MYI 
             优点：可以被压缩，节省空间，可以转换为只读表提高效率 
     
             Engine: InnoDB
            Support: DEFAULT
            Comment: Supports transactions, row-level locking, and foreign keys
       Transactions: YES
                 XA: YES
         Savepoints: YES            
             优点：支持事务、行级锁、外键等，这种存储引擎最安全
              表的结构存储在xxx.frm文件中
              数据存储在table space这样的空间中（逻辑概念），无法被压缩，无法转换为只读
              在MySQL数据库崩溃后提供自动恢复
              支持级联删除级联更新
              删父表时也删子表
     
             Engine: MEMORY
            Support: YES
            Comment: Hash based, stored in memory, useful for temporary tables
       Transactions: NO
                 XA: NO
         Savepoints: NO
             优点：数据和索引都在内存里，速度快
             缺点：不支持事物。数据容易丢失
             以前叫做HEPA引擎
     
3. 事务（Transaction）
       3.1 什么是事务？
           一个事务是一个完整的逻辑单元，不可再分
           比如：银行账户转账，从a账户转10000给b
           update t_act set balance = balance -10000 where actno ='act-001';
           update t_act set balance = balance +10000 where actno ='act-002';
           以上两条DML语句必须同时成功或者同时失败，不允许一条成功，一条失败。
           要想保证同时成功或者同时失败，就要使用“事物机制”
       3.2 和事务相关的语句只有：DML语句（insert delete update）
           为什么？ 因为只有这三条语句和数据有关
           事务的存在是为了保证数据的完整性，安全性。
       3.3 假设所有的业务都能使用1条DML语句搞定，就不需要事务机制了 
           只有DML文件进缓存       
           通常一件事需要需要多条DML语句
           开启事务机制
           执行insert语句
           （执行成功之后，把这条执行记录到数据库操作历史中，并不会直接修改硬盘上的数据）
           执行delete操作
           （记录到缓存）
           提交和回滚事务将改动记录到内存，清空缓存和历史
       3.4 事务的特性？
             ACID
             A: 原子性 事务是最小的结构单元，不可再分
             C：一致性 多条DML必须同时成功或者失败
             I：隔离性 事务A与事务B之间具有隔离 
             D：持久性 持久性说的是最终数据必须持久化到硬盘文件中，事务才算成功的结束
       3.5 关于事务之间的隔离性
             事务隔离性存在隔离级别，理论上级别包括四个
                 第一级别：读未提交（read uncommitted）
                     对方事务还未提交，我们可以读取对方未提交的数据。
                     读未提交属于脏读（dirty read）现象：表示读到了脏的数据
                 第二级别：读已提交（read commited）
                     对方事务提交之后的数据我方可以读到。
                     解决了脏读现象
                     问题：不可以重复读
                 第三级别：可重复读（repeatable raed）
                     解决了不可重复读问题 
                     问题：读取到的数据为幻想
                 第四级别：序列化读/串行化读
                     解决了所有问题
                     效率低，需要事务排队
           Oracle级别：读已提交
            MySQL级别：可重复读
       3.6 演示事务
              *MySQL事务默认情况下是自动提交的。
              （只要执行任意一条DML语句就提交一次）start transaction;可关闭自动提交
              设置全局事务隔离级别
              （set global transaction isolation level read uncommitted;）
              （set global transaction isolation level serializable;）
              查看隔离级别
              select @@global.tx_isolation;  
   
4. 索引 
      4.1 什么是索引
          索引相当于一本书的目录，通过索引可以快速找到对应的资源。
          不能随便添加索引，因为索引也是数据库中的对象，也需要数据库不断的维护。是有维护成本的。
          比如表中数据经常被修改的不是合添加索引，因为数据一旦被修改，索引需要重新排序，进行维护。
          在数据库方面，查询一张表时有两种检索方式：
          第一种方式：全表扫描
          第二种方式：根据索引检索（效率很高）
          添加索引是给某一个字段，或者某些字段添加索引
          select ename,sal from emp where ename='SMITH';
          没有添加索引时，以上sql语句会进行全表扫描，扫描ename中的所有值。
      4.2 怎样创建索引对象？怎么删除索引对象
          //create index emp_sal_index on emp(sal);
          创建索引对象：
              create index 索引名称 on 表名;
          删除索引对象：
              drop index 索引名称 on 表名;    
      4.3 什么时候考虑给字段添加索引      
          *数据量庞大
          *该字段很少DML操作
          *该字段经常出现在where字句中。（经常根据哪个字段查询）

      4.4 注意：主键和具有unique字段的字段会自动添加索引 
         （explain 查看）    
      4.5 查看sql语句的执行计划
          MySQL> explain select ename,sal from emp where sal =5000;
      4.6 索引底层采用的数据结构是：B + Tree
      4.7 索引的实现原理？ 
          索引会自动排序
          可能会在内存中，按一些东西分区。
          select ename from emp where 物理地址 = 0x3；
      4.8 索引的分类？
          单一索引：给单个字段添加索引
          符合索引：给多个字段联合起来添加一个索引
          主键索引：主键上会自动添加索引
          唯一索引：有unique约束的字段会自动添加索引
      4.9 索引什么时候失效？
          select ename from emp where ename like '%A%';
          模糊查询时，第一个通配符使用的是‘%’，这个时候索引是失效的。
5.视图（view）
      
      5.1 什么是视图
             站在不同的角度看数据。（同一张表的数据，通过不同的角度取看待）
      5.2 怎么创建视图？怎么删除视图？
             create view myview as select empno,ename from emp;
             drop view myview;
      5.3 对视图进行增删改查会影响到原表数据。（通过视图影响原表数据，不是直接操作原表）
             可以对视图进行CRUD操作
      5.4 面向视图操作
             select *from myview;
             create table emp_bak as select *from emp;
             create view myview1 as select empno,ename,sal from emp_bak;        
             update myview1 set ename ='hehe',sal =1 where empno=7369;
             delete from myview1 where emono = 7369;
      5.5 视图的作用
             视图可以隐藏表的细节，保密级别较高的系统，数据库只提供相关的视图，java程序员只对
             视图对象进行CRUD
6.DBA命令                                          
      6.1 数据库的导入导出
            导出
            在Windows的dos命令窗口中执行（别登录）
              mysqldump bjnode>D:\bjnode.sql -uroot -p233
            导入
              create database bjnode;
              use bjnode;
              source D:\bjnode.sql;  
            创建用户
             CREATE USER　username　IDENTIFIED　BY　'password';             
7.数据库设计三范式？
      7.1 什么是设计范式？
          设计表的依据。按照这个三范式设计的表不会出现数据冗余。
      7.2 三范式都是哪些？
          第一范式：任何一张表都有主键，并且每一个字段原子性不可再分

          第二范式：建立在第一范式的基础上，所有非主键字段完全依赖主键，不能产生部分依赖
          多对多？ 三张表 关系表两个外键
          t_student学生表 t_teacher 讲师表 t_teacher_student_relation;
          第三范式：建立在第二范式的基础之上，所有非主键字段直接依赖主键字段，不能产生传递依赖
          一对多？ 两张表 多的表加外键
      注意:在实际开发中，以满足客户的需求为主，有的时候会拿冗余换执行速度    
      7.3 一对一设计？
          t_user_login 用户登录表
          t_user_detail 用户详细信息表
          两种方案 
          1.主键共享 pk+fk
          2.外键唯一 fk+unique