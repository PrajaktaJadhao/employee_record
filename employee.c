#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define success 1
#define failure 0
#define num_of_employees 15
#define x 15
#define y 15
#define z 35

struct employee_record
{
    char name[150];
    char project_name[100];
    int phone;
    char address[150];
    int no_of_hrs;
    int sal;
};
struct employee_record employee_db[num_of_employees],list_1[x],list_2[y],list_3[z];


int initialize_db(struct employee_record[],int);
int insert(struct employee_record[],int,char[],char[],int,int,char[],int);
int sort(struct employee_record[],int);
int delete1(struct employee_record[],int,char[],char[]);
int getNumRecords(struct employee_record[],int);
int isEmpty(struct employee_record[],int);
int isFull(struct employee_record[],int);
int list_removedup(struct employee_record[],int);
int list_union(struct employee_record[],struct employee_record[],int,int);
int list_intersection(struct employee_record[],struct employee_record[],int,int);
int list_difference(struct employee_record[],struct employee_record[],int,int);
int getMaxNumHrs(struct employee_record[],int,char[]);
void KthTopMostProject(struct employee_record[],int,int);
int leastpopproject(struct employee_record[],int ,int ,int );
void exit();
char pronames[6][30]={"Construction","Infrast","Design","Development","Bridge","Research"};
int main()
{
    int i=0,ch,k,count=0;
    int a,b,l,m;char name2[50];
    int n1,n2,T=1;
    char name1[50],project_name1[20],address1[150];
    int phone1,no_of_hrs1,ans,sal1;
        
    initialize_db(employee_db,n1);
    FILE *fp2;
    FILE *fp1;
    fp1=fopen("empl1.txt","r");
    
    
    while(!feof(fp1))
    { 
       fscanf(fp1,"%s",&employee_db[i].name);
       fscanf(fp1,"%s",&employee_db[i].project_name);
       fscanf(fp1,"%d",&employee_db[i].phone);
       fscanf(fp1,"%s",&employee_db[i].address);
       fscanf(fp1,"%d",&employee_db[i].no_of_hrs);
	   fscanf(fp1,"%d",&employee_db[i].sal);i++;
    
    }
    n1=i;
    fclose(fp1);
     for(i=0;i<n1;i++)
    {
    	printf("%s ",employee_db[i].name);
       printf("%s ",employee_db[i].project_name);
       printf("%d ",employee_db[i].phone);
       printf("%s ",employee_db[i].address);
       printf("%d ",employee_db[i].no_of_hrs);
	   printf("%d \n",employee_db[i].sal);
	}

    while(T)
    {
       printf("\n********************MENU******************");
       printf("\n              EMPLOYEE DATABASE           ");
       printf("\n1:INSERT\n2:DELETE\n3:GET_NUM_RECORDS\n4:isEMPTY\n5:isFULL\n6:getTopmostemployee\n7:kthTOPMOST_PROJECT\n8:LIST_UNION\n9:LIST_INTERSECTION\n10:LIST_DIFFERENCE\n11:LEAST_POPPROJECT\n12:GETMAXNUMHRS");
       printf("\n Enter your choice:");
       scanf("%d",&ch);
       switch(ch)
      {
          case 1:
                  printf("\nEnter the record to be inserted or updated:");
                  printf("\nEnter the Name of the employee,\nproject_name,\nphone,\nno_of_hrs,\naddress,\nsalary");
	              scanf("%s %s %d %d %s %d",&name1,&project_name1,&phone1,&no_of_hrs1,&address1,&sal1);
	              while(phone1 != 0)
                     {
                            phone1 /= 10;
                             ++count;
                      }
                  if(count==10)
	              {
				  insert(employee_db,n1,name1,project_name1,no_of_hrs1,phone1,address1,sal1);
	              printf("\nUpdated array after insertion");
     	          sort(employee_db,n1);}
     	          else{
     	          	printf("record insertion failed\n");
     	          	 printf("\n Enter 1 to continue to MENU:\n");
	              scanf("%d",&T);
				   }
     	         
                  break;
	      
          case 2:
                  printf("enter the employeename and project_name to be deleted");
	              scanf("\n%s\n%s",&name1,&project_name1);
	              delete1(employee_db,n1,name1,project_name1);
                  printf("\nUpdated array after deletion");
                   for(i=0;i<n1;i++)
   {
     printf("\n%s\t%s\t%d\t%d\t%s",employee_db[i].name,employee_db[i].project_name,employee_db[i].phone,employee_db[i].no_of_hrs,employee_db[i].address);
   }
  
	              
	              printf("\n Enter 1 to continue to MENU:\n");
	              scanf("%d",&T);
	              break;
	   
          case 3:
                  ans=getNumRecords(employee_db,n1);
		          printf("the no of active records=%d",ans);
		          printf("\n Enter 1 to continue to MENU:\n");
	              scanf("%d",&T);
	              printf("\nSorted list according to name of the employee and name of the project");
                  sort(employee_db,n1);
	              break;
	  
          case 4:
                  isEmpty(employee_db,n1);
                  printf("\n Enter 1 to continue to MENU:\n");
	              scanf("%d",&T);
	              printf("\nSorted list according to name of the employee and name of the project_name");
                  sort(employee_db,n1);
                  break;
	  
          case 5: 
                  isFull(employee_db,n1);
                  printf("\n Enter 1 to continue to MENU:\n");
	              scanf("%d",&T);
	              printf("\nSorted list according to name of the employee and name of the project_name");
                  sort(employee_db,n1);
	              break;
          case 6:
                
                  ans=getTopmostemployee(employee_db,n1,name1);
	             
	              printf("\n Enter 1 to continue to MENU:\n");
	              scanf("%d",&T);
	              printf("\nSorted list according to name of the employee and name of the project_name");
                  sort(employee_db,n1);
                  break;
      
          case 7:
                  printf("enter k");
                  scanf("%d",&k);
                  sort(employee_db,n1);
                  KthTopMostProject(employee_db,n1,k);
				  
                  printf("\n Enter 1 to continue to MENU:\n");
                  scanf("%d",&T);
                  break;
        
          case 8:
	               
					fp2=fopen("empl2.txt","r");
					
					 i=0;
					while(!feof(fp2))
					{
		
					fscanf(fp2,"%s",&list_2[i].name);
					fscanf(fp2,"%s",&list_2[i].project_name);
					fscanf(fp2,"%d",&list_2[i].phone);
					fscanf(fp2,"%s",&list_2[i].address);
					fscanf(fp2,"%d",&list_2[i].no_of_hrs);
					fscanf(fp2,"%d",&list_2[i].sal);i++;
					}n2=i;
					   fclose(fp2);
					    for(i=0;i<n2;i++)
                       {
   							 	printf("%s ",list_2[i].name);
   							    printf("%s ",list_2[i].project_name);
    							   printf("%d ",list_2[i].phone);
    							   printf("%s ",list_2[i].address);
    							   printf("%d ",list_2[i].no_of_hrs);
								   printf("%d \n",list_2[i].sal);
						}
							fp1=fopen("empl1.txt","r");
						 i=0;
					while(!feof(fp1))
					{
		
					fscanf(fp1,"%s",&list_1[i].name);
					fscanf(fp1,"%s",&list_1[i].project_name);
					fscanf(fp1,"%d",&list_1[i].phone);
					fscanf(fp1,"%s",&list_1[i].address);
					fscanf(fp1,"%d",&list_1[i].no_of_hrs);
					fscanf(fp1,"%d",&list_1[i].sal);i++;
					}n1=i;
					   fclose(fp1);
					    for(i=0;i<n1;i++)
                       {
   							 	printf("%s ",list_1[i].name);
   							    printf("%s ",list_1[i].project_name);
    							   printf("%d ",list_1[i].phone);
    							   printf("%s ",list_1[i].address);
    							   printf("%d ",list_1[i].no_of_hrs);
								   printf("%d \n",list_1[i].sal);
						}
	             list_union(list_1,list_2,n1,n2);
	             printf("\n Enter 1 to continue to MENU:\n");
	             scanf("%d",&T);
	             break;

         case 9:
	             
				fp2=fopen("empl2.txt","r");
					
					 i=0;
					while(!feof(fp2))
					{
		
					fscanf(fp2,"%s",&list_2[i].name);
					fscanf(fp2,"%s",&list_2[i].project_name);
					fscanf(fp2,"%d",&list_2[i].phone);
					fscanf(fp2,"%s",&list_2[i].address);
					fscanf(fp2,"%d",&list_2[i].no_of_hrs);
					fscanf(fp2,"%d",&list_2[i].sal);i++;
					}n2=i;
					   fclose(fp2);
					    for(i=0;i<n2;i++)
    {
    	printf("%s ",list_2[i].name);
       printf("%s ",list_2[i].project_name);
       printf("%d ",list_2[i].phone);
       printf("%s ",list_2[i].address);
       printf("%d ",list_2[i].no_of_hrs);
	   printf("%d \n",list_2[i].sal);
	}
		fp1=fopen("empl1.txt","r");
						 i=0;
					while(!feof(fp1))
					{
		
					fscanf(fp1,"%s",&list_1[i].name);
					fscanf(fp1,"%s",&list_1[i].project_name);
					fscanf(fp1,"%d",&list_1[i].phone);
					fscanf(fp1,"%s",&list_1[i].address);
					fscanf(fp1,"%d",&list_1[i].no_of_hrs);
					fscanf(fp1,"%d",&list_1[i].sal);i++;
					}n1=i;
					   fclose(fp1);
					    for(i=0;i<n1;i++)
                       {
   							 	printf("%s ",list_1[i].name);
   							    printf("%s ",list_1[i].project_name);
    							   printf("%d ",list_1[i].phone);
    							   printf("%s ",list_1[i].address);
    							   printf("%d ",list_1[i].no_of_hrs);
								   printf("%d \n",list_1[i].sal);
						}
	
	          
                 list_intersection(list_1,list_2,n1,n2);
                 printf("\n Enter 1 to continue to MENU:\n");
	             scanf("%d",&T);
	             printf("\nSorted list according to name of the employee and name of the project_name");
                 sort(employee_db,n1);
                 break;
        
        case 10:
                  
					fp2=fopen("empl2.txt","r");
					
					 i=0;
					while(!feof(fp2))
					{
		
					fscanf(fp2,"%s",&list_2[i].name);
					fscanf(fp2,"%s",&list_2[i].project_name);
					fscanf(fp2,"%d",&list_2[i].phone);
					fscanf(fp2,"%s",&list_2[i].address);
					fscanf(fp2,"%d",&list_2[i].no_of_hrs);
					fscanf(fp2,"%d",&list_2[i].sal);i++;
					}n2=i;
					   fclose(fp2);
					    for(i=0;i<n2;i++)
    {
    	printf("%s ",list_2[i].name);
       printf("%s ",list_2[i].project_name);
       printf("%d ",list_2[i].phone);
       printf("%s ",list_2[i].address);
       printf("%d ",list_2[i].no_of_hrs);
	   printf("%d \n",list_2[i].sal);
	}
		fp1=fopen("empl1.txt","r");
						 i=0;
					while(!feof(fp1))
					{
		
					fscanf(fp1,"%s",&list_1[i].name);
					fscanf(fp1,"%s",&list_1[i].project_name);
					fscanf(fp1,"%d",&list_1[i].phone);
					fscanf(fp1,"%s",&list_1[i].address);
					fscanf(fp1,"%d",&list_1[i].no_of_hrs);
					fscanf(fp1,"%d",&list_1[i].sal);i++;
					}n1=i;
					   fclose(fp1);
					    for(i=0;i<n1;i++)
                       {
   							 	printf("%s ",list_1[i].name);
   							    printf("%s ",list_1[i].project_name);
    							   printf("%d ",list_1[i].phone);
    							   printf("%s ",list_1[i].address);
    							   printf("%d ",list_1[i].no_of_hrs);
								   printf("%d \n",list_1[i].sal);
						}
	             
	            list_difference(list_1,list_2,n1,n2);
	            printf("\n Enter 1 to continue to MENU:\n");
	            scanf("%d",&T);
	            printf("\nSorted list according to name of the employee and name of the project_name");
                sort(employee_db,n1);
	            break;
       case 11:
	         	fp1=fopen("empl1.txt","r");
						 i=0;
					while(!feof(fp1))
					{
		
					fscanf(fp1,"%s",&list_1[i].name);
					fscanf(fp1,"%s",&list_1[i].project_name);
					fscanf(fp1,"%d",&list_1[i].phone);
					fscanf(fp1,"%s",&list_1[i].address);
					fscanf(fp1,"%d",&list_1[i].no_of_hrs);
					fscanf(fp1,"%d",&list_1[i].sal);i++;
					}n1=i;
					   fclose(fp1);
					    for(i=0;i<n1;i++)
                       {
   							 	printf("%s ",list_1[i].name);
   							    printf("%s ",list_1[i].project_name);
    							   printf("%d ",list_1[i].phone);
    							   printf("%s ",list_1[i].address);
    							   printf("%d ",list_1[i].no_of_hrs);
								   printf("%d \n",list_1[i].sal);
						}
	             int u,p;
	             printf("enter u");
	             scanf("%d",&u);
	             printf("enter p");
	             scanf("%d",&p);
	               leastpopproject(employee_db,n1 , u ,p );
	             
	            
	            printf("\n Enter 1 to continue to MENU:\n");
                scanf("%d",&T);
                printf("\nSorted list according to name of the employee and name of the project_name");
                sort(employee_db,n1);
                break;
        case 13:
        	  printf("thnk u");T=0;
        	  break;
        case 12:
        	printf("enter the project name");
        	scanf("%s",&project_name1);
        	getMaxNumHrs(employee_db,n1,project_name1);
        	printf("highest no of %d hrs is spent on %s project is by %s employee",employee_db[i].no_of_hrs,employee_db[i].project_name,employee_db[i].name);
        	printf("\n Enter 1 to continue to MENU:\n");
	            scanf("%d",&T);
	            printf("\nSorted list according to name of the employee and name of the project_name");
                sort(employee_db,n1);
	            break;
        	
	  

        default:
                printf("\nInvalid choice");
     }
  }   
  getch();  
}


int initialize_db(struct employee_record employee_db[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
	   employee_db[i].name[0]='\0';
   	   employee_db[i].project_name[0]='\0';
	   employee_db[i].phone=0;
	   employee_db[i].no_of_hrs=0;
	   employee_db[i].address[0]='\0';
	   employee_db[i].sal=0;
    }
    return 0;
    getch();   
}

int insert(struct employee_record employee_db[],int n,char name1[],char project_name1[],int no_of_hrs1,int phone1,char address1[],int sal1 )
{
    int  sc=success;
    int i=0,j=0,found=0,free_index=0,flag=0;

 while((i<n)&&(found==0))
    {
     if((strcmp(employee_db[i].name,name1)==0)&&(strcmp(employee_db[i].project_name,project_name1)==0))
     {
       found=1;
     }
     else
     {
       i++;
     }
    }

    if(found==1)
    {
      employee_db[i].no_of_hrs=no_of_hrs1;
      employee_db[i].phone=phone1;
      strcpy(employee_db[i].address,address1);
       employee_db[i].sal=sal1;
      
    }
    
    else
    {
      free_index=0;
      i=0;
      while((i<n)&&(free_index==0))
      {
    	if(employee_db[i].name[0]=='\0')
    	{
    	  free_index=1;
    	}
    	else 
    	{
    	 i++;
    	}
      }

      if(free_index==0)
      {
      	sc=failure;
      }
      else
      {
       
          strcpy(employee_db[i].name,name1);
          strcpy(employee_db[i].project_name,project_name1);
          employee_db[i].phone=phone1;
          employee_db[i].no_of_hrs=no_of_hrs1;
             strcpy(employee_db[i].address,address1);
                employee_db[i].sal=sal1;         
       
      }
    }

    return sc;
    getch();
 }
 

int sort(struct employee_record employee_db[],int n)
{
   int i,j,flag=1;
   struct employee_record temp;

   for(i=0;(i<n-1)&&(flag==1);i++)
   {  flag=0;
     for(j=0;j<n-1-i;j++)
     {
       if(strcmp(employee_db[j].name,employee_db[j+1].name)>=0)
       {
       	  if((strcmp(employee_db[j].name,employee_db[j+1].name)==0) && (strcmp(employee_db[j].project_name,employee_db[j+1].project_name)>0))
	      {
		           temp=employee_db[j+1];
	               employee_db[j+1]=employee_db[j];
		           employee_db[j]=temp;flag=1;
	      }
	      else
	      {
		           temp=employee_db[j+1];
	               employee_db[j+1]=employee_db[j];
		           employee_db[j]=temp;flag=1;
	      }
       }
     }
   }

   printf("\n Records after sorting:");

   for(i=0;i<n;i++)
   {
     printf("\n%s\t%s\t%d\t%d\t%s\t%d",employee_db[i].name,employee_db[i].project_name,employee_db[i].phone,employee_db[i].no_of_hrs,employee_db[i].address,employee_db[i].sal);
   }
  
  
}

int delete1(struct employee_record employee_db[],int n,char name1[],char project_name1[])
 {
     int found=0,i=0;
     while((i<n)&&(found==0))
     {
                            
			     if((strcmp(employee_db[i].name,name1)==0)&&(strcmp(employee_db[i].project_name,project_name1))==0)
			     {
				  found=1;  
			     }
			     else
			     {
		     		 i++;
			     }
			     
     }
     if(found==1)
     {
        employee_db[i].name[0]='\0';
	    employee_db[i].project_name[0]='\0';
     	employee_db[i].phone=0;
     	employee_db[i].no_of_hrs=0;
     	employee_db[i].address[0]='\0';
     	printf("delete operation is successful");
      }
      else if(found==0)
      {
	    printf("\nRecord cant be deleted becoz its not found");
      }
      else
      printf("not found\n");

 return 0;
 getch();
}


int getNumRecords(struct employee_record employee_db[],int n)
{   int i,cnt=0;
    for(i=0;i<n;i++)
    {
      if(((employee_db[i].name[0])!='\0')&&((employee_db[i].project_name[0])!='\0')) 
      {
	   cnt++; 
      }
    }
    return cnt;
}

int isEmpty(struct employee_record employee_db[],int n)
{
    int found=0,i,flag=0;
    for(i=0;i<n&&found==0&&flag==0;i++)
    {
		if((employee_db[i].name[0]=='\0') &&(employee_db[i].project_name[0]=='\0'))
		      { found=0;
                   }
	          else
	          {
			    found=1;
			    flag=1;
	     	  }
     }

     if(found==0)
     {
         printf("\nList is empty");
     }
     else if (found==1&&flag==1)
     {
	 printf("\nList is not empty");
     }

return found;
    
}

int isFull(struct employee_record employee_db[],int n)
{
    int found=0,i;
    for(i=0;i<n&&found==0;i++)
    {
		      if(employee_db[i].name[0]!='\0'&&employee_db[i].project_name[0]!='\0'&&employee_db[i].phone!=0&&employee_db[i].no_of_hrs!=0&&employee_db[i].address[0]!='\0')
		      {
				   found=0;
		      }
		      else
	          {
			    found=1;
			  }
     }

     if(found==0)
     {
		 printf("\nList is full");
     }
     else
     {
	 printf("\nList is not full");
     }

return 0;
getch();
}

int getTopmostemployee(struct employee_record employee_db[],int n,char name1[20])
{
	int i;
	int sum=employee_db[0].no_of_hrs;
	int max=0;
	for(i=1;i<n;i++)
	{
		 if((strcmp(employee_db[i-1].name,employee_db[i].name))==0)
		{
			sum=sum+employee_db[i].no_of_hrs;
		}
		else
		{
			if(sum>max)
			{
				max=sum;
			}
			sum=employee_db[i].no_of_hrs; 
		}
	}
	printf("\n		the max number of working hours is: %d",max);
	sum=employee_db[0].no_of_hrs;
	
	for(i=1;i<n;i++)
	{
		if((strcmp(employee_db[i-1].name,employee_db[i].name))==0)
		{
			sum=sum+employee_db[i].no_of_hrs;
		}
		else
		{
			if(sum==max)
			{
			 	printf("\n		name of the employee: %s\n",employee_db[i-1].name);
			}
			sum=employee_db[i].no_of_hrs;
		}
	}
}


int list_removedup(struct employee_record employee_db[],int n)
{
  int i,max=0,j=0;
  sort(employee_db,n);
  for(i=0;i<n;i++)
  {
		  if((strcmp(employee_db[i].name,employee_db[i+1].name)==0)&& (strcmp(employee_db[i].project_name,employee_db[i+1].project_name)==0))
		  {
			while((strcmp(employee_db[i].name,employee_db[i+1].name)==0)&& (strcmp(employee_db[i].project_name,employee_db[i+1].project_name)==0))
			{
			     if(employee_db[i].no_of_hrs>employee_db[i+1].no_of_hrs)
			     {
				 max=employee_db[i].no_of_hrs;
			     }
			     else
			     {
				     max=employee_db[i+1].no_of_hrs;
			     }
			     i++;
		       }
		     employee_db[j]=employee_db[i];
		     employee_db[j].no_of_hrs=max;
		     j++;
		  }
	      else
		  {
		      employee_db[j]=employee_db[i];
		      j++;
		  }
  }
  printf("\n New array");
  for(i=0;i<n;i++)
  {
		 printf("\t%s\t%s\t%d\t%d\t%s",employee_db[i].name,employee_db[i].project_name,employee_db[i].phone,employee_db[i].no_of_hrs,employee_db[i].address);
		 printf("\n");
		 }
    getch();
    return 0;
}

int list_union(struct employee_record list_1[],struct employee_record list_2[],int l,int m)
{
    int k=0,p;
    int i,j;

    for(i=0;i<l;i++)
    {
	  strcpy(list_3[k].name,list_1[i].name);
	  strcpy(list_3[k].project_name,list_1[i].project_name);
	  list_3[k].phone=list_1[i].phone;
	  list_3[k].no_of_hrs=list_1[i].no_of_hrs;
	  strcpy(list_3[k].address,list_1[i].address);
	  list_3[k].sal=list_1[i].sal;
	  k++;
    }
    for(j=0;j<m;j++)
    {
      strcpy(list_3[k].name,list_2[j].name);
	  strcpy(list_3[k].project_name,list_2[j].project_name);
	  list_3[k].phone=list_2[j].phone;
	  list_3[k].no_of_hrs=list_2[j].no_of_hrs;
	  strcpy(list_3[k].address,list_1[i].address);
	    list_3[k].sal=list_1[i].sal;
	  k++;              
     }
     p=k;
     sort(list_3,p);
     list_removedup(list_3,p);
     
		      getch();
		      return 0;
}

int list_intersection(struct employee_record list_1[],struct employee_record list_2[],int l,int m)
{
    int i,j,k=0,p,max=0;
    for(i=0;i<l;i++)
    {
	for(j=0;j<m;j++)
	{
	    if((strcmp(list_1[i].name,list_2[j].name)==0)&& (strcmp(list_1[i].project_name,list_2[j].project_name)==0))
	    {
		      if(list_1[i].sal<list_2[j].sal)
		      {
			   max=list_2[j].sal;
		      }
		      else
		      {
			  max=list_1[i].sal;
		      }

		      strcpy(list_3[k].name,list_1[i].name);
		      strcpy(list_3[k].project_name,list_1[i].project_name);
		      list_3[k].phone=list_1[i].phone;
		      strcpy(list_3[k].address,list_1[i].address);
		      list_3[k].sal=max;
		      k++;
	    }
	}
    }
    p=k;
    printf("\n Intersection of two arrays:");
    for(k=0;k<p;k++)
     {
	       printf("\t%s\t%s\t%d\t%d\t%s\t%d",list_3[k].name,list_3[k].project_name,list_3[k].phone,list_3[k].no_of_hrs,list_3[k].address,list_3[k].sal);
	       printf("\n");
     }
    getch();
  return 0;
}

 int list_difference(struct employee_record list_1[],struct employee_record list_2[],int l,int m)
 {
      int i,j,cnt=0,k=0,p,min=0;
     for(i=0;i<l;i++)
     {
	   for(j=0;j<m;j++)
	   {
			   if((strcmp(list_1[i].name,list_2[j].name)==0)&& (strcmp(list_1[i].project_name,list_2[j].project_name)==0))
			   {
			   cnt= 1;
			   }

	   }
	   if(cnt==0)
	   {
			   strcpy(list_3[k].name,list_1[i].name);
			   strcpy(list_3[k].project_name,list_1[i].project_name);
			   list_3[k].phone=list_1[i].phone;
		       list_3[k].no_of_hrs=min;
			   k++;
        }
      }
     p=k;
     printf("\n Difference of two arrays:");
      sort(list_3,p);
     
     getch();
     return 0;
}
 
int getMaxNumHrs(struct employee_record employee_db[], int n , char project_name1[20])
{
	int max=0;
	int i;
	
	
	for(i=0;i<n;i++)
	{
		if(strcmp(employee_db[i].project_name,project_name1)==0)
		{
			if(employee_db[i].no_of_hrs>max)
			{
				max=employee_db[i].no_of_hrs;
			}
		}
	}
	
	printf("%d\n",max);
	
	for(i=0;i<n;i++)
	{
		if(strcmp(employee_db[i].project_name,project_name1)==0)
		{
			if(employee_db[i].no_of_hrs==max)
			{
				printf("       %s\n",employee_db[i].name);
			}
		}
	}
	getch();
	return 0;
}    

void KthTopMostProject(struct employee_record employee_db[], int n ,int k)  
{
	int i,max=0,count=0,j,min;
    float avg[6];
	
	//finding the average working hours of a project
	for(i=0;i<6;i++)
	{
		avg[i]=0;
		count=0;
		for(j=0;j<n;j++)
		{
			if(strcmp(employee_db[j].project_name,pronames[i])==0)
			{
				avg[i]=avg[i]+employee_db[j].no_of_hrs;
				count++;
			}
		}
		if(count!=0)
		avg[i]=avg[i]/count;
	}
	
	//bubble sort technique to find Kth topmost average
	float t;
	
	char str[5];
	for(i=0;i<6;i++)
	{
		for(j=0;j<5-i;j++)
		{
			if(avg[j]>avg[j+1])
			{
				t=avg[j];
				avg[j]=avg[j+1];
				avg[j+1]=t;
				strcpy(str,pronames[j]);
				strcpy(pronames[j],pronames[j+1]);
				strcpy(pronames[j],str);
			}
		}
		
	}
	printf("\n		name of project:%s \n",pronames[n-i]);
}
int leastpopproject(struct employee_record employee_db[],int n,int k,int p)

{
		int i,j;
	float perc[5];

	int cnt=0,tcnt=0;
	
	//finding percentage of employees working for less than p hours// 
	for(i=0;i<6;i++)
	{
		cnt=0;
		tcnt=0;
		for(j=0;j<n;j++)
		{
			if(strcmp(employee_db[j].project_name,pronames[i])==0)
			{
				if(employee_db[j].no_of_hrs<p)
				cnt++;
				tcnt++;//no of employees working on same project//
			}
		}
		if(tcnt!=0)
		perc[i]=(cnt*100)/tcnt;
		
	}
	
	printf("\n		LIST OF PROJECTS: \n");
	for(i=0;i<6;i++)
	{
		int t=(int)perc[i];
		if(t>=k)
		printf("		%s\n",pronames[i]);
	}
	
}	

	

