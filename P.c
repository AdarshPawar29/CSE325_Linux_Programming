 //Paging Algorithms using C language OS problem
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
 # define maxn 50  
 typedef struct  page  
 {  
   int frame ;  
   int count[maxn],curr[maxn] ;  
 }page ;  
 struct page p ;  
 void fifo(int pages,int page[]) ;  
 void lru(int pages ,int page[]) ;  
 void optimal(int pages,int page[]) ;  
 void main()  
 {  
  int ch=0,pages=0,i,j,page[maxn],frames=0,temp3,temp4 ;  
  char temp ;  
  clrscr() ;  
  do  
  {  
    printf("\t\t\t****main menu****\n") ;  
    printf("\t\t\t1.enter the page information\n");  
    printf("\t\t\t2.dispaly page info\n");  
    printf("\t\t\t3.fifo\n" );  
    printf("\t\t\t4.lru\n") ;  
    printf("\t\t\t5.optimal\n") ;  
    printf("\t\t\t6.exit\n");  
    printf("\t\t\tenter ur choice\n");  
   scanf("%d",&ch);  
   switch (ch)  
   {  
    case 1:  
      clrscr();  
      printf("enter the no of pages\n");  
      scanf("%d",&pages) ;  
      printf("enter pages\n");  
      for(i=0;i<pages;i++) <br="">      
      {  
       printf("page %d\n",i);  
       scanf("%d",&page[i]) ;  
      }  
      printf("enter number of frames .....\n");  
      scanf("%d",&p.frame) ;  
      break ;  
    case 2:  
      printf("no of pages%d\n",pages);  
       printf("page sequence \n");  
       for(i=0;i<pages;i++) <br="">       
       {  
       printf("page %d\n",page[i]);  
       }  
       printf("no of frames/%d",p.frame);  
      break ;  
    case 3:  
       fifo(pages,page) ;  
       break ;  
    case 4:  
       lru(pages ,page);  
      break ;  
    case 5:  
        optimal(pages ,page);  
      break ;  
    case 6:  
      break ;  
   }  
 }
 while(ch!=6 );  
 }  
 void fifo(int pages,int page[])  
 {  
  int i,j,k,flag=0,temp=0,fault=0 ;  
  for(i=0;i<p.frame;i++) <br="">
 
  {  
     p.curr[i]=-1 ;  
     p.count[i]=100 ;  
     printf("\tpage%d",i+1) ;  
  }  
  printf("\tfault\n\n");  
  for(i=0;i<pages;i++) <br="">  
  {  
     flag=0 ;  
     temp=0 ;  
     for(j=0;j<p.frame;j++) <br="">
 
     {  
           if(p.curr[j]==page[i])  
           {  
             flag=1 ;  
             break ;  
           }  
           if(temp<p.count[j]) <br="">
 
           {  
               temp=p.count[j] ;  
               k=j ;  
           }  
     }  
     for(j=0;j<p.frame;j++) <br="">
 
     {  
         if(flag==0 && k==j)  
         {  
           p.curr[j]=page[i] ;  
           p.count[j]=1 ;  
           fault++ ;  
         }  
         else  
         if(j<fault) <br="">         p.count[j]++;  
         if(p.curr[j]!=-1)  
         printf("\t%d",p.curr[j]) ;  
     }  
     if(flag==0)  
     printf("\t\t\t*") ;  
     printf("\n") ;  
  }  
  printf("no of page fault%d",fault);  
 }  
 void lru(int pages ,int page[])  
 {  
  int i,j,k,flag=0,temp=0,fault=0 ;  
  for(i=0;i<p.frame;i++) <br="">
 
  {  
     p.curr[i]=-1 ;  
     p.count[i]=100 ;  
     printf("\tpage%d",i+1) ;  
  }  
  printf("\tfault\n\n");  
  for(i=0;i<pages;i++) <br="">  {  
     flag=0 ;  
     temp=0 ;  
     for(j=0;j<p.frame;j++) <br="">
 
     {  
           if(p.curr[j]==page[i])  
           {  
             flag=1 ;  
             p.count[j]=0 ;  
             break ;  
           }  
           if(temp<p.count[j]) <br="">
 
           {  
               temp=p.count[j] ;  
               k=j ;  
           }  
     }  
     for(j=0;j<p.frame;j++) <br="">
 
     {  
         if(flag==0 && k==j)  
         {  
           p.curr[j]=page[i] ;  
           p.count[j]=1 ;  
           fault++ ;  
         }  
         else  
         if(j<fault) <br="">         p.count[j]++;  
         if(p.curr[j]!=-1)  
         printf("\t%d",p.curr[j]) ;  
     }  
     if(flag==0)  
     printf("\t\t\t*") ;  
     printf("\n") ;  
  }  
  printf("no of page fault%d",fault);  
 }  
 void optimal(int pages,int page[])  
 {  
  int i,j,k,flag=0,temp=0,fault=0,s ;  
  for(i=0;i<p.frame;i++) <br="">
 
  {  
     p.curr[i]=-1 ;  
     p.count[i]=100 ;  
     printf("\tpage%d",i+1) ;  
  }  
  printf("\tfault\n\n");  
  for(i=0;i<pages;i++) <br="">  {  
     flag=0 ;  
     temp=0 ;  
     for(j=0;j<p.frame;j++) <br="">
 
     {  
           if(p.curr[j]==page[i])  
           {  
             flag=1 ;  
             p.count[j]=0 ;  
             break ;  
           }  
           if(temp<p.count[j]) <br="">
 
           {  
               temp=p.count[j] ;  
               k=j ;  
           }  
     }  
     for(j=0;j<p.frame;j++) <br="">
 
     {  
         if(flag==0 && k==j)  
         {  
           p.curr[j]=page[i] ;  
           p.count[j]=0 ;  
           fault++ ;  
         }  
         else  
         if(j<fault) <br="">         
         {  
           p.count[j]=0 ;  
           for(s=i+1;s<pages;s++) <br="">           
           {  
             if(page[i]==p.curr[j])  
             break ;  
             else  
             p.count[j]++ ;  
           }  
         }  
         p.count[j]++;  
         if(p.curr[j]!=-1)  
         printf("\t%d",p.curr[j]) ;  
     }  
     if(flag==0)  
     printf("\t\t\t*") ;  
     printf("\n") ;  
  }  
  printf("no of page fault%d",fault);  
 }