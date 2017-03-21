#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
int days_in_month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

char *ECtoGC_Converter(int,int,int);
int isLeapYear(int);
int isLeapYearGC(int);
char *GCtoEC_Converter(int,int,int);

int inputyear(void)
{
    int year;

    printf("Please enter a year (example: 1999) : ");
    scanf("%d", &year);
    return year;
}



int main()
{
    char *convertedDate;
    int day,month,year, daycode, leapyear;

    //year = inputyear();
    //daycode = determinedaycode(year);
    isLeapYearGC(year);
    //calendar(year, daycode);
    printf("\n");
    //printf("%d",isLeapYearGC(year));
    //convertedDate=ECtoGC_Converter(10,8,2008);
    printf("Enter day, month & year in EC:");
    scanf("%d%d%d",&day,&month,&year);
    convertedDate=ECtoGC_Converter(day,month,year);
    printf("\n");
    printf("Gregorian Calendar=%s",convertedDate);
    return 0;
}

int isLeapYear(int yearToBeChecked)
{
    int year;
    int initialYear=1987;
    yearToBeChecked = (yearToBeChecked * 1);
    for (year = initialYear; year <= yearToBeChecked; year += 4)
    {
        if (yearToBeChecked == year)
            return 1;
    }
    return 0;
}

int isLeapYearGC(int year)
{
    if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}


char *ECtoGC_Converter(int day,int month,int year)
{
    int cday, cmonth, cyear;
    int leapEffect = isLeapYear(year - 1);
    int gcLeapEffect;
    char *convertedDate;
    convertedDate=malloc(sizeof(char));
    //char forwardslash[1]="/";

    if (month == 0) //if Meskerem
    {
        cyear = year + 7;
        if (day <= (20 - leapEffect))
        {
            cmonth = month + 9; //sep
            cday = day + 10 + leapEffect;
        }
        else
        {
            cmonth = month + 10; //oct
            if (leapEffect == 1)
                cday = day - 19;
            else
                cday = day - 20;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        //convertedDate = cday + '/' + cmonth + '/' + cyear;
        return convertedDate;
    }
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 1) //if Tikimt
    {
        cyear = year + 7;
        if (day <= (21 - leapEffect))
        {
            cmonth = month + 9; //oct
            cday = day + 10 + leapEffect;
        }
        else
        {
            cmonth = month + 10; //nov
            if (leapEffect == 1)
                cday = day - 20;
            else
                cday = day - 21;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        //convertedDate = cday + '/' + cmonth + '/' + cyear;

        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 2) //if Hidar
    {
        cyear = year + 7;
        if (day <= (21 - leapEffect))
        {
            cmonth = month + 9; //nov
            cday = day + 9 + leapEffect;
        }
        else
        {
            cmonth = month + 10; //dec
            if (leapEffect == 1)
                cday = day - 20;
            else
                cday = day - 21;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 3) //if Tahissas
    {
        //cyear = year + 7;
        if (day <= (22 - leapEffect))
        {
            cyear = year + 7; //year is ready to switch
            cmonth = month + 9; //dec
            cday = day + 9 + leapEffect;
        }
        else
        {
            cyear = year + 8; //year is switched
            cmonth = month - 2;  //JAN /*HAPPY NEW YEAR*/
            if (leapEffect == 1)
                cday = day - 21;
            else
                cday = day - 22;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 4) //if Thir
    {
        cyear = year + 8;
        if (day <= (23 - leapEffect))
        {
            cmonth = month - 3; //jan
            cday = day + 8 + leapEffect;
        }
        else
        {
            cmonth = month - 2; //feb /*April the fool*/
            if (leapEffect == 1)
                cday = day - 22;
            else
                cday = day - 23;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 5) //if Yekatit
    {
        cyear = year + 8;
        gcLeapEffect = isLeapYearGC(cyear);
        if (day <= ((21 + gcLeapEffect) - leapEffect))
        {
            cmonth = month - 3; //feb
            cday = day + 7 + leapEffect;
        }
        else
        {
            cmonth = month - 2; //mar
            if (leapEffect == 1)
                cday = day - (20 + gcLeapEffect);
            else
                cday = day - (21 + gcLeapEffect);
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 6) //if Megabit
    {
        cyear = year + 8;
        if (day <= 22)
        {
            cmonth = month - 3;  //mar
            cday = day + 9;
        }
        else
        {
            cmonth = month - 2;  //apr
            cday = day - 22;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 7) //if Miyazia
    {
        cyear = year + 8;
        if (day <= 22)
        {
            cmonth = month - 3;  //apr
            cday = day + 8;
        }
        else
        {
            cmonth = month - 2;  //may
            cday = day - 22;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 8) //if Ginbot
    {
        cyear = year + 8;
        if (day <= 23)
        {
            cmonth = month - 3;  //may
            cday = day + 8;
        }
        else
        {
            cmonth = month - 2;  //jun
            cday = day - 23;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 9) //if Sene
    {
        cyear = year + 8;
        if (day <= 23)
        {
            cmonth = month - 3;  //jun
            cday = day + 7;
        }
        else
        {
            cmonth = month - 2;  //jul
            cday = day - 23;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 10) //if Hamle
    {
        cyear = year + 8;
        if (day <= 24)
        {
            cmonth = month - 3;  //jul
            cday = day + 7;
        }
        else
        {
            cmonth = month - 2;  //aug
            cday = day - 24;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 11) //if Nehasse
    {
        cyear = year + 8;
        if (day <= 25)
        {

            cmonth = month - 3;  //aug
            cday = day + 6;
        }
        else
        {
            //cyear = year + 7;
            cmonth = month - 2;  //sep
            cday = day - 25;
        }
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (month == 12) //if Puagme /*Ethiopian's alone month*/
    {
        cyear = year + 8;
        cmonth = month - 3;  //sep
        cday = day + 5;
        //alert(cday + "/" + cmonth + "/" + cyear);
        //convertedDate = cday + "/" + cmonth + "/" + cyear;
        sprintf(convertedDate, "%d%s%d%s%d", cday,"/",cmonth, "/",cyear);
        return convertedDate;
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

}


