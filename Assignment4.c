#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct record_info
{
    int id ;
    char name[64]  ;
    char password[64]  ;
    int amount ;

}record ;

void insert()
{
    system("cls") ;
    printf("Please Insert data \n") ;

    FILE *info;

		info = fopen("info.txt","a");

		if(info==NULL)
		{
		    printf("Sorry, Cannot Open Database!\n");
			exit(1) ;
		}

    printf("\nType Your ID : ") ;
    scanf("%d", &record.id) ;

    printf("\nEnter your name : ");
    scanf("%s",&record.name) ;

    printf("\nType your password(character only) : ") ;
    scanf("%s",&record.password) ;

    printf("\nEnter your amount : ") ;
    scanf("%d", &record.amount) ;

    fwrite(&record, sizeof(record), 1, info) ;
    fclose(info) ;

}
void search()
{
    system("cls") ;
    char s_name[128] ;
    FILE *search ;
    search = fopen("info.txt","r") ;
    int search_data ;

    if(search==NULL)
    {
        printf("\nNO DATA\n") ;
        return;
    }

    printf("\nEnter Name You Want to Search :") ;
    scanf("%s",&s_name) ;

    while(fread(&record,sizeof(record),1,search))
    {
        if(strcmp(s_name,record.name)==0)
        {
          search_data = 1 ;

          printf("\nDATA FOUND\n") ;

          printf("\nID= %d , NAME= %s , PASSWORD= %s , AMOUNT= %d\n",record.id,record.name,record.password,record.amount) ;

        }
    }
    fclose(search);

        if(search_data==0)
				{
				    printf("\nDATA NOT FOUND \n");
				}
  		return ;

}
void list()
{
    system("cls") ;
    printf("\n********************************************LIST********************************************\n");
	FILE *all_list ;
	all_list=fopen("info.txt","r") ;
	if(all_list==NULL)
	{
	    printf("\nNO DATA\n") ;
        return ;
	}

	while(fread(&record,sizeof(record),1,all_list))
		{
		 printf("\nID= %d , NAME= %s , PASSWORD= %s , AMOUNT= %d\n",record.id,record.name,record.password,record.amount) ;
		}
	fclose(all_list);

    return;
}
void edit()
{
    system("cls") ;
    char e_name[128] ;
    FILE *info , *change1 ;
    info = fopen("info.txt","r") ;
    change1 = fopen("temp.txt","w") ;
    int change_data=0;

    if(info==NULL)
    {
        printf("\nNO DATA\n") ;
        return;
    }

    printf("\nEnter Name You Want to change :") ;
    scanf("%s",&e_name) ;

    while(fread(&record,sizeof(record),1,info))
    {
        if(strcmp(e_name,record.name)==0)
        {
          change_data= 1 ;

          printf("\nDATA FOUND\n") ;

          printf("\nID= %d , NAME= %s , PASSWORD= %s , AMOUNT= %d\n",record.id,record.name,record.password,record.amount) ;




          int *choice ;
          int a = &choice ;

          printf("\nWhat You Want to Change: 1->ID , 2->NAME , 3->PASSWORD , 4->AMOUNT :") ;
          scanf("%d", &a) ;

          switch(a)
          {
          case 1:

           printf("\nEnter ID you want to change:") ;
           scanf("%d",&record.id) ;
           printf("\nID change success\n") ;
           fwrite(&record, sizeof(record.id), 1, change1) ;

           fclose(info) ;
           fclose(change1) ;

           if(change_data)
           {
               change1 = fopen("temp.txt","r") ;
               info = fopen("info.txt","r+") ;

               while(fread(&record,sizeof(record.id),1,change1))
               {
                   fwrite(&record,sizeof(record.id),1,info) ;
               }
           fclose(info) ;
           fclose(change1) ;
           remove("temp.txt") ;
           }
           break ;

          case 2:

           printf("\nEnter name you want to change:") ;
           scanf("%s",&record.name) ;
           printf("\nName change success\n") ;
           fwrite(&record, sizeof(record.name), 1, change1) ;

           fclose(info) ;
           fclose(change1) ;

           if(change_data)
           {
               change1 = fopen("temp.txt","r") ;
               info = fopen("info.txt","r+") ;

               while(fread(&record,sizeof(record.name),1,change1))
               {
                   fwrite(&record,sizeof(record.name),1,info) ;
               }
           fclose(info) ;
           fclose(change1) ;
           remove("temp.txt") ;
           }
           break ;

          case 3:
            printf("\nEnter password you want to change(character only):") ;
           scanf("%s",&record.password) ;
           printf("\npassword change success\n") ;
           fwrite(&record, sizeof(record), 1, change1) ;

           fclose(info) ;
           fclose(change1) ;

           if(change_data)
           {
               change1 = fopen("temp.txt","r") ;
               info = fopen("info.txt","r+") ;

               while(fread(&record,sizeof(record.password),1,change1))
               {
                   fwrite(&record,sizeof(record.password),1,info) ;
               }
           fclose(info) ;
           fclose(change1) ;
           remove("temp.txt") ;
           }
           break ;

          case 4:

            printf("\nEnter amount you want to change:") ;
           scanf("%d",&record.amount) ;
           printf("\namount change success\n") ;
           fwrite(&record, sizeof(record), 1, change1) ;

           fclose(info) ;
           fclose(change1) ;

           if(change_data)
           {
               change1 = fopen("temp.txt","r") ;
               info = fopen("info.txt","r+") ;

               while(fread(&record,sizeof(record.amount),1,change1))
               {
                   fwrite(&record,sizeof(record.amount),1,info) ;
               }
           fclose(info) ;
           fclose(change1) ;
           remove("temp.txt") ;
           }
           break ;

          }


      }

}

}

int main()
{
       int *data ;
       int i = &data ;


        printf("\n********************************************Welcome********************************************\n") ;

        printf("\nPress 1 -> Insert Data") ;
        printf("\nPress 2 -> Search Data") ;
        printf("\nPress 3 -> List Data") ;
        printf("\nPress 4 -> Change Data") ;

        printf("\nEnter your choice : ") ;
        scanf("%d", &i) ;

        while (i == 0 || i < 5)
        {

        switch(i)
        {
            case 1:
			insert() ;
			break ;

			case 2:
            search() ;
            break ;

            case 3:
            list() ;
            break ;

            case 4:
            edit() ;
            break ;
        }

        printf("\nPress 1 -> Insert Data") ;
        printf("\nPress 2 -> Search Data") ;
        printf("\nPress 3 -> List Data") ;
        printf("\nPress 4 -> Change Data") ;


        printf("\nEnter your choice : ") ;
        scanf("%d", &i) ;

        }

   return 0 ;
}
