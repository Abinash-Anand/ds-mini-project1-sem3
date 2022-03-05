#include <stdio.h>
#include <stdlib.h>
struct record
{
  int sn;
  char name[20];
  long signed int prn;
  char fname[20];
  float amount;
  char mode[20];
  char date[27];
};
int a, w, roll, id, i;
FILE *fp;
FILE *ptr;
char ch, array[2556];
struct record r;
// Function to Add Payment Details
void Add_Payment()
{
  fp = fopen("iam.txt", "a");
  printf("Enter Roll No.\n");
  scanf("%d", &r.sn);
  fflush(stdin);
  printf("Enter Your Name\n");
  gets(r.name);
  printf("Enter Your P.R.N.\n");
  scanf("%ld", &r.prn);
  fflush(stdin);
  printf("Enter Fee Name\n");
  gets(r.fname);
  printf("Enter Amount\n");
  scanf("%f", &r.amount);
  fflush(stdin);
  printf("Enter Payment Mode\n");
  gets(r.mode);
  printf("Enter Date\n");
  gets(r.date);
  fprintf(fp, "%d      %ld     %s    %s   %s     %f      %s \n", r.sn, r.prn, r.name, r.fname, r.mode, r.amount, r.date);
  fclose(fp);
}
// Function to Search Data
void search()
{
  printf("Search by Roll Number\n");

  scanf("%d", &roll);
  ptr = fopen("iam.txt", "r");

  for (i = 0; i <= 2000; i++)
  {
    fscanf(ptr, "%s", array);
    id = atoi(array); // atoi function converts a string to an integer

    if (id == roll)
    {
      fgets(array, 255, (FILE *)ptr);
      printf("%s", array);
    }
  }

  fclose(ptr);
}
// Function to See Student Details
void Student_Details()
{
  fp = fopen("iam.txt", "r");
  if (fp == NULL)
  {
    printf("File not found\n");
    exit(1);
  }
  ch = fgetc(fp);
  while (!feof(fp))
  {
    printf("%c", ch);
    ch = fgetc(fp);
  }

  fclose(fp);
}
// Function to see Reciept
void Receipt()
{
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\t\t\t\t\t\t\t\t\tBharati Vidyapeeth College of Engineering\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\tDhankawari, Pune\n");
  printf("\t\t\t\t\t____________________________________________________________________________________________________________________________\n\n");
  printf("\t\t\t\t\tReciept No: %d                                                                ", r.sn);
  printf("\t\t\t\t\tDate: ");
  puts(r.date);
  printf("\n");
  printf("\t\t\t\t\tPayment Mode:");
  puts(r.mode);
  printf("      \t\t\t      \t\t\t\t         \t\t\t\t\t             ");
  printf("                        GSTIN : 27AAATLO355\n");
  printf("\t\t\t\t\tBank Name: SBI                                                              \n");
  printf("\t\t\t\t\tRecieved From: ");
  puts(r.name);
  printf("\n");
  printf("\t\t\t\t\tThe Following payment in the office of the Semister 1-2\n");
  printf("\t\t\t\t\t______________________________________________________________________________________________________________\n");
  printf("\t\t\t\t\tSr.no                   ");
  printf("Heads");
  printf("          \t\t\t\t  ");
  printf("         Amount(Rs)         \n");
  printf("\t\t\t\t\t______________________________________________________________________________________________________________\n");
  printf("\t\t\t\t\t%d                  ", r.sn);
  puts(r.fname);
  printf(" \t\t\t\\t\t\t        \t\t\t\t   ");
  printf("    \t\t\t\t    %f", r.amount);
  printf("            \n");
  printf("\t\t\t\t\t              \t\t");
  printf("CGST             \t\t\t  ");
  printf("          %f", r.amount * 0.09);
  printf("          \n");
  printf("\t\t\t\t\t \t\t      ");
  printf("\tSGST    \t\t\t    ");
  printf("\t\t    %f", (r.amount * 0.09));
  printf("          \n");
  printf("\t\t\t\t\t      \t\t\t\t\t                          ");
  printf("________________________________________\n");
  printf("\t\t\t\t\t                \n");
  printf("\t\t\t\t\t                                                                        ");
  printf("    %f\n", r.amount + 2 * ((r.amount * 9) / 100));
  printf("\n\n");
  printf("\t\t\t\t\t                                                                   ____________________________________\n");
  printf("\t\t\t\t\tRemark:                                                                        Reciver Signature\n");
}

int main()
{
  long signed int id, roll;
  int flag = 0, count = 0;
  FILE *ptr;
  printf("Enter Your Password: ");

  scanf("%ld", &roll);
  ptr = fopen("sa.txt", "r");

  for (i = 0; i <= 2000; i++)
  {
    fscanf(ptr, "%s", array);
    id = atoi(array); // atoi function converts a string to an integer

    if (id == roll)
    {
      fgets(array, 255, (FILE *)ptr);
      printf("        Welcome\n %s\n", array);

      do
      {
        printf("Press 1 for Add Payment Details\n");
        printf("Press 2 for Search By Roll No.\n");
        printf("Press 3 for See Student Details\n");
        scanf("%d", &a);
        int r;
        switch (a)
        {
        case 1:
          Add_Payment();
          printf("Press 1 for Reciept\nPress 2 for exit\n");
          scanf("%d", &r);
          switch (r)
          {
          case 1:
            Receipt();
            break;
          case 2:
            exit(1);
            break;
          default:
            printf("Invalid Input!\n");
          }
          break;
        case 2:
          search();
          break;
        case 3:
          Student_Details();
          break;
        default:
          printf("Invalid Input!!\n");
        }
        printf("\nMore! Press 7\n");
        scanf("%d", &w);
      } while (w == 7);
    }
    else
    {
      flag = 1;
      count++;
    }
  }

  fclose(ptr);
  if (flag == 1 && count > 2000)
  {
    printf("Incorrect Password!!!!!\n");
  }
  return 0;
}
