#include<stdio.h>
#include<string.h>
struct stu
{
	char name[40];
	int stu_num;
	int dor_num;
};
struct stu st[1000];
int i = 0;
void menu()
{
	printf("\t\t\t\t\t\t主菜单\n");
	printf("\t\t\t\t\t   1.添加学生住宿信息\n");
	printf("\t\t\t\t\t   2.删除学生住宿信息\n");
	printf("\t\t\t\t\t   3.显示学生住宿信息\n");
	printf("\t\t\t\t\t   4.查询学生住宿信息\n");
	printf("\t\t\t\t\t   5.排列学生住宿信息\n");
	printf("\t\t\t\t\t   6.退出系统\n");
	printf("请输入你所需功能的序号:");
}
void read()
{
	FILE *fp;
	fopen_s(&fp, "dor_manage.txt", "r");
	if (fp == NULL)
	{
		printf("Failure to open dor_manage.txt!\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf_s(fp, "%s", st[i].name,10);
			fscanf_s(fp, "%d", &st[i].stu_num);
			fscanf_s(fp, "%d", &st[i].dor_num);
		}
		i--;
	}
	fclose(fp);
}

void write(stu st[])
{
	FILE *fp;
	fopen_s(&fp,"dor_manage.txt", "w");
	if (fp == NULL)
	{
		printf("Failure to open dor_manage.txt!\n");
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			fprintf(fp, "%10s%15d%8d\n", st[j].name, st[j].stu_num, st[j].dor_num);
		}
		fclose(fp);
	}
}
void add()
{
	
	printf("请输入学生的姓名:");
	scanf_s("%s", st[i].name, 40);
	printf("请输入学生的学号:");
	scanf_s("%d", &st[i].stu_num);
	printf("请输入学生的宿舍号:");
	scanf_s("%d", &st[i].dor_num);
	i++;
	write(st);
	
	char b_or_c;
	getchar();
	printf("按'c'继续该功能   按其他键退出该功能回到主菜单\n");
	b_or_c = getchar();
	if (b_or_c == 'c')
	{
		add();
	}
}

void show()
{
	for (int j = 0; j < i; j++)
	{
		printf("%-10s  %-10d  %-8d\n", st[j].name, st[j].stu_num, st[j].dor_num);
	}
}

void shan()
{
	printf("请输入要删除学生的姓名\n");
	char shan_name[40];
	scanf_s("%s", shan_name, 40);
	int shan_flag;
	for (int k = 0; k < i; k++)
	{
		if (strcmp(shan_name, st[k].name) == 0)
		{
			shan_flag = k;
			i--;
			break;
		}
	}
	for (int j = shan_flag; j < i; j++)
	{
		st[j] = st[j + 1];
	}
	printf("删除成功\n");
	char b_or_c;
	getchar();
	printf("按'c'查看删除后的信息   按其他键退出该功能回到主菜单\n");
	b_or_c = getchar();
	if (b_or_c == 'c')
	{
		show();
	}
}

void xing_pai()
{
	int b;
	struct stu temp;
	for (int j = 0; j < i; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			b = strcmp(st[k].name, st[j].name);
			if (b<0)
			{
				temp = st[k];
				st[k] = st[j];
				st[j] = temp;
			}
		}
	}
}
void stu_num_pai()
{
	struct stu temp;
	for (int j = 0; j < i; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (st[k].stu_num < st[j].stu_num)
			{
				temp = st[k];
				st[k] = st[j];
				st[j] = temp;
			}
		}
	}
}
void dor_num_pai()
{
	struct stu temp;
	for (int j = 0; j < i; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (st[k].dor_num < st[j].dor_num)
			{
				temp = st[k];
				st[k] = st[j];
				st[j] = temp;
			}
		}
	}
}
void pai()
{
	printf("请选择相应的排序方式\n1.按姓名排序      2.按学号排序  3.按宿舍号排序\n");
	int a;
	scanf_s("%d", &a);
	if (a == 1)
	{
		xing_pai();
		write(st);
		printf("排完后的顺序为:\n");
		show();
	}
	if (a == 2)
	{
		stu_num_pai();
		write(st);
		printf("排完后的顺序为:\n");
		show();
	}

	if (a == 3)
	{
		dor_num_pai();
		write(st);
		printf("排完后的顺序为:\n");
		show();
	}
}


void check()
{
	printf("请选择相应的查询方式\n1.按姓名查找      2.按学号查找  3.按宿舍号查找\n");
	int a;
	scanf_s("%d", &a);
	if (a == 1)
	{
		xing_pai();
		char temp[40];
		printf("请输入学生的姓名:");
		scanf_s("%s",temp, 40);
		int low = 0, high = i,mid;
		while (true)
		{
			mid = (low + high) / 2;
			int b = strcmp(temp, st[mid].name);
			if (b<0)
			{
				high = mid - 1;
			}
			if (b == 0)
			{
				printf("%s    %d    %d\n", st[mid].name, st[mid].stu_num, st[mid].dor_num);
				break;
			}
			if (b > 0)
			{
				low = mid + 1;
			}
		}
	}
	if (a == 2)
	{
		stu_num_pai();
		int temp;
		printf("请输入学生的学号:");
		scanf_s("%d", &temp);
		int low = 0, high = i, mid;
		while (true)
		{
			mid = (low + high) / 2;
			if (temp<st[mid].stu_num)
			{
				high = mid - 1;
			}
			if (temp==st[mid].stu_num)
			{
				printf("%s    %d    %d\n", st[mid].name, st[mid].stu_num, st[mid].dor_num);
				break;
			}
			if (temp>st[mid].stu_num)
			{
				low = mid + 1;
			}
		}
	}
	if (a == 3)
	{
		dor_num_pai();
		int temp;
		printf("请输入学生的宿舍号:");
		scanf_s("%d", &temp);
		int low = 0, high = i-1, mid;
		
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (temp<st[mid].dor_num)
			{
				high = mid-1;
			}
			else if (temp == st[mid].dor_num)
			{
				printf("%s    %d    %d\n", st[mid].name, st[mid].stu_num, st[mid].dor_num);
				break;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
}


int  n;
int main()
{
	while (true)
	{
		menu();
		read();
		scanf_s("%d", &n);
		if (n == 1)
		{
			add();
		}
		else if (n == 2)
		{
			shan();
		}
		else if (n == 3)
		{
			show();
		}
		else if (n == 4)
		{
			check();
		}
		else if (n == 5)
		{
			pai();
		}
		else if (n == 6)
		{
			break;
		}
	
	}
}