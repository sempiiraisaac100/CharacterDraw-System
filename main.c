#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <mysql.h>
#include <time.h>


int main(){
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL_FIELD* col;

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   conn = mysql_init(NULL);


    //static const char studentID[]="Clarance", password[]="123456";
    char *pupil_code[4];
    char *username;
    int n=1;
    char *query_;
    int query_len;
    char *run_query;

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("database connection initialized...");
   }

    //printf("user name must not exceed%lu %lu:", strlen(username), strlen(pupil_code));
    do{
        printf("\nenter username: ");
        scanf("%s", &username);
        fflush(stdout);

        printf("\nenter pupil_code: ");
        scanf("%s", &pupil_code);
        fflush(stdout);
            //sql ="SELECT SID,`UserName`,`Password`,Class FROM `Students` WHERE `UserName`='"+username+"' && `Password`= '"+password+"'";
        query_ = "SELECT `pupil_code` FROM `pupils` WHERE `pupil_code`= 'pupil_code'";
        query_len = strlen(query_);

        run_query = (char *) malloc(query_len);
        snprintf(run_query, query_len, "SELECT `id` FROM `pupils` WHERE `id`= '%s'",pupil_code);


           /* send SQL query */
           if (mysql_query(conn,run_query)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
           }else {
                   res = mysql_use_result(conn);

                   if ((row = mysql_fetch_row(res)) != NULL){
                         printf("\nLogin Successful...\n");
                         mysql_free_result(res);
                         break;
                   }else {
                         printf("\nWrong Password, try again\n", 5-n);
                         /* flash results */
                         mysql_free_result(res);
                         getchar();
                         n++;
                         }

                         if(n>5){
                         printf("\nAccess Denied\n");
                         getchar();
                         exit(0);
                         }
                  }

        }while (n<=5);

/* close connection */
   mysql_close(conn);

   menu(pupil_code);

  return 0;
}

int menu(char *code_[4]){
	char *i;
	char *com1 = "Viewall";
	char *com2 = "Checkstatus";
	char *com3 = "Viewassignment";
	char *com4 = "Checkdates";
	char *com5 = "RequestActivation";
	char com[strlen(com5)];
	char option;
	char *a_id[4];

	for(i = 0; i < 100; i++)
		printf("=");
	printf("\n\t\t\tWelcome to the KinderCare Character Draw System.\n");
	for(i = 0; i < 100; i++)
		printf("=");

	while(option != '1' && option != '0')

	{
		printf("\nPlease Enter any of the following commands to proceed.");
		printf("\n1. Viewall");
		printf("\n2. Checkstatus");
		printf("\n3. Viewassignment");
		printf("\n4. Checkdates");
		printf("\n5. RequestActivation\n\n");
		printf("Enter command here(for example \"Viewall\" to view assignments): ");

		scanf("%s", &com);
		fflush(stdout);

		if(strcmp(com, com1)==0){
			printf("\nYou have selected option ");
			puts(com1);

			Viewall();

		}
		else if(strcmp(com, com2)==0){
			printf("\nYou have selected option ");
			puts(com2);

			Checkstatus();
		}
		else if(strcmp(com, com3)==0){
			printf("\nYou have selected option ");
			puts(com3);
			Viewassignment(code_);
		}
		else if(strcmp(com, com4)==0){
			printf("\nYou have selected option ");
			puts(com4);

			Checkdates();
		}
		else if(strcmp(com, com5)==0){
			printf("\nYou have selected option ");
			puts(com5);

			RequestActivation();
		}
		else{
			printf("\nYou have selected an invalid option. Try again.");
		}

		printf("\nEnter 1 to quit or 0 to attempt an assignment or any other character to continue: ");
		getchar();
		option = getchar();


	}

	if (option = '0'){

       printf("\n\nEnter assignment_id (e.g. 1): \n\n");
        //scanf("%i.%i.%i",&d,&m,&y);
       scanf("%s",a_id);
       fflush(stdout);

       Attemptassignment(code_,a_id);

	}

	return 0;
}

int Viewall(){

   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL_FIELD* col;
   conn = mysql_init(NULL);

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("\ndatabase records...\n\n");
   }

        if (mysql_query(conn, "SELECT `id`,`characters`,`expiry_date`,`attempt_status`,`activation_status` FROM assignments")) {
                printf("Unable to connect with MySQL server\n");
                mysql_close(conn);
                return 1;
            }


            res = mysql_store_result(conn);

            if (res == NULL) {
                printf("Unable to compile SQL statement\n");
                mysql_close(conn);
                return 1;
            }



                while (col = mysql_fetch_field(res)) {
                    printf("%s       ", col->name);
                }

                 printf("\n\n");
                 while (row = mysql_fetch_row(res)){
                 printf("%s       %s              %s           %s            %s   \n", row[0], row[1], row[2], row[3], row[4], row[5]);
                 }


            /* flash results */
            mysql_free_result(res);
            mysql_close(conn);

            return 0;
}

int RequestActivation(){

   MYSQL *conn;

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   conn = mysql_init(NULL);
        /* Connect to database */
       if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          printf("can't initialize database connection..");
          exit(1);
       } else {
         puts("On the database connection...");
       }

    //static const char studentID[]="Clarance", password[]="123456";
    char *assignment_id[4],*pupil_code[4],*query_,*run_query;
    int m_len,m_len2,query_len;
    char *m;

    char message_[10];
    char message1_[10];
    char message2_[10];
    char buff[1024];

        printf("\nenter deactivated assignment_id: ");
        scanf("%s", &assignment_id);
        fflush(stdout);

        printf("\nenter your pupil_code: ");
        scanf("%s", &pupil_code);
        fflush(stdout);

        printf("\n\n");

        //do{
        printf("enter your request_message (not exceeding 3 words): ");

        scanf("%s %s %s",message_,message1_,message2_);
        //printf("%s\n", message_);


        snprintf(buff, sizeof buff, "INSERT INTO requests (pupil_id, assignment_id, message) VALUES ('%s', '%s', '%s %s %s')",pupil_code,assignment_id,message_,message1_,message2_);

        //sprintf(buf, query_string,p_code,a_id,average_score,time_taken);
        if (mysql_query(conn,buff)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
           }else {

                   printf("\n\nActivation Request sent successfully...\n\n");
                 }

         //char a[100];
         //printf("Enter Ur sentence \n");
         //scanf("%[a-z]",message_);
         //printf("%s\n",message_);

        //char name[10];
        //printf("Enter your name: ");
        //fgets(message_, 10, stdin);
        //printf("Hello %s! \n", message_);


        //char sen[100];
        //scanf("%[^\n]s", sen);
        /*char str[100];

           printf( "Enter a value :");
           gets( str );

           printf( "\nYou entered: ");
           puts( str );*/
            //scanf("%[^\n]s", &message_);
            //gets( message_ );

                 //gets(message_);


            //fflush(stdout);
           // m_len = strlen(message_);
         //if(m_len>100){
            //puts("your characters exceeded 100!!.. repeat the message...");
         //   exit(1);
         //}
      // }while(m_len>100);

        //m = message_;
        /*

        query_ = "INSERT INTO requests (pupil_code, assignment_id, message) VALUES ('%s', '%s', '%s')";

        query_len = strlen(query_)+ m_len + 9;

        run_query = (char *) malloc(query_len);
        snprintf(run_query, query_len, "INSERT INTO requests (pupil_code, assignment_id, message) VALUES ('%s', '%s', '%s')",pupil_code,assignment_id,m);
          */
           /* send SQL query */
          /* if (mysql_query(conn,run_query)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
           }else {

                   printf("\n\nActivation Request sent successfully...\n\n");
                 }*/

   mysql_close(conn);

   return 0;
}

int Checkstatus(){

   MYSQL *conn;
   char *query_;
   int num_rows;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL_FIELD* col;
   conn = mysql_init(NULL);

   int t,a,n,m;

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("\nfetching from the database...\n\n");
   }

         query_ = "SELECT(SELECT COUNT(*) FROM assignments) AS Total_Assignments,\
                  (SELECT COUNT(*) FROM assignments WHERE attempt_status ='attempted') AS Attempted_Percentage,\
                  (SELECT COUNT(*) FROM assignments WHERE attempt_status ='not_attempted')AS Not_Attempted_Percentage,\
                  (SELECT COUNT(*) FROM assignments WHERE attempt_status ='missed')AS Missed_Percentage";

                 /* query_ = "SELECT(SELECT COUNT(*) FROM assignments) AS Total_Assignments,\
                  (SELECT COUNT(*) FROM assignments WHERE attempt_status ='attempted') AS Attempted,\
                  (SELECT COUNT(*) FROM assignments WHERE attempt_status ='not_attempted')AS Not_Attempted,\
                  (SELECT COUNT(*) FROM assignments WHERE attempt_status ='missed')AS Missed";*/

                  //query_ = "SELECT COUNT(*) AS Total_Assignments FROM assignments";

        if (mysql_query(conn, query_)) {
                printf("Unable to connect with MySQL server\n");
                mysql_close(conn);
                return 1;
            }

            res = mysql_store_result(conn);

            if (res == NULL) {
                printf("Unable to compile SQL statement\n");
                mysql_close(conn);
                return 1;
            }
            num_rows = mysql_num_rows(res);

            if(num_rows<1){
                printf("no rows returned");
                exit(1);
            }


                while (col = mysql_fetch_field(res)) {
                    printf("%s     ", col->name);
                }

                 printf("\n\n");
                 while (row = mysql_fetch_row(res)){
                        t = atoi(row[0]);
                        a = atoi(row[1]);
                        n = atoi(row[2]);
                        m = atoi(row[3]);
                 printf("%d                              %.2f                   %.2f                     %.2f\n",t,((float)a/(float)t)*100, ((float)n/(float)t)*100, ((float)m/(float)t)*100);


                 printf("\n\nTotal Assignments: %s\n", row[0]);
                 printf("\nNumber of Assignments Attempted: %s\n", row[1]);
                 printf("\nNumber of Assignments Not_Attempted: %s\n", row[2]);
                 printf("\nNumber of Assignments Missed: %s\n", row[3]);

                 }
           // }

           /* flash results */
            mysql_free_result(res);
            mysql_close(conn);

            return 0;
}

int Checkdates(){

   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL_FIELD* col;
   conn = mysql_init(NULL);

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";


    int d,m,y,d1,m1,y1;
    char *cmd[10], option;
    char *query_,*run_query;
    int query_len;

    //int a=10;int a1=11;int b=2; int c=2022;

  /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     puts("fetching from the database...");
   }

    do{
        printf("\n\nEnter command \"Checkdates datefrom dateto\" using (date-format: dd-mm-yyyy): \n\n");
        //scanf("%i.%i.%i",&d,&m,&y);
        scanf("%s %i-%i-%i %i-%i-%i",&cmd,&d,&m,&y,&d1,&m1,&y1);
        fflush(stdout);

       if(d){
          printf("\nValidating datefrom...\n\n");

          if(validatedate(d,m,y)==0){
             printf("It is a valid date format!\n\n");
             option ='1';
          }else{
             printf("It's an invalid date format!\n\n");

             printf("\nEnter 0 to quit or any other character to re-enter command: ");
             getchar();
             option = getchar();
             //if(option=='0') exit(0);
          }
        }
        if(d1){
          printf("\nValidating dateto...\n\n");

          if(validatedate(d1,m1,y1)==0){
             printf("It is a valid date format!\n\n");
             option='1';
          }else{
             printf("It's an invalid date format!\n\n");

             printf("\nEnter 0 to quit or any other character to re-enter command: ");
             getchar();
             option = getchar();
             //if(option=='0') exit(0);
          }
        }

    if(option=='0') exit(0);
    }while(option!='1');

    query_ = "SELECT `id`,`characters`,`expiry_date`,`attempt_status`,`activation_status` FROM `assignments` WHERE expiry_date BETWEEN '&i-&i-&i' AND '&i-&i-&i'";

        query_len = strlen(query_)+15;

        run_query = (char *) malloc(query_len);
        snprintf(run_query, query_len, "SELECT `id`,`characters`,`expiry_date`,`attempt_status`,`activation_status` FROM `assignments` WHERE expiry_date BETWEEN '%i-%i-%i' AND '%i-%i-%i'",y,m,d,y1,m1,d1);

        //snprintf(run_query, query_len, "SELECT * FROM `assignments` WHERE expiry_date BETWEEN '%i-%i-%i' AND '%i-%i-%i'",c,b,a,c,b,a1);

           /* send SQL query */
           if (mysql_query(conn,run_query)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
           }else {

                    res = mysql_store_result(conn);

                    if (res == NULL) {
                        printf("Unable to compile SQL statement\n");
                        mysql_close(conn);
                        return 1;
                    }

                    while (col = mysql_fetch_field(res)) {
                        printf("%s  ", col->name);
                    }

                     printf("\n\n");
                     while (row = mysql_fetch_row(res)){
                     printf("%s   %s             %s        %s             %s     \n", row[0], row[1], row[2], row[3], row[4], row[5]);
                     }
                 }

                /* flash results */
                mysql_free_result(res);
                mysql_close(conn);

                return 0;

}

int validatedate(int d,int m,int y){

      int legit = 0;
      int leap = 0;

            if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
                    {leap=1;}
                if (m<13)
                {
                    if (m == 1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 )
                        {if (d <=31)
                            {legit=1;}}
                    else if (m == 4 || m==6 || m==9 || m==11 )
                        {if (d <= 30)
                            {legit = 1;}}
                    else
                        {
                                    if (leap == 1)
                                          {if (d <= 29)
                                                {legit = 1;}}
                                    if (leap == 0)
                                          {{if (d <= 28)
                                                legit = 1;}}
                         }
                }
                if (legit==1)
                    return 0;
                else
                    return 1;

}

int Viewassignment(char *p[4]){

   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL_FIELD* col;
   conn = mysql_init(NULL);

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   char cmd[15];
   char *query_,*run_query;
   //char *p[4];
   char *k[4];

   int query_len,num_rows;

   /*p = "p000";
   k = "a000";
   printf("%s\n",p);
   printf("%s\n",k);*/



    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {

    printf("\n\nEnter command \"Viewassignment assignment_id\(e.g. Viewassignment a003): \n\n");
        //scanf("%i.%i.%i",&d,&m,&y);
    scanf("%s %s",&cmd,k);
    fflush(stdout);
    //printf("%s\n",cmd);
   // printf("%s\n",k);

    /*printf("\n\nEnter your pupil_code: ");
        //scanf("%i.%i.%i",&d,&m,&y);
    scanf("%s",&p);
    fflush(stdout);
    printf("%s\n",p);*/

   /* printf("\n\nEnter your ass_code: ");
        //scanf("%i.%i.%i",&d,&m,&y);
    scanf("%s",&k);
    fflush(stdout);
    printf("%s\n",k);*/


    printf("\nfetching from database records...\n\n");

   }
    query_ = "SELECT `pupil_id`,`assignment_id`,`average_score`,`attempt_duration_in_seconds`,`teacher_comment` FROM `attempt` WHERE `pupil_id`='%s' AND `assignment_id`='%s'";

    //query_ = "SELECT `pupil_code`,`assignment_id`,`average_score`,`attempt_duration(seconds)`,`teacher_comment` FROM `attempt` WHERE `pupil_code`='%s'";

    query_len = strlen(query_)+9;

    run_query = (char *) malloc(query_len);
    snprintf(run_query, query_len, "SELECT `pupil_id`,`assignment_id`,`average_score`,`attempt_duration_in_seconds`,`teacher_comment` FROM `attempt` WHERE `pupil_id`='%s' AND `assignment_id`='%s'",p,k);

    //snprintf(run_query, query_len, "SELECT `pupil_code`,`assignment_id`,`average_score`,`attempt_duration(seconds)`,`teacher_comment` FROM `attempt` WHERE `pupil_code`='%s'",p);


        if (mysql_query(conn,run_query )) {
                fprintf(stderr, "%s\n", mysql_error(conn));
                mysql_close(conn);
                return 1;
            }


            res = mysql_store_result(conn);

            if (res == NULL) {
                printf("Unable to compile SQL statement\n");
                mysql_close(conn);
                return 1;
            }

            num_rows = mysql_num_rows(res);

            if(num_rows<1){
                printf("no rows returned");
                exit(1);
            }

                while (col = mysql_fetch_field(res)) {
                    printf("%s  ", col->name);
                }

                 printf("\n\n");
                 while (row = mysql_fetch_row(res)){
                 printf("%s         %s                    %s           %s                       %s\n", row[0], row[1], row[2], row[3], row[4]);
                 }


            /* flash results */
            mysql_free_result(res);
            mysql_close(conn);

            return 0;

}

int Attemptassignment(char *p_code[4],char *a_id[4]){

    char *characters;
    char *expiry_date;
    char *attempt_status;
    char *activation_status;
    char *release_;

   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;


   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   conn = mysql_init(NULL);


    //static const char studentID[]="Clarance", password[]="123456";


    char *query_;
    int query_len;
    char *run_query;


    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("\nconnected to the database...\n");
   }

    query_ = "SELECT * FROM `assignments` WHERE `assignment_id`= '%s'";
    query_len = strlen(query_)+5;

    run_query = (char *) malloc(query_len);
    snprintf(run_query, query_len, "SELECT * FROM `assignments` WHERE `id`= '%s'",a_id);


       /* send SQL query */
       if (mysql_query(conn,run_query)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
       }else {
               res = mysql_use_result(conn);
               row = mysql_fetch_row(res);

               if ((row != NULL)){

                     characters = row[1];
                     expiry_date = row[2];
                     attempt_status =row[3];
                     activation_status = row[4];
                     //release_ = row[5];
                     //mysql_free_result(res);
                     //mysql_close(conn);

                     checkexpiry(a_id);

                     check_activation_status(a_id);

                     //check_release(a_id);

                     printf("\nStart the Attempt...\n");

                     printf("\nIn Assignment \"%s\" , Draw the following Characters:\n\n  %s\n\n",a_id,characters);

                     attempting(characters,p_code,a_id);

                     printf("\n\nCheers!!..Attempt Completed...\n\n");

               }else {
                     printf("\nNo assignment with that id!\n");
                     /* flash results */
                     mysql_free_result(res);
               }

               }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;


}

int checkexpiry(char *a_id[4]){

   MYSQL *conn;




   MYSQL_RES *res2;
   MYSQL_ROW row2;


   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   conn = mysql_init(NULL);


    //static const char studentID[]="Clarance", password[]="123456";
    char *query_2;
    int query_len2;
    char *run_query2;

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("\nassignment expiry check...\n");
   }


       query_2 = "SELECT * FROM `assignments` WHERE `assignment_id`= '%s' AND `expiry_date`>=CURRENT_DATE";

       query_len2 = strlen(query_2)+5;

       run_query2 = (char *) malloc(query_len2);
       snprintf(run_query2, query_len2, "SELECT * FROM `assignments` WHERE `id`= '%s' AND `expiry_date`>=CURRENT_DATE",a_id);

       if (mysql_query(conn,run_query2)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
       }else {
           res2 = mysql_use_result(conn);
           row2 = mysql_fetch_row(res2);

           if ((row2 != NULL)){
              printf("\nAssignment not yet expired!\n");
              mysql_free_result(res2);

           }else{
               printf("\nAssignment expired!\n");
               mysql_free_result(res2);
               exit(1);
           }
       }
  mysql_close(conn);
  return 0;
}

int check_activation_status(char *a_id[4]){

    MYSQL *conn;

   MYSQL_RES *res2;
   MYSQL_ROW row2;


   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   conn = mysql_init(NULL);


    //static const char studentID[]="Clarance", password[]="123456";
    char *query_2;
    int query_len2;
    char *run_query2;

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("\nactivation status check...\n");
   }


       query_2 = "SELECT * FROM `assignments` WHERE `id`= '%s' AND `activation_status`='activated'";

       query_len2 = strlen(query_2)+5;

       run_query2 = (char *) malloc(query_len2);
       snprintf(run_query2, query_len2, "SELECT * FROM `assignments` WHERE `id`= '%s' AND `activation_status`='activated'",a_id);

       if (mysql_query(conn,run_query2)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
       }else {
           res2 = mysql_use_result(conn);
           row2 = mysql_fetch_row(res2);

           if ((row2 != NULL)){
              printf("\nYour activated for this assignment!\n");
              mysql_free_result(res2);

           }else{
               printf("\nYour deactivated for this assignment!\n");
               mysql_free_result(res2);
               exit(1);
           }
       }
  mysql_close(conn);
  return 0;
}

int check_release(char *a_id[4]){

   MYSQL *conn;

   MYSQL_RES *res2;
   MYSQL_ROW row2;


   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   conn = mysql_init(NULL);


    //static const char studentID[]="Clarance", password[]="123456";
    char *query_2;
    int query_len2;
    char *run_query2;

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {
     printf("\nactivation status check...\n");
   }


       query_2 = "SELECT * FROM `assignments` WHERE `assignment_id`= '%s' AND `release_`='on'";

       query_len2 = strlen(query_2)+5;

       run_query2 = (char *) malloc(query_len2);
       snprintf(run_query2, query_len2, "SELECT * FROM `assignments` WHERE `id`= '%s' AND `release_`='on'",a_id);

       if (mysql_query(conn,run_query2)) {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
       }else {
           res2 = mysql_use_result(conn);
           row2 = mysql_fetch_row(res2);

           if ((row2 != NULL)){
              printf("\nThe assignment is released!\n");
              mysql_free_result(res2);

           }else{
               printf("\nThe assignment is not yet released!\n");
               mysql_free_result(res2);
               exit(1);
           }
       }
  mysql_close(conn);
  return 0;
}

int attempting(char *test,char *p_code[4],char *a_id[4]){

	//char test[2]={'L','L'};
    double char_score;
	int marks;
	double average_score=0.0;
	double time_taken;
	double total_score =0.0;

	char ltr[7][4],test_c;
    char ans[7][4]={
                    {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
    };
    clock_t start,stop;
    char mark='*';
    int i,j,choice;
    int char_num = 0;

    char letter;


    start=clock();
        //for(int k=0;k<2;k++){
    for (; *test; test++){
    char_num+=1;
    marks=0;
    char_score =0.0;
    letter=*test;
    i=0;
    printf("\n\nDraw letter %c\n",*test);
    printf("\n\nHere is, how letter %c must look like\n\n",*test);

    how_letter(letter);



    do{

        for(j=0;j<4;j++){
        printf("\nplease enter 1 to draw in box or 0 to skip box\n");
        printf("\nyou are drawing at row %d cell %d\n",i+1,j+1);
        scanf("%d",&choice);
        if(choice==1){
            ans[i][j]='*';
        }
        else{
            ans[i][j]=' ';
        }
        }
        i++;
    }while(i<7);

    printf("\n\nHere is the letter %c drawn by you\n\n",*test);

    your_drawing(ans);

    if(letter=='F'){
                char ltr[7][4]={
               {'*','*','*','*'},
               {'*',' ',' ',' '},
               {'*',' ',' ',' '},
               {'*','*','*','*'},
               {'*',' ',' ',' '},
               {'*',' ',' ',' '},
               {'*',' ',' ',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='B'){
                    char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='C'){
                    char ltr[7][4]={
                   {' ','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {' ','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='A'){
                    char ltr[7][4]={
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='D'){
                    char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='E'){
                    char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='G'){
                    char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='H'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='I'){
                    char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*','*','*','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {'*','*','*','*'},
                   {'*','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='J'){
                    char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*','*','*','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {'*','*','*',' '},
                   {'*','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='T'){
                    char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*','*','*','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='K'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ','*',' '},
                   {'*','*',' ',' '},
                   {'*',' ','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='X'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='Y'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

      }
      if(letter=='V'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='U'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='L'){
                    char ltr[7][4]={
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='M'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='N'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='O'){
                    char ltr[7][4]={
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='P'){
                    char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='R'){
                    char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

         for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='Q'){
                    char ltr[7][4]={
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*',' ','*'},
                   {' ','*','*',' '},
                   {' ',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='S'){
                    char ltr[7][4]={
                   {' ','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {' ','*','*',' '},
                   {' ',' ',' ','*'},
                   {' ',' ',' ','*'},
                   {'*','*','*',' '},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='W'){
                    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
    if(letter=='Z'){
                    char ltr[7][4]={
                   {'*','*','*','*'},
                   {' ',' ','*',' '},
                   {' ',' ',' ',' '},
                   {' ','*',' ',' '},
                   {' ',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},};

        for(i=0;i<7;i++){
            for(j=0;j<4;j++){
                if(ans[i][j]==ltr[i][j]){
                    marks+=1;
                }
            }
        }

        char_score = (marks/28.0)*100.0;
        total_score+=char_score;
        printf("your percentage character score is: %.2f ",char_score);

    }
 }
stop=clock();

average_score = (total_score/(double)char_num);
time_taken=(double)(stop-start)/1000;
printf("\n\nThe attempt took %f seconds\n",time_taken);
printf("\nThe average score %.2f\n\n",average_score);

update_attempt_status(a_id);

reg_performance(p_code,a_id,average_score,time_taken);

return 0;
}

void how_letter(char letter){

     char ltr[7][4];


     switch (letter)
     {
         case 'A':{

         //char ltr[7][4];

		 char ltr[7][4]={
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};
         your_drawing(ltr);

		}
            break;
         case 'B':{

        char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},};

            your_drawing(ltr);
	    }
            break;
         case 'C':{
		char ltr[7][4]={
                   {' ','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {' ','*','*','*'},};
         your_drawing(ltr);

	  }
            break;
         case 'D':{
		char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},};
        your_drawing(ltr);
	}
            break;
         case 'E':{
		  char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},};

          your_drawing(ltr);

	    }
            break;
         case 'F':{
		  char ltr[7][4]={
               {'*','*','*','*'},
               {'*',' ',' ',' '},
               {'*',' ',' ',' '},
               {'*','*','*','*'},
               {'*',' ',' ',' '},
               {'*',' ',' ',' '},
               {'*',' ',' ',' '},};
         your_drawing(ltr);
	    }
            break;
         case 'G':{
		char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},};
         your_drawing(ltr);
	    }
            break;
         case 'H':{
		char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};
          your_drawing(ltr);
	}
            break;
         case 'I':{
		  char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*','*','*','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {'*','*','*','*'},
                   {'*','*','*','*'},};
            your_drawing(ltr);
	   }
            break;
         case 'J':{
		   char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*','*','*','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {'*','*','*',' '},
                   {'*','*','*',' '},};

         your_drawing(ltr);
	   }
            break;
         case 'K':{
		   char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ','*',' '},
                   {'*','*',' ',' '},
                   {'*',' ','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

            your_drawing(ltr);

	   }
            break;
         case 'L':{
		   char ltr[7][4]={
                       {'*',' ',' ',' '},
                       {'*',' ',' ',' '},
                       {'*',' ',' ',' '},
                       {'*',' ',' ',' '},
                       {'*',' ',' ',' '},
                       {'*',' ',' ',' '},
                       {'*','*','*','*'},};
            your_drawing(ltr);

	       }
            break;
         case 'M':{
		   char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

           your_drawing(ltr);
	     }
            break;
         case 'N':{
		    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ','*','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

            your_drawing(ltr);

	      }
            break;
         case 'O':{
		  char ltr[7][4]={
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},};

            your_drawing(ltr);

	    }
            break;
         case 'P':{
		   char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},};

            your_drawing(ltr);

	    }
            break;
         case 'Q':{
		  char ltr[7][4]={
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*',' ','*'},
                   {' ','*','*',' '},
                   {' ',' ',' ','*'},};

            your_drawing(ltr);

	      }
            break;
         case 'R':{
		  char ltr[7][4]={
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};

            your_drawing(ltr);

	     }
            break;
         case 'S':{
		   char ltr[7][4]={
                   {' ','*','*','*'},
                   {'*',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {' ','*','*',' '},
                   {' ',' ',' ','*'},
                   {' ',' ',' ','*'},
                   {'*','*','*',' '},};

            your_drawing(ltr);

	     }
            break;
         case 'T':{
		   char ltr[7][4]={
                   {'*','*','*','*'},
                   {'*','*','*','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},};

            your_drawing(ltr);

	     }
            break;
         case 'U':{
		   char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},};

            your_drawing(ltr);
	       }
            break;
         case 'V':{
		    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},};

            your_drawing(ltr);

	     }
            break;
         case 'W':{
		   char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*','*','*','*'},
                   {'*',' ',' ','*'},};

            your_drawing(ltr);

	       }
            break;
         case 'X':{
		    char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},};


            your_drawing(ltr);

	     }
            break;
        case 'Y':{
		  char ltr[7][4]={
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {'*',' ',' ','*'},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},
                   {' ','*','*',' '},};

           your_drawing(ltr);
	      }
            break;
        case 'Z':{
		  char ltr[7][4]={
                   {'*','*','*','*'},
                   {' ',' ','*',' '},
                   {' ',' ',' ',' '},
                   {' ','*',' ',' '},
                   {' ',' ',' ',' '},
                   {'*',' ',' ',' '},
                   {'*','*','*','*'},};
            your_drawing(ltr);

	       }
            break;
        default:
            printf("poor letter format!");
            exit(1);
    }
    return;
}

void your_drawing(char ans[7][4]){

        printf("   %c|   %c|   %c|   %c\n",ans[0][0],ans[0][1],ans[0][2],ans[0][3]);
        printf("____|____|____|____\n");
        printf("   %c|   %c|   %c|   %c\n",ans[1][0],ans[1][1],ans[1][2],ans[1][3]);
        printf("____|____|____|____\n");
        printf("   %c|   %c|   %c|   %c\n",ans[2][0],ans[2][1],ans[2][2],ans[2][3]);
        printf("____|____|____|____\n");
        printf("   %c|   %c|   %c|   %c\n",ans[3][0],ans[3][1],ans[3][2],ans[3][3]);
        printf("____|____|____|____\n");
        printf("   %c|   %c|   %c|   %c\n",ans[4][0],ans[4][1],ans[4][2],ans[4][3]);
        printf("____|____|____|____\n");
        printf("   %c|   %c|   %c|   %c\n",ans[5][0],ans[5][1],ans[5][2],ans[5][3]);
        printf("____|____|____|____\n");
        printf("   %c|   %c|   %c|   %c\n",ans[6][0],ans[6][1],ans[6][2],ans[6][3]);

}

void update_attempt_status(char *a_id[4]){

   MYSQL *conn;
   conn = mysql_init(NULL);

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";


   char *query_,*run_query;
   int query_len;

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {

    printf("\n\nUpdating attempt_status...\n\n");

   }
    query_ = "UPDATE `assignments` SET `attempt_status` = 'attempted' WHERE id = '%s'";

    query_len = strlen(query_)+5;

    run_query = (char *) malloc(query_len);
    snprintf(run_query, query_len, "UPDATE `assignments` SET `attempt_status` = 'attempted' WHERE id = '%s'",a_id);

        if (mysql_query(conn,run_query )) {
                printf("Unable to connect with MySQL server\n");
                mysql_close(conn);
                return 1;
        }else{

           printf("\n\nattempt_status successfully updated...\n\n");

        }

    mysql_close(conn);

    return 0;

}
void reg_performance(char *p_code[4],char *a_id[4],double average_score,double time_taken){

   MYSQL *conn;

   conn = mysql_init(NULL);

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "kindercare";

   char *query_,*run_query;
   int query_len;

   char buff[1024];

   //printf("\n%.2f\n",average_score);
            //printf("\n%s\n",test);
           // printf("\n");

    /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      printf("can't initialize database connection..");
      exit(1);
   } else {

      printf("\n\nRegistering performance...\n\n");

   }
    //query_ = "INSERT INTO `attempt` (pupil_code, assignment_id, average_score, attempt_duration(seconds)) VALUES ('%s', '%s', %.2f, %.2f)";

    //query_len = strlen(query_)+ 25;

    //run_query = (char *) malloc(query_len);
    //snprintf(run_query, query_len, "INSERT INTO `attempt` (pupil_code, assignment_id, average_score, attempt_duration(seconds)) VALUES ('%s', '%s', %.2f, %.2f)",p_code,a_id,average_score,time_taken);


         /*char query_string[] = {
           "INSERT INTO attempt(pupil_code, assignment_id, average_score, attempt_duration(seconds)) VALUES('%s','%s','%.2f','%.2f')"
                              };*/

        snprintf(buff, sizeof buff, "INSERT INTO attempt(pupil_id, assignment_id, average_score, attempt_duration_in_seconds) VALUES('%s','%s',%.2f,%.2f);",p_code,a_id,average_score,time_taken);

        //sprintf(buf, query_string,p_code,a_id,average_score,time_taken);
        if (mysql_query(conn,buff))
        {
          fprintf(stderr, "%s\n", mysql_error(conn));
         // printf("\n%.2f\n",average_score);
         // printf("\n%.2f\n",time_taken);
          printf("\n");
        }else{
            printf("\n\nYour Performance is registered successfully...\n\n");
            //printf("\n%.2f\n",average_score);
              //printf("\n%s\n",test);
            //printf("\n");

            }


    /*
        //if (mysql_query(conn,run_query )) {
                printf("Unable to connect with MySQL server\n");
                mysql_close(conn);
                exit(1);
           // }else{

              printf("\n\nYour Performance is registered successfully...\n\n");
            }*/

    mysql_close(conn);

    return 0;

}



/*UPDATE Customers
SET ContactName = 'Alfred Schmidt', City = 'Frankfurt'
WHERE CustomerID = 1;


 char *p="abcd";
    for (; *p; p++)
        printf("%c\n", *p);
    return 0;

*/




                     //struct date dt;
                    // This function is used to get
                    // system's current date
                    //getdate(&dt);

                    //day_ = dt.da_day;
                    //month_ = dt.da_mon-dt;
                    //year_ = dt.da_year;



                    //printf("System's current date\n");
                    //printf("%d/%d/%d",
                         //  dt.da_day,
                         //  dt.da_mon,
                         //  dt.da_year);



/*
n_of_assignments = "SELECT count(*) FROM assignments";

if(mysql_query(mysql, "SELECT COUNT(*) FROM `login_client` WHERE `ID` < DATE(NOW() + INTERVAL 1 DAY)")){
        sqldebug(mysql);
    }

    /* store the results */
   /* MYSQL_RES *result = mysql_store_result(mysql);

    if(result == NULL){
        finish_with_error(mysql);
    }

    /* check the result has records ** don't really need this part */
   /* int num_fields = mysql_num_fields(result);
    if(num_fields<1){
        printf("no fields returned");
        exit(1);
    }

    /* row record */
   /* MYSQL_ROW row;

    if(row=mysql_fetch_row(result)){
       printf("Counted users %s\n", row[0]);
    }
    return;

    SELECT(
      SELECT COUNT(*)
	  FROM   employees
	  ) AS Total_Employees,
	  (SELECT COUNT(*)
	  FROM   departments
	  ) AS No_Of_Departments
FROM dual

"SELECT(SELECT COUNT(*) FROM assignments) AS Total_Assignments,
(SELECT COUNT(*) FROM assignments WHERE attempt_status ='attempted') AS Attempted,
(SELECT COUNT(*) FROM assignments WHERE attempt_status ='not_attempted')AS Not_Attempted,
(SELECT COUNT(*) FROM assignments WHERE attempt_status ='missed')As Missed"

SELECT COUNT(assignment_id)
FROM assignments;

SELECT COUNT( * ) as "Number of Rows"
FROM orders
WHERE ord_amount>1500;

WHERE `pupil_code`= 'pupil_code'

SELECT COUNT(*) AS Not_Attempted FROM assignments WHERE attempt_status ='not_attempted';

SELECT *
 FROM myTable
 WHERE CAST(ReadDate AS DATETIME) + ReadTime BETWEEN '2010-09-16 5:00PM' AND '2010-09-21 9:00AM'
 SELECT * FROM `dt_tb` WHERE dt BETWEEN '2005-01-01' AND '2005-12-31'

 #include <stdio.h>

int main()
{
    int dd, mm, yy;
    int date;

    printf("Enter date (dd/mm/yy) format: ");
    scanf("%d/%d/%d", &dd, &mm, &yy);

    printf("\nEntered date is: %02d/%02d/%04d\n", dd, mm, yy);

    /*adding dd,mm,yy into date*/
    /*an integer has 4 bytes and dd range is 1 to 31 , mm range is 1 to 12 which
     *can be stored in 1 byte, 1 byte and in rest of 2 bytes
     *we can store year.*/

   /* date = 0;
    date |= (dd & 0xff); /*dd storing in byte 0*/
    //date |= (mm & 0xff) << 8; /*mm storing in byte 1*/
    //date |= (yy & 0xffff) << 16; /*yy storing in byte 2 and 3*/

    //printf("Date in single variable: %d [Hex: %08X] \n", date, date);

    /*Extracting dd,mm,yy from date (an integer value)*/


   /*
    dd = (date & 0xff); /*dd from byte 0*/
   // mm = ((date >> 8) & 0xff); /*mm from byte 1*/
   // yy = ((date >> 16) & 0xffff); /*yy from byte 2 and 3*/

   // printf("Date after extracting: %02d/%02d/%04d\n", dd, mm, yy);

   // return 0;
//}
/*
Enter date (dd/mm/yy) format: 11/11/2011

    Entered date is: 11/11/2011
    Date in single variable: 131795723 [Hex: 07DB0B0B]
    Date after extracting: 11/11/2011

*/



