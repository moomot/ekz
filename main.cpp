#include <QCoreApplication>
#include <cmath>

void show_menu();
void makeTask_5_3();
void makeTask_5_4();
void makeTask_6_2();
void makeTask_6_3();
void makeTask_6_4();
void makeKorr()
{
    int arr1[10];
    int arr2[10];
    for(int i(0); i<10; i++){
        scanf("%d",&arr1[i]);
    }
    for(int i(0); i<10; i++){
        scanf("%d",&arr2[i]);
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i(0); i<10; i++){
        sum1 += arr1[i];
        sum2 += arr2[i];
    }
    double med1 = sum1/10;
    double med2 = sum2/10;
    printf("med  %1.0f  %1.0f\n", med1, med2);

    double dis1 = 0;
    double dis2 = 0;
    double cov = 0;
    for(int i(0); i<10; i++){
        dis1 += pow(arr1[i]-med1,2);
        dis2 += pow(arr2[i]-med2,2);
        cov += (arr1[i]-med1)*(arr2[i]-med2);
    }
    double one = sqrt(dis1);
    double two = sqrt(dis2);
    printf("dis  %0.2f  %0.2f\n",dis1/10, dis2/10);
    printf("sig  %0.4f  %0.4f\n",sqrt(dis1/10), sqrt(dis2/10));
    printf("cor  %0.4f  ",cov/(one*two));

    system("pause");
    system("cls");
    show_menu();
}
void serDispSigma()
{
    double arr[10];
    double sum = 0.0;
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
        sum+=arr[i];
    }

    double avg = (double) sum / (double)10;
    printf("Avg: %.4lf", avg);

    double disp = 0.0;
    for(int i = 0; i < 10; i++) {
        double tmp = arr[i] - avg;
        tmp*=tmp;
        disp+=tmp;
    }
    disp/=10;
    printf(" Disp: %.4lf", disp);

    printf(" Sigma: %.4lf", sqrt(disp));

    system("pause");
    system("cls");
    show_menu();

}
void amkm() {
    int x1 = 0, x2 = 0, x3 = 0;
    scanf("%d%d%d", &x1, &x2, &x3);
    int a = 0, b = 0, x4 = 0;
    a = x2;
    // A + B*x2 mod 8 = x3
    // A + B*x3 mod 8 = x4

    int cnt = 0;
    while(true) {
        if((a + cnt*x2)%8 == x3)
                break;
        cnt ++;
    }
    b = cnt;

    x4 = (a + b*x3)%8;

    printf("A: %d B: %d x4: %d", a, b, x4);

    system("pause");
    system("cls");
    show_menu();
}

int main()
{
    show_menu();
}

void show_menu(){
    printf("Choose your task:\n"
           "1)  client + working\n"
           "2)  coming + working\n"
           "3)  d95\n"
           "4)  3 arrays\n"
           "5)  3 avg + 3 disp\n"
           "6)  2 arrays + korr\n"
           "7)  avg+disp+sigma\n"
           "8)  AMKM\n\n");
    int task_num ;
    scanf("%d",&task_num);
    switch (task_num) {
    case 1:
        makeTask_5_3();
        break;
    case 2:
        makeTask_5_4();
        break;
    case 3:
        makeTask_6_2();
        break;
    case 4:
        makeTask_6_3();
        break;
    case 5:
        makeTask_6_4();
        break;
    case 6:
        makeKorr();
        break;
    case 7:
        serDispSigma();
        break;
    case 8:
        amkm();
        break;
    default:
        break;
    }
}

void makeTask_5_3(){
    system("cls");
    float a;
    float b;
    printf("Enter clients intens: ");
    scanf("%f",&a);
    printf("Enter working intens: ");
    scanf("%f",&b);
    float w = a/b;
    float d = 1-w*w;
    float c = (1-a/b)*w*w;
    float e = 1-c-d;
    printf(" %2.4f     %2.4f\n %2.4f     %2.4f\n\n",w,d,c,e);
    system("pause");
    system("cls");
    show_menu();
}

void makeTask_5_4(){
    system("cls");

    float a;
    float b;
    printf("Enter clients coming: ");
    scanf("%f",&a);
    printf("Enter client working: ");
    scanf("%f",&b);

    float w = b/a;
    float v = w*w/(1-w);
    float x = v*a;
    printf(" %2.4f    %2.4f   %2.4f\n\n",w,v,x);

    system("pause");
    system("cls");
    show_menu();
}

void makeTask_6_2(){
    system("cls");

    int arr[10];
    float a;
    printf("Enter numbers: \n");
    for(int i(0); i<10; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter koef: ");
    scanf("%f",&a);

    int sum1=0;
    for(int i(0); i<10; i++){
        sum1 += arr[i];
    }
    double med = sum1/10;

    double dis=0;
    for(int i(0); i<10; i++){
        dis += pow(arr[i]-med,2);
    }
    double D = dis/10;

    double total = a*sqrt(D/10);
    printf(" %2.4f    %2.4f   %2.4f\n\n",med,D,total);

    system("pause");
    system("cls");
    show_menu();
}

void makeTask_6_3(){
    system("cls");

    int arr1[10];
    int arr2[10];
    int arr3[10];

    printf("Enter numbers 1: \n");
    for(int i(0); i<10; i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter numbers 2: \n");
    for(int i(0); i<10; i++){
        scanf("%d",&arr2[i]);
    }
    printf("Enter numbers 3: \n");
    for(int i(0); i<10; i++){
        scanf("%d",&arr3[i]);
    }

    int sum1=0;
    int sum2=0;
    int sum3=0;
    for(int i(0); i<10; i++){
        sum1 += arr1[i];
        sum2 += arr2[i];
        sum3 += arr3[i];
    }
    double avr1 = sum1/10;
    double avr2 = sum2/10;
    double avr3 = sum3/10;

    double dis1=0;
    double dis2=0;
    double dis3=0;
    for(int i(0); i<10; i++){
        dis1 += pow(arr1[i]-avr1,2);
        dis2 += pow(arr2[i]-avr2,2);
        dis3 += pow(arr3[i]-avr3,2);
    }
    double D1 = dis1/10;
    double D2 = dis2/10;
    double D3 = dis3/10;
    double maxD;

    if(D1>D2){
        if(D1>D3){
            maxD = D1;
        }else{
            maxD = D3;
        }
    }else{
        if(D2>D3){
            maxD = D2;
        }else{
            maxD = D3;
        }
    }

    printf(" %2.4f     %2.4f \n", (D1+D2+D3)/3, maxD/(D1+D2+D3));

    system("pause");
    system("cls");
    show_menu();

}

void makeTask_6_4(){
    system("cls");

    double arr1[3];
    double arr2[3];

    printf("Enter avarages: \n");
    for(int i(0); i<3; i++){
        scanf("%lf",&arr1[i]);
    }
    printf("Enter dispersions: \n");
    for(int i(0); i<3; i++){
        scanf("%lf",&arr2[i]);
    }

    double sumD = (double)((double)arr2[0]+(double)arr2[1]+(double)arr2[2]);
    double serAvr = (double)(((double)arr1[0]+(double)arr1[1]+(double)arr1[2])/3);
    double sum = (double)((double)pow((double)arr1[0]-(double)serAvr,2)+(double)pow((double)arr1[1]-(double)serAvr,2)+(double)pow((double)arr1[2]-(double)serAvr,2));

    double ans1 = (double)((double)sumD/30);
    double ans2 = (double)((double)sum/2);
    double ans3 = (double)((double)ans2/(double)ans1);
    printf(" %.4f     %.4f     %.4f\n", ans1, ans2, ans3);


    system("pause");
    system("cls");
    show_menu();
}
