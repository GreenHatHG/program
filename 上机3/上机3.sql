1.��������
1����STUDENT ������������ݣ� 
1001,����,��,10,20
1002,����,Ů,10,21
1003,����,��,10,21
1004,����,Ů,20,21
1005,����,��,20,22
insert into dbo.Student VALUES
(1001,'����','��',10,20),
(1002,'����','Ů',10,21),
(1003,'����','��',10,21),
(1004,'����','Ů',20,21),
(1005,'����','��',20,22)

2����COURSE ������������ݣ�
1,���ݽṹ,101,4
2,���ݿ�,102,4
3,��ɢ��ѧ,103,4
4,C���Գ������,101,2
insert into Course VALUES 
(1,'���ݽṹ',101,4),
(2,'���ݿ�',102,4),
(3,'��ɢ��ѧ',103,4),
(4,'C���Գ������',101,2)
3����SC ������������ݣ�
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

4����TEACHER ������������ݣ� 
101,����,10
102,��ɺ,10
103,����Ӧ,10
104,����, 20
INSERT INTO Teacher VALUES
(101,'����',10),
(102,'��ɺ',10),
(103,'����Ӧ',10),
(104,'����', 20)

5����DEPT ������������ݣ� 
10,�������ѧ�뼼��
20,��Ϣ
INSERT INTO Dept VALUES
(10,'�������ѧ�뼼��'),
(20,'��Ϣ')

2.�޸�����
��������ʦ���ݽṹ�ε�ѧ���ɼ�ȫ����2 ��
update SC set GRADE = GRADE + 2 where CNO IN (select CNO from Course,Teacher where Course.TNO = Teacher.TNO and Teacher.TNAME = '����');

3.ɾ������
ɾ������ͬѧ������ѡ�μ�¼
DELETE FROM SC WHERE SNO IN (SELECT SNO FROM Student WHERE Student.SNO = SC.SNO and Student.SNAME='����');

(��)��ѯ����
1.�����ѯ
1����ѯ����ѧ������Ϣ��
SELECT * FROM Student
2����ѯ����Ů����������
SELECT * FROM Student WHERE SEX='Ů'
3����ѯ�ɼ���80 ��89 ֮�������ѧ��ѡ�μ�¼����ѯ������ɼ��Ľ������С�
SELECT * FROM SC WHERE GRADE<=89 AND GRADE >=80 ORDER BY GRADE desc
4����ѯ����ϵ��ѧ��������
SELECT * FROM Student WHERE DEPTNO=10,
SELECT * FROM Student WHERE DEPTNO=20
2.���Ӳ�ѯ
��ѯ��Ϣϵ������21 �����£���21 �꣩��Ů�������������䡣
SELECT SNAME,AGE FROM Student where DEPTNO=20 AND AGE<=21
3.Ƕ�ײ�ѯ
1����ѯ�޿���ѧ����10 ѧ�����µ�ѧ��������
SELECT SNAME FROM Student 
where SNO IN(
SELECT SNO
FROM SC,Course
WHERE SC.CNO = Course.CNO
GROUP BY SNO having SUM(CREDIT)<=10
)

2����ѯ���ſγ�ȡ����߳ɼ���ѧ����������ɼ���
SELECT CNO,SNAME,GRADE FROM Student, SC 
WHERE Student.SNO=SC.SNO AND 
GRADE IN 
(SELECT MAX(GRADE) FROM SC,Course 
WHERE SC.CNO = Course.CNO GROUP BY CNAME)

3����ѯѧϰȫ���γ̵�ѧ��������
SELECT SNAME FROM Student,SC 
WHERE Student.SNO=SC.SNO GROUP BY SNAME 
HAVING COUNT(CNO) = 
(SELECT COUNT(CNO) FROM Course)

4����ѯѧϰ�γ̺�Ϊ��1����2����ѧ��ѧ�š�
SELECT SNO FROM SC WHERE CNO=1 UNION SELECT SNO FROM SC WHERE CNO=2

5����ѯ����ѧϰ�γ̺�Ϊ��1���͡�2����ѧ��ѧ�š�

SELECT SNO FROM SC WHERE CNO=1 AND SNO IN (SELECT SNO FROM SC WHERE CNO = 2)
6����ѯ��ѧ��2���ſγ̵�ѧ������������
SELECT SNAME,AGE FROM Student  
WHERE SNAME IN  
(SELECT SNAME FROM Student,SC  
WHERE Student.SNO=SC.SNO 
AND Student.SNO NOT IN (SELECT SNO FROM SC WHERE CNO = 2))