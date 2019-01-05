#include <stdio.h>
#include <string.h>
struct krmnd
{
	int num,sn,sk;
	char nm[100],*nmp;
	long int cd,hu;
};
struct krmnd kr[10000000];
int menu(int tdf,int chnf,int ckrf);
info(int cn);
brmv(int cn,int tv);
pac();
main()
{
	printf("		alifo	     alifo	     alifoalifoalifo\n	     alifoalifo	     alifo	     alifoalifoalifo\n	   alifoalifoalifo   alifo		  alifo\n	alifoalifoalifoalifo alifo		  alifo\n	alifo          alifo alifo		  alifo \n	alifo          alifo alifo		  alifo\n	alifoalifoalifoalifo alifo		  alifo\n	alifoalifoalifoalifo alifo		  alifo\n	alifo          alifo alifo		  alifo\n	alifo          alifo alifoalifoalifo alifoalifoalifo\n	alifo          alifo alifoalifoalifo alifoalifoalifo");
	printf("\n\n\n\n\n				Loading...");
	while(clock()<2000)
	;
	system("cls");
	printf("Welcome to Financial institution Database Program!by Alifo\n");
	int vd,td=0,cr,lp,ay=0,chn=0,ckr=0;
	char dy[3],*dyp;
	dyp=dy;
	printf("Do you want to load informations from database file?");
	scanf(" %s",dyp);
	system("cls");
	if(strcmp(dyp,"yes")==0)
	{
		ckr=0;
		FILE *fp;
		struct krmnd brkr;
		fp=fopen("database.dat","r");
		while(fread(&brkr, sizeof(struct krmnd), 1, fp))
		{
			kr[ckr]=brkr;
			ckr++;
		}
		if(ckr==0)
		{
			printf("Data dosen't found!\n");
			pac();
		}
		else if(kr[0].nm!=NULL)
		{
			printf("Informations loaded successfuly\n");
			ay=1;
			ckr-=1;
			pac();
		}
		else
		{
			printf("Error during file loading");
			pac();
		}
		td=ckr;
	}
	for(lp=0;;lp++)
	{
		vd=menu(td,chn,ckr);
		if(vd==1)
		{
			char am[3],*amp;
			amp=am;
			if(td!=0)
			{
				printf("Do you want to overwrite new information:");
				scanf(" %s",amp);
				system("cls");
				if(strcmp(amp,"no")==0)
				{
					
				}
			}
			if(td==0||strcmp(amp,"yes")==0)
			{
				printf("Enter number of employees:");
				scanf("%d",&chn);
				system("cls");
				for(cr=0;cr<chn;cr++)
				{
					printf("%d of %d employees\n",cr+1,chn);
					info(cr);		
				}
				td+=chn;
				ay=1;
				if(td>0)
				{
					printf("information saved for %d employees\n",chn);
					pac();
				}
			}
		}
		if(vd==2)
		{
			int ch1,ch2,sh,shb,to,ycd;
			if(ay==0)
			{
				printf("Please Enter employees information first!\n");
				pac();
			}
			else
			{
			int ch0;
			printf("Do you want modification or remove?\n[1] Modification\n[2] Remove\n[0] Menu\nEnter number:");
			scanf("%d",&ch0);
			system("cls");
			if(ch0==1)
			{
				printf("Select a choice:\n[1] Modificate by name\n[2] Single modification\n[3] Range modification\n[4] Modificate all\n[0] Menu\nEnter number:");
				scanf("%d",&ch1);
				system("cls");
				if(ch1==1)
				{
					int	shm=0,ctd;
					char kdd[100],*kdn;
					kdn=kdd;
					printf("Which employee you want to modificate:");
					scanf(" %s",kdn);
					system("cls");
					for(ctd=0;ctd<td;ctd++)
					{
						if(strcmp(kdn,kr[ctd].nm)==0)
						{
							info(ctd);
							shm++;
						}
						pac();
					}
					if(shm==0)
					{
						puts("Emplyee not found");
						pac();
					}
				}
				if(ch1==2)
				{
					printf("Enter employee Number:");
					scanf("%d",&sh);
					system("cls");
					if(sh<1||sh>td)
					{
						printf("You must enter a number between 1~%d",td);
						pac();
					}
					else
					{
						info(sh-1);
						printf("Changes saved successfully");
					}
				}
				if(ch1==3)
				{
					printf("Enter range of %d\nFrom:",td);
					scanf("%d",&sh);
					printf("To:");
					scanf("%d",&to);
					system("cls");
					if(to>td||sh<1||sh>td)
					{
						printf("You must enter a number between 1~%d & your first number must be smaller than your second number",td);
						pac();
					}
					else
					{
						for(ycd=sh-1;ycd<to;ycd++)
						{
							printf(" %d of %d employees\n",ycd+1,td);
							info(ycd);
						}
						printf("Changes saved successfully");
					}
				}
				if(ch1==4)
				{
					for(ycd=0;ycd<td;ycd++)
					{
						printf(" %d of %d employees\n",ycd+1,td);
						info(ycd);
					}
					printf("Changes saved successfully");
				}
			}
			if(ch0==2)
			{
				printf("Select a choice:\n[1] Remove by name\n[2] Single Remove\n[3] Range Remove\n[4] Remove all\n[0] Menu\nEnter number:");
				scanf("%d",&ch2);
				system("cls");
				if(ch2==1)
				{
					int	sre=0,cts,cb;
					char kds[100],*kdo;
					kdo=kds;
					printf("Which employee you want to remove:");
					scanf(" %s",kdo);
					system("cls");
					for(cts=0;cts<td;cts++)
					{
						if(strcmp(kdo,kr[cts].nm)==0)
						{
							for(cb=cts;cb<td;cb++)
							{
							brmv(cb,1);
							}
							if(cts<ckr)
							ckr--;
							else
							chn--;
							td--;
							if(cts<td)
							printf("Information removed successfully and every employee number after %d are come 1 number back\n",ycd);
							if(cts=td)
							printf("Information removed successfully\n");						
							pac();
							sre++;
						}
						pac();
					}
					if(sre==0)
					{
						puts("Emplyee not found");
						pac();
					}
				}		
				if(ch2==2)
				{
					printf("Enter employee number:");
					scanf("%d",&sh);
					system("cls");
					if(sh<1||sh>td)
					{
						printf("You must enter a number between 1~%d",td);
						pac();
					}
					else
					{
						for(ycd=sh-1;ycd<td;ycd++)
						brmv(ycd,1);
						if(sh-1<ckr)
						ckr--;
						else
						chn--;
						td--;
						if(sh<td)
						printf("Information removed successfully and every employee number after %d are come 1 number back\n",ycd);
						if(sh=td)
						printf("Information removed successfully\n");						
						pac();
					}
				}
				if(ch2==3)
				{
					int tf;
					printf("Enter range of %d\nFrom:",td);
					scanf("%d",&shb);
					printf("To:");
					scanf("%d",&to);
					system("cls");
					if(to>td||shb<1||to<=shb)
					{
						printf("You must enter numbers between 1~%d & your first number must be smaller than your second number",td);
						pac();
					}
					else
					{
						tf=to-shb+1;
						for(ycd=shb-1;ycd<=to;ycd++)
						brmv(ycd,tf);
						if(shb-1<=ckr , to-1<ckr)
						ckr-=tf;
						if(shb-1>=ckr , to-1>=ckr)
						chn-=tf;
						if(shb-1<=ckr , to-1>=ckr)
						{
							chn=to-ckr;
							ckr=shb-1;
						}

						if(to<td)
						printf("Information removed successfully and every employee number after %d are come %d number back\n",ycd,tf);
						if(to==td)
						printf("Information removed successfully\n");
						td-=tf;
						pac();
					}
				}
				if(ch2==4)
				{
					for(ycd=0;ycd<td;ycd++)
					{
						strcpy(kr[ycd].nm,"");
						kr[ycd].sn=NULL;
						kr[ycd].sk=NULL;
						kr[ycd].cd=NULL;
						td=0;
					}
					printf("Information removed successfully\n");
					pac();
				}
			}
			}
		}
		if(vd==3)
		{
			if(ay==0)
			{
				printf("Please Enter employees information first!\n");
				pac();
			}
			else
			{
				int sd,co,ci,mi;
				printf("Select a choise:\n[1] By work exprience\n[2] By name\n[0] Menu\nEnter number:");
				scanf("%d",&sd);
				system("cls");
				struct krmnd ma,sw;
				if(sd==1)
				{
					for (co=0;co<td;co++)
					{
						ma=kr[td-1];
						for (ci=co;ci<td;ci++)
						{
							if (kr[ci].sk>=ma.sk)
							{
								ma=kr[ci];
								mi=ci;
							}
						}
						sw=kr[co];
						kr[co]=ma;
						kr[mi]=sw;
					}
					if (kr[td-1].sk>kr[td-2].sk)
					{
						sw=kr[td-2];
						kr[td-2]=kr[td-1];
						kr[td-1]=sw;
					}
					printf("Sorting by work exprience was successful\n");
					pac();
				}	
				if(sd==2)
				{
					for(co=0;co<td;co++)
					{
						ma=kr[co];
						for(ci=co;ci<td;ci++)
						{
							if(strcmp(kr[ci].nm,ma.nm)<=0)
							{
								ma=kr[ci];
								mi=ci;
							}
						}
						sw=kr[co];
						kr[co]=ma;
						kr[mi]=sw;
					}
					printf("Sorting by name was successful\n");
					pac();
				}
			}
		}
		if(vd==4)
		{
			if(ay==0)
			{
				printf("Please Enter employees information first!\n");
				pac();	
			}
			else
			{
				int ct,shd=0,chj;
				printf("Select a choise:\n[1] Show by name\n[2] Show all\n[0] Menu\nEnter number:");
				scanf("%d",&chj);
				system("cls");
				if(chj==1)
				{
					char kd[100],*kdp;
					kdp=kd;
					printf("Which employee you want to shown:");
					scanf(" %s",kdp);
					system("cls");
					for(ct=0;ct<td;ct++)
					{
						if(strcmp(kdp,kr[ct].nm)==0)
						{
							printf("Name:                ");
							puts(kr[ct].nmp);
							printf("Civilization code:   %d\nAge:                 %d years\nWork exprience:      %d years\nSalary:              %d toman\n",kr[ct].cd,kr[ct].sn,kr[ct].sk,kr[ct].hu);
							if(kdp<ckr)
							printf("(File)\n");
							else
							printf("(Temporiraly)\n");
							shd++;
						}
						pac();
					}
					if(shd==0)
					{
						printf("Emplyee not found");
						pac();
					}
				}
				if(chj==2)
				{
					for(ct=0;ct<td;ct++)
					{
						printf("Employee %d of %d\nName:                ",ct+1,td);
						puts(kr[ct].nmp);
						printf("Civilization code:   %d\nAge:                 %d years\nWork exprience:      %d years\nSalary:              %d toman\n",kr[ct].cd,kr[ct].sn,kr[ct].sk,kr[ct].hu);
						if(ct<ckr)
						printf("(File)\n");
						else
						printf("(Temporiraly)\n");
						if(td>1)
						printf("------------------------------------------\n");
					}
					pac();
				}	
			}
		}
		if(vd==5)
		{
			if(ay==0)
			{
				printf("Please Enter employees information first!\n");
				pac();
			}
			else
			{
				int cu,scu=0,chnt;
				printf("How many employee you want to add:");
				scanf("%d",&chnt);
				chn+=chnt;
				system("cls");
				for(cu=td;cu<td+chnt;cu++)
				{
					printf("%d(%d) of %d employees\n",cu+1,scu+1,td+chnt);
					info(cu);
					scu++;
				}
				td+=chnt;
				if(chnt>0)
				printf("Information saved for %d employees\n",chnt);
				pac();
			}
		}
		if(vd==6)
		break;
	}
	if(chn>0)
	{
		char af[3],*afp;
		afp=af;
		printf("Do you want to save information in file:");
		scanf(" %s",afp);
		if(strcmp(afp,"yes")==0)
		{
			struct krmnd ts;
			FILE *fp;
			fp=fopen("database.dat","w+");
			fwrite(kr, sizeof(struct krmnd), td, fp);
			fread(&ts, sizeof(struct krmnd), 1, fp);
			if(ts.nm!=NULL)
			{
				printf("Information saved successfuly\n");
				pac();
			}
			else
			{
				printf("Error during writing");
				pac();
			}
			fclose(fp);
		}
	}
}
int menu(int tdf,int chnf,int ckrf)
{
	int kh;
	printf("What can I do for you?\n[1] Save employees information\n[2] Modification or remove employee information\n[3] Sort information by name or work experience\n[4] Show an employee information\n[5] Add new employees\n[6] Exit\n");
	if(tdf>0)
	printf("%d employee found(%d temporarily & %d in file)\n",tdf,chnf,ckrf);
	if(tdf==0)
	printf("Any employee information dosen't found!\n");
	printf("Enter number:");
	scanf("%d",&kh);
	system("cls");
	return kh;
}
info(int cn)
{
		int sbk=0;
		kr[cn].num=cn;
		kr[cn].nmp=kr[cn].nm;
		printf("Enter name:");
		scanf("%s",kr[cn].nmp);
		printf("Enter civilization code:");
		scanf("%d",&kr[cn].cd);
		while(kr[cn].cd>10000000000)
		{
			printf("Civilization code must has 10-digits\n");
			printf("Enter civilization code again:");
			scanf("%d",&kr[cn].cd);
		}
		printf("Enter age:");
		scanf("%d",&kr[cn].sn);
		while(kr[cn].sn<18||kr[cn].sn>80)
		{
			printf("You must fire this employee! Age must be between 18~80\n");
			printf("Enter age again:");
			scanf("%d",&kr[cn].sn);		
		}
		printf("Enter work exprience:");
		scanf("%d",&kr[cn].sk);
		while(kr[cn].sk+18>kr[cn].sn)
		{
			printf("Employee must had 18 years old when he/she starts to work\n");
			printf("Enter work exprience again:");
			scanf("%d",&kr[cn].sk);
		}
		while(kr[cn].sk>25)
		{
			printf("This employee must be retired!work exprience maximum is 25 years\n");
			printf("Enter work exprience again:");
			scanf("%d",&kr[cn].sk);
		}
		sbk=kr[cn].sk;
		kr[cn].hu=(sbk*50000)+500000;
		system("cls");
}
brmv(int cn,int tv)
{
	strcpy(kr[cn].nm,kr[cn+tv].nm);
	kr[cn].num=kr[cn+tv].num;
	kr[cn].sn=kr[cn+tv].sn;
	kr[cn].sk=kr[cn+tv].sk;
	kr[cn].cd=kr[cn+tv].cd;
}
pac()
{
	system("pause");
	system("cls");
}
