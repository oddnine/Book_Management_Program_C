//control.c
#include "std.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define DATAMAX	100

book g_booklist[DATAMAX];

int count = 0;

void savelist() {
    FILE* fp = fopen("list.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %d %d %d %s %s %s %s %s %s %d %d\n", g_booklist[i].classfirst, g_booklist[i].classsecond,g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, g_booklist[i].flag1, g_booklist[i].flag);
        
    }
    fclose(fp);
}

void readlist() {
    FILE* in = fopen("list.txt", "r");
    int ccount = 0;
    fscanf(in, "\n");
    while (!feof(in)) {
        fscanf(in, "%s %s %d %d %d %s %s %s %s %s %s %d %d\n", g_booklist[ccount].classfirst, g_booklist[ccount].classsecond, &g_booklist[ccount].classnum1, &g_booklist[ccount].classnum2, &g_booklist[ccount].classnum3, g_booklist[ccount].classpub, g_booklist[ccount].classauth, g_booklist[ccount].classname, g_booklist[ccount].name, g_booklist[ccount].auth, g_booklist[ccount].pub, &g_booklist[ccount].flag1, &g_booklist[ccount].flag);
        ccount++;
    }
    
    count = ccount;
    fclose(in);
    return;
}

int random() {
    srand(time(NULL));
    int i = rand() % 100000;

    return i;
}

void Swap(book* arr, int a, int b)
{
    book temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void Sort(book* arr, int m, int n)
{
        
        if (m < n) // 오름차순
        {
            int key = m;
            int i = m + 1;
            int j = n;
            while (i <= j)
            {
                while (i <= n && arr[i].classnum1 <= arr[key].classnum1)
                    i++;
                while (j > m && arr[j].classnum1 >= arr[key].classnum1)
                    j--;
                if (i > j)
                    Swap(arr, j, key);
                else
                    Swap(arr, i, j);
            }
            Sort(arr, m, j - 1);
            Sort(arr, j + 1, n);
        }
}

void con_printall()
{
    system("cls");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                                  도서 목록                                  │\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
   
    for (int i = 0; i <= count; i++)
    {
        char gar[10]; //대출가능여부
        if (g_booklist[i].flag1 == 1) {
            strcpy_s(gar, sizeof(gar), "가  능");
        }
        else {
            strcpy_s(gar, sizeof(gar), "불가능");
        }
        if (g_booklist[i].flag == 1) {
            printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
            printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3,g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
            printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
        }
        printf("│                                                                             │\n");
    }
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("[1] 대분류번호 오름차순 정렬 \n");
    printf("[2] 메뉴 \n");
    char sel = _getch();
    if (sel == '1') {
        Sort(g_booklist, 0, count - 1);
        con_printall();
    }
    else {
        return;
    }
}

void con_printall1()
{
    system("cls");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");

    for (int i = 0; i <= count; i++)
    {
        char gar[10]; //대출가능여부
        if (g_booklist[i].flag1 == 1) {
            strcpy_s(gar, sizeof(gar), "가  능");
        }
        else {
            strcpy_s(gar, sizeof(gar), "불가능");
        }
        if (g_booklist[i].flag == 1) {
            printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
            printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
            printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
        }
        printf("│                                                                             │\n");
    }
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
}

void con_insert()
{

    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    char ch = menuprint2();
    switch (ch)
    {
    case '0':	con_insert0(ch); 		break;
    case '1':	con_insert1(ch); 		break;
    case '2':	con_insert2(ch);		break;
    case '3':	con_insert3(ch);		break;
    case '4':	con_insert4(ch);		break;
    case '5':	con_insert5(ch);		break;
    case '6':	con_insert6(ch);		break;
    case '7':	con_insert7(ch); 		break;
    case '8':	con_insert8(ch); 		break;
    case '9':	con_insert9(ch); 		break;
    case 'x':		break;
    }
}


char menuprint2() {
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│            총류(000~099): 0번           │\n");
    printf("\t\t\t\t│            철학(100~199): 1번           │\n");
    printf("\t\t\t\t│            종교(200~299): 2번           │\n");
    printf("\t\t\t\t│            사회과학(300~399): 3번       │\n");
    printf("\t\t\t\t│            자연과학(400~499): 4번       │\n");
    printf("\t\t\t\t│            기술과학(500~599): 5번       │\n");
    printf("\t\t\t\t│            예술(600~699): 6번           │\n");
    printf("\t\t\t\t│            언어(700~799): 7번           │\n");
    printf("\t\t\t\t│            문학(800~899): 8번           │\n");
    printf("\t\t\t\t│            역사(900~999): 9번           │\n");
    printf("\t\t\t\t│            돌아가기: x키                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    char ch = _getch();
    return ch;
}

void con_insert0(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t도서학, 서지학(000) \t\t  │\n");
    printf("\t\t\t\t│\t문헌정보학(010) \t\t  │\n");
    printf("\t\t\t\t│\t백과사전(020) \t\t\t  │\n");
    printf("\t\t\t\t│\t강연집,수필집,연설문집(030)       │\n");
    printf("\t\t\t\t│\t일반연속간행물(040) \t\t  │\n");
    printf("\t\t\t\t│\t학회,단체,협회,기관,연구기관(050) │ \n");
    printf("\t\t\t\t│\t신문,저널리즘(060)\t \t  │\n");
    printf("\t\t\t\t│\t일번 전집, 총서(070)\t\t  │\n");
    printf("\t\t\t\t│\t향토자료(080)  \t\t\t  │\n");
    printf("\t\t\t\t│\t역사(090)\t\t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 0;
    getchar();
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "총류");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "도서서지");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "문헌정보");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "백과사전");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "강수연집");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "일반연속");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "학단협기");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "신문저널");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "전집총서");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "향토자료");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "역사");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert1(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t철학(100)\t\t\t  │\n");
    printf("\t\t\t\t│\t형이상학(110)\t\t\t  │\n");
    printf("\t\t\t\t│\t인식론(120)\t\t\t  │\n");
    printf("\t\t\t\t│\t초심리학,신비주의(130)\t\t  │\n");
    printf("\t\t\t\t│\t철학파(140)\t\t\t  │\n");
    printf("\t\t\t\t│\t심리학(150)\t\t\t  │ \n");
    printf("\t\t\t\t│\t논리학(160\t\t\t  │\n");
    printf("\t\t\t\t│\t윤리학(170)\t\t\t  │\n");
    printf("\t\t\t\t│\t고대 철학,중세 철학, 동양철학(180)│\n");
    printf("\t\t\t\t│\t현대 서양철학(190) \t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 1;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "철학");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "철학");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "형이상학");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "인식론");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "심리신비");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "철학파");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "심리학");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "논리학");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "윤리학");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "고중동철");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "현서철학");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert2(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t종교(200) \t\t\t  │\n");
    printf("\t\t\t\t│\t종교의 철학 및 이론(210)\t  │\n");
    printf("\t\t\t\t│\t성경(220) \t\t\t  │\n");
    printf("\t\t\t\t│\t교리신학집(230)\t\t\t  │\n");
    printf("\t\t\t\t│\t그리스도교 윤리(240) \t\t  │\n");
    printf("\t\t\t\t│\t지역교회(250)\t\t\t  │ \n");
    printf("\t\t\t\t│\t그리스도교 사회신학(260)\t  │\n");
    printf("\t\t\t\t│\t그리스도교 교회사(270)\t\t  │\n");
    printf("\t\t\t\t│\t그리스도교 교파(280)  \t\t  │\n");
    printf("\t\t\t\t│\t기타 종교(290) \t\t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 2;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "종교");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "종교");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "종철및이");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "성경");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "교리신학");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "그리윤리");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "지역교회");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "그리사신");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "그리교회");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "그리교파");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "기타종교");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert3(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t사회과학(300)\t\t\t  │\n");
    printf("\t\t\t\t│\t통계(310) \t\t\t  │\n");
    printf("\t\t\t\t│\t정치학(320) \t\t\t  │\n");
    printf("\t\t\t\t│\t경계학(330) \t\t\t  │\n");
    printf("\t\t\t\t│\t법률(340) \t\t\t  │\n");
    printf("\t\t\t\t│\t행정학,군사학(350) \t\t  │ \n");
    printf("\t\t\t\t│\t사회문제,사회복지(360)\t\t  │\n");
    printf("\t\t\t\t│\t교육학(370) \t\t\t  │\n");
    printf("\t\t\t\t│\t상업,통신,교통(380) \t\t  │\n");
    printf("\t\t\t\t│\t풍속,민속학(390)\t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 3;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "사과");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "사회과학");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "통계");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "정치학");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "경계학");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "법률");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "행정군사");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "사회문복");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "교육학");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "상통교통");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "풍속민속");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert4(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t자연과학(400) \t\t\t  │\n");
    printf("\t\t\t\t│\t수학(410) \t\t\t  │\n");
    printf("\t\t\t\t│\t천문학(420) \t\t\t  │\n");
    printf("\t\t\t\t│\t물리학(430) \t\t\t  │\n");
    printf("\t\t\t\t│\t화학(440)  \t\t\t  │ \n");
    printf("\t\t\t\t│\t지구과학(450)\t\t\t  │ \n");
    printf("\t\t\t\t│\t고생물학(460) \t\t\t  │\n");
    printf("\t\t\t\t│\t생물학(470) \t\t\t  │\n");
    printf("\t\t\t\t│\t식물학(480) \t\t\t  │\n");
    printf("\t\t\t\t│\t동물학(490) \t\t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 4;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "자과");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "자연과학");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "수학");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "천문학");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "물리학");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "화학");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "지구과학");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "고생물학");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "생물학");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "식물학");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "동물학");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert5(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t기술과학(500) \t\t\t  │\n");
    printf("\t\t\t\t│\t의학(510) \t\t\t  │\n");
    printf("\t\t\t\t│\t공학(520) \t\t\t  │\n");
    printf("\t\t\t\t│\t농학(530) \t\t\t  │\n");
    printf("\t\t\t\t│\t가정학(540)  \t\t\t  │ \n");
    printf("\t\t\t\t│\t경영학(550)\t\t\t  │ \n");
    printf("\t\t\t\t│\t화학공학(560) \t\t\t  │\n");
    printf("\t\t\t\t│\t제조업(570) \t\t\t  │\n");
    printf("\t\t\t\t│\t특수제조업(580) \t\t  │\n");
    printf("\t\t\t\t│\t건축공학(590) \t\t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 5;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "기과");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "자연과학");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "수학");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "천문학");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "물리학");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "화학");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "지구과학");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "고생물학");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "생물학");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "식물학");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "동물학");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert6(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t예술(600) \t\t\t  │\n");
    printf("\t\t\t\t│\t도시예술,조경예술(610) \t\t  │\n");
    printf("\t\t\t\t│\t건축술(620) \t\t\t  │\n");
    printf("\t\t\t\t│\t조각술(630) \t\t\t  │\n");
    printf("\t\t\t\t│\t그래픽아트,장식예술(640)  \t  │ \n");
    printf("\t\t\t\t│\t회화(650)\t\t\t  │ \n");
    printf("\t\t\t\t│\t판화(660) \t\t\t  │\n");
    printf("\t\t\t\t│\t사진술,영화예술(670)\t\t  │\n");
    printf("\t\t\t\t│\t음악(680) \t\t\t  │\n");
    printf("\t\t\t\t│\t공연예술,오락,스포츠(690)\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 6;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "문학");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "기술과학");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "의학");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "공학");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "농학");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "가정학");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "경영학");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "화학공학");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "제조업");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "특수제조");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "건축공학");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert7(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t언어(700) \t\t\t  │\n");
    printf("\t\t\t\t│\t언어학(710) \t\t\t  │\n");
    printf("\t\t\t\t│\t영어(720) \t\t\t  │\n");
    printf("\t\t\t\t│\t독일어(730) \t\t\t  │\n");
    printf("\t\t\t\t│\t프랑스어(740)  \t\t\t  │ \n");
    printf("\t\t\t\t│\t이탈리아어(750)\t\t\t  │ \n");
    printf("\t\t\t\t│\t스페인어(760) \t\t\t  │\n");
    printf("\t\t\t\t│\t라틴어,이태리어(770)\t\t  │\n");
    printf("\t\t\t\t│\t그리스어(780) \t\t\t  │\n");
    printf("\t\t\t\t│\t기타언어(790) \t\t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");

    int classnum = (int)temp - 48;

    int idx;
    classnum = 7;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "문학");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "예술");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "도시조경");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "건축술");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "조각술");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "그래장식");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "회화");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "판화");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "사진영화");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "음악");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "공연오락");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}

void con_insert8(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t문학(800) \t\t\t  │\n");
    printf("\t\t\t\t│\t미국문학(810) \t\t\t  │\n");
    printf("\t\t\t\t│\t영국문학(820) \t\t\t  │\n");
    printf("\t\t\t\t│\t독일문학(830) \t\t\t  │\n");
    printf("\t\t\t\t│\t프랑스문학(840)  \t\t  │ \n");
    printf("\t\t\t\t│\t이탈리아문학(850)\t\t  │ \n");
    printf("\t\t\t\t│\t스페인문학(860) \t\t  │\n");
    printf("\t\t\t\t│\t라틴 및 이태리문학(870)\t\t  │\n");
    printf("\t\t\t\t│\t그리스문학(880) \t\t  │\n");
    printf("\t\t\t\t│\t기타언어 문학(890) \t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");

    int classnum = (int)temp - 48;

    int idx;
    classnum = 8;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "문학");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "문학");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "미국문학");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "영국문학");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "독일문학");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "프랑스문");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "이탈리아");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "스페인문");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "라틴및이");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "그리스문");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "기타언어");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }
}

void con_insert9(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 추가                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│\t역사(900) \t\t\t  │\n");
    printf("\t\t\t\t│\t지리,기행(910) \t\t\t  │\n");
    printf("\t\t\t\t│\t전기,계보학(920) \t\t  │\n");
    printf("\t\t\t\t│\t고대세계 역사(930) \t\t  │\n");
    printf("\t\t\t\t│\t유럽역사(940)  \t\t\t  │ \n");
    printf("\t\t\t\t│\t아시아역사(950)\t\t\t  │ \n");
    printf("\t\t\t\t│\t아프리카역사(960) \t\t  │\n");
    printf("\t\t\t\t│\t북미역사(970) \t\t\t  │\n");
    printf("\t\t\t\t│\t남미역사(980) \t\t\t  │\n");
    printf("\t\t\t\t│\t기타지역 역사(990) \t\t  │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 9;
    printf("\t\t\t\t저장할 소분류 번호 입력(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t잘못 입력되었습니다.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t제목(띄어쓰기 시 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t저자 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t출판사 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "문학");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "역사");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "지리기행");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "전기계보");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "고대역사");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "유럽역사");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "아시역사");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "아프역사");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "북미역사");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "남미역사");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "기타역사");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t저장되었습니다.\n");

    }
    else
    {
        printf("\t\t\t\t범위를 벗어났습니다..\n");

    }

}


int searchsn(int serialnum) //일련번호 검색
{
    for (int i = 0; i <= count; i++) {
        if (g_booklist[i].classnum3 == serialnum) {
            return i;
        }
    }
    return -1;
}

void con_select()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 검색                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                                         │\n");
    printf("\t\t\t\t│             [1] 제목 검색               │\n");
    printf("\t\t\t\t│             [2] 저자 검색               │\n");
    printf("\t\t\t\t│             [3] 출판사 검색             │\n");
    printf("\t\t\t\t│             [4] 분류별 검색             │\n");
    printf("\t\t\t\t│             [5] 일련번호 검색           │\n");
    printf("\t\t\t\t│                                         │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 검색                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t제목 입력) ");
        gets_s(name, sizeof(name));

        int i = nametoidx(name);
        system("cls");
        
        if (i != -1) {
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│                                  검색 결과                                  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");

            char gar[10]; //대출가능여부
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "가  능");
            }
            else {
                strcpy_s(gar, sizeof(gar), "불가능");
            }
            if (g_booklist[i].flag == 1) {
                printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t없습니다\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 검색                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t저자 입력) ");
        gets_s(name, sizeof(name));

        int i = authtoidx(name);
        system("cls");
        
        if (i != -1) {
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│                                  검색 결과                                  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");

            char gar[10]; //대출가능여부
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "가  능");
            }
            else {
                strcpy_s(gar, sizeof(gar), "불가능");
            }
            if (g_booklist[i].flag == 1) {
                printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t없습니다\n");
        }
    }
    else if (temp == '3') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 검색                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t출판사 입력) ");
        gets_s(name, sizeof(name));

        int i = pubtoidx(name);
        
        if (i != -1) {
            system("cls");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│                                  검색 결과                                  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");

            char gar[10]; //대출가능여부
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "가  능");
            }
            else {
                strcpy_s(gar, sizeof(gar), "불가능");
            }
            if (g_booklist[i].flag == 1) {
                printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t없습니다\n");
        }
    }
    else if (temp == '4') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 검색                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│            총류(000~099): 0번           │\n");
        printf("\t\t\t\t│            철학(100~199): 1번           │\n");
        printf("\t\t\t\t│            종교(200~299): 2번           │\n");
        printf("\t\t\t\t│            사회과학(300~399): 3번       │\n");
        printf("\t\t\t\t│            자연과학(400~499): 4번       │\n");
        printf("\t\t\t\t│            기술과학(500~599): 5번       │\n");
        printf("\t\t\t\t│            예술(600~699): 6번           │\n");
        printf("\t\t\t\t│            언어(700~799): 7번           │\n");
        printf("\t\t\t\t│            문학(800~899): 8번           │\n");
        printf("\t\t\t\t│            역사(900~999): 9번           │\n");
        printf("\t\t\t\t│            돌아가기: x키                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        char ch = _getch();

        if (ch == 'x') {
            printf("\t\t\t\t잘못된 값입니다.\n");
        }
        else {
            system("cls");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│                                  검색 결과                                  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            int classnum = (int)ch - 48;
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");

            for (int i = 0; i <= count; i++)
            {
                char gar[10]; //대출가능여부
                if (g_booklist[i].flag1 == 1) {
                    strcpy_s(gar, sizeof(gar), "가  능");
                }
                else {
                    strcpy_s(gar, sizeof(gar), "불가능");
                }
                if (g_booklist[i].flag == 1 && g_booklist[i].classnum1 == classnum) {
                    printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                    printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                    printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
                }
                printf("│                                                                             │\n");
            }
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("\n");
        }
    }
    else if (temp == '5') {
        system("cls");
        int sn;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 검색                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t일련번호 입력) ");
        scanf_s("%d", &sn);
        int i = searchsn(sn);
        if (i == -1) {
            printf("\t\t\t\t잘못된 값입니다.\n");
        }
        else {
            system("cls");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│                                  검색 결과                                  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
            printf("│   분류번호\t제목\t\t  저자  \t  출판사  \t대여가능여부  │\n");
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

            printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");

            char gar[10]; //대출가능여부
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "가  능");
            }
            else {
                strcpy_s(gar, sizeof(gar), "불가능");
            }
            if (g_booklist[i].flag == 1) {
                printf("│ %-2s.%-8s                                                               │\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("│  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s │\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("│ %-2s.%-2s.%-8s                                                              │\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
            printf("\n");
        }
    }
}
void con_update()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 대여                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│         [1] 제목 검색 후 대여           │\n");
    printf("\t\t\t\t│         [2] 일련번호 검색 후 대여       │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        char name[20];
        printf("\t\t\t\t제목 입력 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            if (g_booklist[idx].flag1 == 1) {
                g_booklist[idx].flag1 = 0;

                printf("\t\t\t\t대여되었습니다.\n");
            }
            else
                printf("\t\t\t\t이미 대여되어있습니다.\n");
        }
        else
        {
            printf("\t\t\t\t없습니다\n");
        }
    }
    else if (temp == '2') {
        int sn;
        printf("\t\t\t\t일련번호 입력) ");
        scanf_s("%d", &sn);
        int temp = searchsn(sn);
        if (temp == -1) {
            printf("\t\t\t\t없습니다\n");
        }
        else {
            if (g_booklist[temp].flag1 == 1) {
                g_booklist[temp].flag1 = 0;

                printf("\t\t\t\t대여되었습니다.\n");
            }
            else {
                printf("\t\t\t\t이미 대여되어있습니다.\n");
            }
        }
    }
    else {
        return;
    }
}
void con_update1()
{
    system("cls"); 
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 반납                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│         [1] 제목 검색 후 반납           │\n");
    printf("\t\t\t\t│         [2] 일련번호 검색 후 반납       │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        char name[20];
        printf("\t\t\t\t제목 입력 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            if (g_booklist[idx].flag1 == 0) {
                g_booklist[idx].flag1 = 1;

                printf("\t\t\t\t반납되었습니다.\n");
            }
            else
                printf("\t\t\t\t이미 반납되어있습니다.\n");
        }
        else
        {
            printf("\t\t\t\t없습니다\n");
        }
    }
    else if(temp == '2') {
        int sn;
        printf("\t\t\t\t일련번호 입력) ");
        scanf_s("%d", &sn);

        int idx = searchsn(sn);
        if (idx != -1) {
            if (g_booklist[idx].flag1 == 0) {
                g_booklist[idx].flag1 = 1;

                printf("\t\t\t\t반납되었습니다.\n");
            }
            else
                printf("\t\t\t\t이미 반납되어있습니다.\n");
        }
        else {
            printf("\t\t\t\t없습니다.\n");
        }
    }
}
void con_update2()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 수정                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│         [1] 제목 검색 후 수정           │\n");
    printf("\t\t\t\t│         [2] 일련번호 검색 후 수정       │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 수정                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t제목 입력 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            char auth[20];
            char pub[20];
            char name[20];
            int cn1;
            int cn2;

            printf("\t\t\t\t수정할 대분류 번호 입력(0~9) : ");
            scanf_s("%d", &cn1);
            if (cn1 < 0 && cn1 > 9) {
                printf("\t\t\t\t잘못 입력되었습니다.\n");
                return;
            }
            if (cn1 == 0)  	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "총류");
            else if (cn1 == 1) 	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "철학");
            else if (cn1 == 2)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "종교");
            else if (cn1 == 3)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "사과");
            else if (cn1 == 4)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "자과");
            else if (cn1 == 5)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "기과");
            else if (cn1 == 6)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "예술");
            else if (cn1 == 7)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "언어");
            else if (cn1 == 8)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "문학");
            else if (cn1 == 9)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "역사");


            printf("\t\t\t\t수정할 소분류 번호 입력(00~99) : ");
            scanf_s("%d", &cn2);
            if (cn2 < 0 && cn2 > 99) {
                printf("\t\t\t\t잘못 입력되었습니다.\n");
                return;
            }
            if (cn1 == 0)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "도서서지");
                else if (cn2 >= 10 && cn2 <= 19)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "문헌정보");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "백과사전");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "강수연집");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "일반연속");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "학단협기");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "신문저널");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "전집총서");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "향토자료");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "역사");
            }
            if (cn1 == 1)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "철학");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "형이상학");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "인식론");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "심리신비");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "철학파");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "심리학");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "논리학");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "윤리학");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "고중동철");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "현서철학");
            }
            if (cn1 == 2)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "종교");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "종철및이");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "성경");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "교리신학");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리윤리");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "지역교회");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리사신");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리교회");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리교파");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타종교");
            }
            if (cn1 == 3)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "사회과학");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "통계");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "정치학");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "경계학");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "볍률");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "행정군사");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "사회문복");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "교육학");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "상통교통");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "풍속민속");
            }
            if (cn1 == 4)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "자연과학");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "수학");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "천문학");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "물리학");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "화학");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "지구과학");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "고생물학");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "생물학");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "식물학");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "동물학");
            }
            if (cn1 == 5)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기술과학");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "의학");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "공학");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "농학");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "가정학");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "경영학");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "화학공학");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "제조업");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "특수제조");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "건축공학");
            }
            if (cn1 == 6)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "예술");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "도시조경");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "건축술");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "조각술");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그래장식");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "회화");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "판화");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "사진영화");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "음악");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "공연오락");
            }
            if (cn1 == 7)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "언어");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "언어학");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "영어");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "독일어");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "프랑스어");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "이태리어");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "스페인어");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "라틴이태");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리스어");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타언어");
            }
            if (cn1 == 8)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "문학");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "미국문학");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "영국문학");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "독일문학");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "프랑스문");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "이탈리아");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "스페인문");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "라틴및이");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리스문");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타언어");
            }
            if (cn1 == 9)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "역사");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "지리기행");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "전기계보");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "고대역사");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "유럽역사");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "아시역사");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "아프역사");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "북미역사");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "남미역사");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타역사");
            }

            getchar();
            printf("\t\t\t\t수정할 제목 입력 : ");
            gets_s(name, sizeof(name));
            printf("\t\t\t\t수정할 작가 입력 : ");
            gets_s(auth, sizeof(auth));
            printf("\t\t\t\t수정할 출판사 입력 : ");
            gets_s(pub, sizeof(pub));
            g_booklist[idx].classnum1 = cn1;
            g_booklist[idx].classnum2 = cn2;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx].name), name);
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx].pub), auth);
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx].pub), pub);

            strncpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), g_booklist[idx].pub, 2);
            g_booklist[idx].classpub[3] = '\0';
            strncpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), g_booklist[idx].auth, 2);
            g_booklist[idx].classauth[3] = '\0';
            strncpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), g_booklist[idx].name, 8);
            g_booklist[idx].classname[8] = '\0';


            printf("\t\t\t\t수정되었습니다.\n");
        }
        else
        {
            printf("\t\t\t\t없습니다\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        int sn;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 수정                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        printf("\t\t\t\t일련번호 입력) ");
        scanf_s("%d", &sn);
        int idx = searchsn(sn);
        if (idx == -1) {
            printf("\t\t\t\t잘못된 값입니다.\n");
        }
        else {
            if (sn != -1)
            {
                char auth[20];
                char pub[20];
                char name[20];
                int cn1;
                int cn2;

                printf("\t\t\t\t수정할 대분류 번호 입력(0~9) : ");
                scanf_s("%d", &cn1);
                if (cn1 < 0 && cn1 > 9) {
                    printf("\t\t\t\t잘못 입력되었습니다.\n");
                    return;
                }
                if (cn1 == 0)  	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "총류");
                else if (cn1 == 1) 	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "철학");
                else if (cn1 == 2)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "종교");
                else if (cn1 == 3)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "사과");
                else if (cn1 == 4)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "자과");
                else if (cn1 == 5)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "기과");
                else if (cn1 == 6)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "예술");
                else if (cn1 == 7)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "언어");
                else if (cn1 == 8)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "문학");
                else if (cn1 == 9)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "역사");


                printf("\t\t\t\t수정할 소분류 번호 입력(00~99) : ");
                scanf_s("%d", &cn2);
                if (cn2 < 0 && cn2 > 99) {
                    printf("\t\t\t\t잘못 입력되었습니다.\n");
                    return;
                }
                if (cn1 == 0)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "도서서지");
                    else if (cn2 >= 10 && cn2 <= 19)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "문헌정보");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "백과사전");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "강수연집");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "일반연속");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "학단협기");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "신문저널");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "전집총서");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "향토자료");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "역사");
                }
                if (cn1 == 1)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "철학");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "형이상학");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "인식론");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "심리신비");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "철학파");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "심리학");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "논리학");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "윤리학");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "고중동철");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "현서철학");
                }
                if (cn1 == 2)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "종교");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "종철및이");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "성경");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "교리신학");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리윤리");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "지역교회");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리사신");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리교회");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리교파");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타종교");
                }
                if (cn1 == 3)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "사회과학");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "통계");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "정치학");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "경계학");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "볍률");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "행정군사");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "사회문복");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "교육학");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "상통교통");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "풍속민속");
                }
                if (cn1 == 4)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "자연과학");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "수학");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "천문학");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "물리학");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "화학");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "지구과학");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "고생물학");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "생물학");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "식물학");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "동물학");
                }
                if (cn1 == 5)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기술과학");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "의학");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "공학");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "농학");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "가정학");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "경영학");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "화학공학");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "제조업");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "특수제조");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "건축공학");
                }
                if (cn1 == 6)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "예술");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "도시조경");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "건축술");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "조각술");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그래장식");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "회화");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "판화");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "사진영화");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "음악");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "공연오락");
                }
                if (cn1 == 7)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "언어");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "언어학");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "영어");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "독일어");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "프랑스어");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "이태리어");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "스페인어");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "라틴이태");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리스어");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타언어");
                }
                if (cn1 == 8)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "문학");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "미국문학");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "영국문학");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "독일문학");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "프랑스문");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "이탈리아");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "스페인문");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "라틴및이");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "그리스문");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타언어");
                }
                if (cn1 == 9)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "역사");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "지리기행");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "전기계보");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "고대역사");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "유럽역사");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "아시역사");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "아프역사");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "북미역사");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "남미역사");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "기타역사");
                }

                getchar();
                printf("\t\t\t\t수정할 제목 입력 : ");
                gets_s(name, sizeof(name));
                printf("\t\t\t\t수정할 작가 입력 : ");
                gets_s(auth, sizeof(auth));
                printf("\t\t\t\t수정할 출판사 입력 : ");
                gets_s(pub, sizeof(pub));
                g_booklist[idx].classnum1 = cn1;
                g_booklist[idx].classnum2 = cn2;
                strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx].name), name);
                strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx].pub), auth);
                strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx].pub), pub);

                strncpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), g_booklist[idx].pub, 2);
                g_booklist[idx].classpub[3] = '\0';
                strncpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), g_booklist[idx].auth, 2);
                g_booklist[idx].classauth[3] = '\0';
                strncpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), g_booklist[idx].name, 8);
                g_booklist[idx].classname[8] = '\0';


                printf("\t\t\t\t수정되었습니다.\n");
            }
            else
            {
                printf("\t\t\t\t없습니다\n");
            }
        }
    }
}

void con_delete()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│                도서 삭제                │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");
    printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
    printf("\t\t\t\t│         [1] 제목 검색 후 삭제           │\n");
    printf("\t\t\t\t│         [2] 일련번호 검색 후 삭제       │\n");
    printf("\t\t\t\t└─────────────────────────────────────────┘\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 삭제                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        char name[20];
        printf("\t\t\t\t제목 입력 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1) {
            g_booklist[idx].classnum1 = 0;
            g_booklist[idx].classnum2 = 0;
            g_booklist[idx].classnum3 = 0;
            g_booklist[idx].flag = 0;
            g_booklist[idx].flag1 = 0;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx]).name, "");
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx]).auth, "");
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx]).pub, "");
            strcpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), "");
            strcpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), "");
            strcpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), "");
            strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "");
            strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "");


            printf("\t\t\t\t삭제되었습니다.\n\n");

        }
        else
        {
            printf("\t\t\t\t없습니다\n\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t┌─────────────────────────────────────────┐\n");
        printf("\t\t\t\t│                도서 삭제                │\n");
        printf("\t\t\t\t└─────────────────────────────────────────┘\n");
        int sn;
        printf("\t\t\t\t일련번호 입력) ");
        scanf_s("%d", &sn);
        int idx = searchsn(sn);
        if (idx != -1) {
            g_booklist[idx].classnum1 = 0;
            g_booklist[idx].classnum2 = 0;
            g_booklist[idx].flag = 0;
            g_booklist[idx].flag1 = 0;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx]).name, "");
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx]).auth, "");
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx]).pub, "");
            strcpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), "");
            strcpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), "");
            strcpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), "");
            strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "");


            printf("\t\t\t\t삭제되었습니다.\n\n");

        }
        else
        {
            printf("\t\t\t\t잘못된 값입니다.\n\n");
        }
    }
}

int nametoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].name, name) == 0)
            return i;
    }
    return -1;
}

int authtoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].auth, name) == 0)
            return i;
    }
    return -1;
}
int pubtoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].pub, name) == 0)
            return i;
    }
    return -1;
}