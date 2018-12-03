1.插入数据
1）向STUDENT 表插入下列数据： 
1001,张天,男,10,20
1002,李兰,女,10,21
1003,陈铭,男,10,21
1004,刘茜,女,20,21
1005,马朝阳,男,20,22
insert into dbo.Student VALUES
(1001,'张天','男',10,20),
(1002,'李兰','女',10,21),
(1003,'陈铭','男',10,21),
(1004,'刘茜','女',20,21),
(1005,'马朝阳','男',20,22)

2）向COURSE 表插入下列数据：
1,数据结构,101,4
2,数据库,102,4
3,离散数学,103,4
4,C语言程序设计,101,2
insert into Course VALUES 
(1,'数据结构',101,4),
(2,'数据库',102,4),
(3,'离散数学',103,4),
(4,'C语言程序设计',101,2)
3）向SC 表插入下列数据：
1001,1,80
1001,2,85
1001,3,78
1002,1,78
1002,2,82
1002,3,86
1003,1,92
1003,3,90
1004,1,87
1004,4,90
1005,1,85
1005,4,92
insert into SC VALUES
(1001,1,80),
(1001,2,85),
(1001,3,78),
(1002,1,78),
(1002,2,82),
(1002,3,86),
(1003,1,92),
(1003,3,90),
(1004,1,87),
(1004,4,90),
(1005,1,85),
(1005,4,92)

4）向TEACHER 表插入下列数据： 
101,张星,10
102,李珊,10
103,赵天应,10
104,刘田, 20
INSERT INTO Teacher VALUES
(101,'张星',10),
(102,'李珊',10),
(103,'赵天应',10),
(104,'刘田', 20)

5）向DEPT 表插入下列数据： 
10,计算机科学与技术
20,信息
INSERT INTO Dept VALUES
(10,'计算机科学与技术'),
(20,'信息')

2.修改数据
将张星老师数据结构课的学生成绩全部加2 分
update SC set GRADE = GRADE + 2 where CNO IN (select CNO from Course,Teacher where Course.TNO = Teacher.TNO and Teacher.TNAME = '张星');

3.删除数据
删除马朝阳同学的所有选课记录
DELETE FROM SC WHERE SNO IN (SELECT SNO FROM Student WHERE Student.SNO = SC.SNO and Student.SNAME='马朝阳');

(二)查询操作
1.单表查询
1）查询所有学生的信息。
SELECT * FROM Student
2）查询所有女生的姓名。
SELECT * FROM Student WHERE SEX='女'
3）查询成绩在80 到89 之间的所有学生选课记录，查询结果按成绩的降序排列。
SELECT * FROM SC WHERE GRADE<=89 AND GRADE >=80 ORDER BY GRADE desc
4）查询各个系的学生人数。
SELECT * FROM Student WHERE DEPTNO=10,
SELECT * FROM Student WHERE DEPTNO=20
2.连接查询
查询信息系年龄在21 岁以下（含21 岁）的女生姓名及其年龄。
SELECT SNAME,AGE FROM Student where DEPTNO=20 AND AGE<=21
3.嵌套查询
1）查询修课总学分在10 学分以下的学生姓名。
SELECT SNAME FROM Student 
where SNO IN(
SELECT SNO
FROM SC,Course
WHERE SC.CNO = Course.CNO
GROUP BY SNO having SUM(CREDIT)<=10
)

2）查询各门课程取得最高成绩的学生姓名及其成绩。
SELECT CNO,SNAME,GRADE FROM Student, SC 
WHERE Student.SNO=SC.SNO AND 
GRADE IN 
(SELECT MAX(GRADE) FROM SC,Course 
WHERE SC.CNO = Course.CNO GROUP BY CNAME)

3）查询学习全部课程的学生姓名。
SELECT SNAME FROM Student,SC 
WHERE Student.SNO=SC.SNO GROUP BY SNAME 
HAVING COUNT(CNO) = 
(SELECT COUNT(CNO) FROM Course)

4）查询学习课程号为“1”或“2”的学生学号。
SELECT SNO FROM SC WHERE CNO=1 UNION SELECT SNO FROM SC WHERE CNO=2

5）查询至少学习课程号为“1”和“2”的学生学号。

SELECT SNO FROM SC WHERE CNO=1 AND SNO IN (SELECT SNO FROM SC WHERE CNO = 2)
6）查询不学“2”号课程的学生姓名与年龄
SELECT SNAME,AGE FROM Student  
WHERE SNAME IN  
(SELECT SNAME FROM Student,SC  
WHERE Student.SNO=SC.SNO 
AND Student.SNO NOT IN (SELECT SNO FROM SC WHERE CNO = 2))