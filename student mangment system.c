#include <stdio.h>
#include <stdlib.h>
int n = 0;
typedef struct grade
{
	char name[10];
	int id;
	float math;
	float chinese;
	float sum;
	float ave;
	struct grade *next;
} t_s;
t_s *Load(void) //载入文件中的数据到结构体中
{
	FILE *fp;
	t_s *head, *p, *q;
	head = NULL;
	fp = fopen("e:\\student.txt", "r"); //以"r"形式打开student的文件
	if (fp == NULL)						//如果文件不存在
	{
		fp = fopen("e:\\student.txt", "w"); //创立一个student文件
		fclose(fp);							//关闭文件
		return head;						//返回链表中，存入head
	}
	p = (t_s *)malloc(sizeof(t_s));		   //如果存在
	if (fread(p, sizeof(t_s), 1, fp) != 1) //判断文件中的数据 是否只有1个
		return head;					   //是就返回
	head = p;
	printf("%f %f %s %d\n", p->math, p->chinese, p->name, p->id);
	while (!feof(fp)) //否则就开始从文件中读数据
	{
		q->next = p;
		q = p;
		p = (t_s *)malloc(sizeof(t_s));
		fread(p, sizeof(t_s), 1, fp);
		printf("%f %f %s %d\n", p->math, p->chinese, p->name, p->id);
	}
	q->next = NULL;
	free(p); //释放指针p所指向的内存空间
	fclose(fp);
	return head; //返回链表中，存入head
}
t_s *creat()
{
	t_s *head = NULL;
	FILE *fp;
	fp = fopen("e:\\student.txt", "at");
	t_s *pa = NULL, *pb = NULL;
	int retu_scanf;
	pa = pb = (t_s *)malloc(sizeof(t_s));
	retu_scanf = scanf("%f%f%s%d", &pa->math, &pa->chinese, pa->name, &pa->id);
	if (retu_scanf != 0)
		fwrite(pa, sizeof(t_s), 1, fp);
	while (retu_scanf)
	{

		if (head == NULL)
			head = pa;
		else
			pb->next = pa;
		pb = pa;
		pa = (t_s *)malloc(sizeof(t_s));
		retu_scanf = scanf("%f%f%s%d", &pa->math, &pa->chinese, pa->name, &pa->id);
		if (retu_scanf != 0)
			fwrite(pa, sizeof(t_s), 1, fp);
	}
	pb->next = NULL;
	fclose(fp);
	return head;
}
void print(t_s *head)
{
	while (head)
	{
		printf("%f %f %s %d\n", head->math, head->chinese, head->name, head->id);
		head = head->next;
	}
}
void delect(t_s *head)
{
	int id;
	t_s *before = NULL, *last = NULL;
	last = head;
	scanf("%d", &id);
	while (last)
	{

		if (last->id == id)
			if (last == head)
			{
				head = head->next;
				break;
			}
			else
			{
				before->next = last->next;
				break;
			}
		before = last;
		last = last->next;
	}
}
t_s *sort(t_s *head)
{
	t_s *pfirst;
	t_s *ptail;
	t_s *pminbefore;
	t_s *pmin;
	t_s *p;
	pfirst = NULL;
	while (head != NULL)
	{
		for (p = head, pmin = head; p->next; p = p->next)
		{
			if (p->next->id < pmin->id)
			{
				pminbefore = p;
				pmin = p->next;
			}
		}
		if (pfirst == NULL)
		{
			pfirst = pmin;
			ptail = pmin;
		}
		else
		{
			ptail->next = pmin;
			ptail = pmin;
		}
		if (pmin == head)
		{
			head = head->next;
		}
		else
		{
			pminbefore->next = pmin->next;
		}
	}
}
void search(t_s *head)
{
	int id;
	scanf("%d", &id);
	while (head)
	{
		if (head->id == id)
		{
			printf("%f %f %s %d", head->math, head->chinese, head->name, head->id);
			break;
		}
		head = head->next;
	}
	if (head == NULL)
		printf("不存在此记录");
}
int main()
{
	t_s *head = NULL;
	int num;
	printf("                            #学生成绩管理系统#\n");
	printf("系统说明：\n");
	printf("1.按1输入学生成绩\n");
	printf("2.按2增加学生成绩\n");
	printf("3.按3学生成绩排序\n");
	printf("4.按4删除学生成绩\n");
	printf("5.按5显示学生成绩\n");
	printf("6.按6显示学生成绩\n");
	printf("7.按7安全退出系统\n");
	while (1)
	{
		scanf("%d", &num);
		head = Load();
		switch (num)
		{
		case 1:
			creat();
			break;
			head = Load();
		case 2:
			creat();
			break;
			head = Load();
		case 3:
			search(head);
			break;
		case 4:
			delect(head);
			break;
		case 5:
			print(head);
			break;
		case 6:
			sort(head);
			break;
		case 7:
			printf("bye");
			return 0;
		}
		scanf("%d", &num);
	}
	return 0;
}