CREATE DATABASE dbms;
CREATE TABLE departments(
	id int PRIMARY KEY auto_increment,
	name VARCHAR(50)NOT NULL,
	location VARCHAR(100)NOT null,
	hod VARCHAR(50)NOT null,
	contact VARCHAR(15)NOT NULL
);
INSERT INTO departments(id,name,location,hod,contact)VALUES
(null,'CSE','4th floor','RHF','09876543213'),
(null,'Math','2nd floor','SH','09876543234'),
(null,'CSE','4th floor','RHF','09876543216'),
(null,'CSE','4th floor','RHF','09876543876'),
(null,'Math','2nd floor','SH','09876543987');
CREATE TABLE students(
	id int PRIMARY KEY auto_increment,
	name VARCHAR(50)NOT null,
	roll int NOT NULL,
	phone VARCHAR(15)NOT null,
	city VARCHAR(100)NOT null,
	dob DATE NOT null,
	dept_id int,
	FOREIGN KEY(dept_id)REFERENCES departments(id)
);
INSERT INTO students(id,name,roll,phone,city,dob,dept_id)VALUES
(null,'Antor',101,'014763033','khulna','2004-02-20',1),
(null,'Mohon',102,'014763034','Barishal','2004-07-15',2),
(null,'Milon',103,'014763088','Dhaka','2004-02-23',1),
(null,'Sabuj',104,'014763090','khulna','2004-08-11',2),
(null,'Sagor',105,'014763012','Barishal','2004-11-18',1);
CREATE TABLE teachers(
	id int PRIMARY KEY auto_increment,
	name VARCHAR(50)NOT null,
	designation VARCHAR(50)NOT null,
	salary DECIMAL(7,2)NOT null,
	city VARCHAR(10)NOT null,
	joining_date DATE NOT null,
	dept_id int,
	FOREIGN KEY(dept_id)REFERENCES departments(id)
);
INSERT INTO teachers(id,name,designation,salary,city,joining_date,dept_id)VALUES
(null,'Alice','Lecturer',60000.00,'khulna','2018-12-30',2),
(null,'Bob','Assistant Professor',40000.00,'Barishal','2019-03-11',1),
(null,'Malice','Associate Professor',45000.00,'Barishal','2016-12-23',3),
(null,'Hary','Professor',66000.00,'Sylhet','2017-10-12',2),
(null,'Finch','Associate Professor',71000.00,'Dhaka','2018-07-30',2);
