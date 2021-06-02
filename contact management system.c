#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>

struct contact

{

    long ph;

    char first[20],last[20],email[30];

} list;

char query[20],first[20];

FILE *fp, *ft;

int i,n,ch,l,found;

int main()

{

main:

    system("cls");    /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add New Contact\n\t\t[2] View All Contacts\n\t\t[3] Search Contacts\n\t\t[4] Modify Contacts\n\t\t[5] Delete Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add new contacts************  */

    case 1:

        system("cls");

        fp=fopen("contact.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input\nFirst Name:");

            scanf("%[^\n]",&list.first);

            if(stricmp(list.first,"")==0 || stricmp(list.first," ")==0)

                break;

            fflush(stdin);
            
            printf("Last Name:");

            scanf("%[^\n]",&list.last);
            
            fflush(stdin);

            printf("E-mail Address:");

            gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);
            
            printf("Phone Number:");

            scanf("%ld",&list.ph);

            fflush(stdin);

        }

        fclose(fp);

        break;

        /* *********************list of contacts*************************  */

    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.first[0]==i || list.first[0]==i-32)

                {

                    printf("\nfirst Name\t: %s\nLast Name\t: %s\nE-mail Address\t: %s\nPhone number\t: %ld\n",list.first,

                           list.last,list.email,list.ph);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

        /* *******************search contacts**********************  */

    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("contact.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    first[i]=list.first[i];

                first[l]='\0';

                if(stricmp(first,query)==0)

                {

                    printf("\n..::First Name\t: %s\n..::Last Name\t: %ld\n..::E-mail Address\t: %s\n..::Phone Number\t: %s\n",list.first,list.last,list.email,list.ph);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

        /* *********************edit contacts************************/

    case 4:

        system("cls");

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

        scanf("%[^\n]",first);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(first,list.first)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",first);

        printf("..::First Name:");

        scanf("%[^\n]",&list.first);

        fflush(stdin);
        
        printf("..::Last Name:");

        scanf("%[^\n]",&list.last);

        printf("..::E-mail Address:");

       

        printf("..::Phone Number:");

        scanf("%[^\n]",&list.ph);

        fflush(stdin);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.dll");

        rename("temp.dat","contact.dll");

        break;

        /* ********************delete contacts**********************/

    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]",&first);

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(first,list.first)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.dll");

        rename("temp.dat","contact.dll");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}
