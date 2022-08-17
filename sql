create database studentaccom;
use studentaccom;
create table student(
sid int,fname varchar(20),lname varchar(20),street varchar(20),city varchar(20),postcode int,comments varchar(20),
gender varchar(20),dob date,school varchar(20),needs varchar(20),email varchar(20),nationality varchar(20),slevel varchar(20),sstatus varchar(20),primary key(sid));
create table mobile(
sid int,mobile1 int,foreign key(sid)references student(sid));
create table hall(
sid int,hname varchar(20),addressh varchar(20),telephone int,managername varchar(20),primary key(hname),foreign key(sid)references student(sid));
create table rooms(
placeno int,roomno int,hname varchar(20),sid int,rrent int,primary key(placeno),foreign key(sid)references student(sid),foreign key(hname)references hall(hname));
create table apartment(
flatno int,nod int,primary key(flatno));
create table dormitory(
did int,dbedno int,flatno int,daddress varchar(20),primary key(did),foreign key(flatno)references apartment(flatno));
create table bed(
bedno int,did int,brent int,sid int,foreign key(sid)references student(sid),primary key(bedno),foreign key(did)references dormitory(did));
create table invoice(
invoiceno int,term int,due int,fname varchar(20),lname varchar(20),placeno int,roomno int,address varchar(20),pdate date,method varchar(20),
ifirst date,ilast date, primary key(invoiceno), foreign key(placeno)references rooms(placeno),constraint sid foreign key(invoiceno)references student(sid));
create table inspection(
inspectorname varchar(20),isdate date,satisfaction varchar(20),iscomments varchar(20),hname varchar(20),did int,
foreign key(hname)references hall(hname),foreign key(did)references dormitory(did));

insert into student values(1001,"john","jacobs","boston","nyc",560050,null,"male","2002-05-05","nyc public",null,"jacob@gamil","usa","UG","placed");
insert into mobile values(1001,636345678);
insert into hall values(1001,"hall1","deakin",70131504,"kumar");
insert into rooms values(100,1,"hall1",1001,1500);
insert into apartment values(1,10);
insert into dormitory values(111,2,1,"deakin");
insert into bed values(010,111,500,1001);
insert into invoice values(1001,3,2000,"john","jacobs",100,1,"deakin","2022-09-09","debit","2022-07-09","2022-08-09");
insert into inspection values("steve","2022-08-15","satisfied",'well maintained',"hall1",null);

insert into student values(1002,"suraj","kumar","basavanagudi","bglr",560050,null,"male","2002-05-12","chaitanya",null,"kumar@gamil","indian","UG","waiting");
insert into mobile values(1002,636345678);
insert into hall values(1002,"hall2","boston",54546545,"kumar");
insert into rooms values(200,2,"hall2",1002,1600);
insert into apartment values(2,10);
insert into dormitory values(112,3,2,"jaynagar");
insert into bed values(020,112,700,1002);
insert into invoice values(1002,2,1000,"suraj","kumar",200,2,"mysore","2022-10-09","cash","2022-09-09","2022-10-09");
insert into inspection values("lokesh","2022-11-15","unsatisfied",'creative',null,112);

insert into student values(1003,"udaya","raj","basavanagudi","bglr",560050,null,"male","2002-05-12","chaitanya",null,"kumar@gamil","indian","UG","placed");
insert into mobile values(1003,636345678);
insert into hall values(1003,"hall3","jaynagar",36351432,"kumar");
insert into rooms values(300,3,"hall3",1003,1600);
insert into apartment values(3,10);
insert into dormitory values(113,3,3,"jaynagar");
insert into bed values(030,112,700,1003);
insert into invoice values(1003,3,1000,"suraj","kumar",200,2,"jaynagar","2022-10-09","cash","2022-09-09","2022-10-09");
insert into inspection values("lokesh","2022-11-15","unsatisfied",null,null,113);

select * from hall;
select * from student;
select * from apartment;
select * from bed;
select * from invoice;
select * from inspection;
truncate table inspection;

select managername,telephone from hall;
create view manager(name,telephone) as (select managername,telephone from hall);
select * from manager;

alter table invoice 
drop foreign key sid;
alter table invoice
add constraint sid foreign key(invoiceno) references student(sid) on delete cascade;
desc invoice;

select * from inspection where satisfaction = 'unsatisfied';
select * from dormitory where did in (select did from inspection where satisfaction = 'unsatisfied');

select (select rrent from rooms where sid = '1002')+(select brent from bed where sid = '1002') as rent_fee;

update inspection set iscomments = 'not good' where inspectorname = 'steve';

delete from invoice where invoiceno = (select sid from student where fname = 'john');
