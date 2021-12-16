#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int i,j,a,b;
int otobus[10][3];
int koltuk;
int otobusNo;
int personel;
int hasilat;
float ucret;
char hex[10];
char basSehir[20];
char varSehir[20];
int otobusNo_Sec,baslangicSaat,varisSaat,yolculukSure;
char rezervNo[8];
char ad[20],soyad[20];
int main()
{
    system("cls");
    char giris;

    printf("\n\n\n\n\t\t\t..::Betelgeuse Ulasim::..");
    printf("\n\n\n\n\t\t\tANA MENU");
    printf("\n\t\t\t1. FIRMA GIRISI");
    printf("\n\t\t\t2. MUSTERI GIRISI");
    printf("\n\t\t\t3. CIKIS");
    menu:
    printf("\n\t\t\tLutfen bir giris yapiniz -> ");
    scanf("%s", &giris);

    switch (giris){
    case '1':
        firmaGiris();
        break;
    case '2':
        musteriGiris();
        break;
    case '3':
        cikis();
        break;
    default:
        printf("\n\t\t\tHatali giris yaptiniz. Lutfen tekrar deneyin.");
        goto menu;
        break;
    }
    return 0;
}
void cikis(){
    printf("\n\t\t\tGuney Kaya 202802042 Yazilim Muh.");
}
void musteriGiris(){
    system("cls");
    char a;
    printf("\n\n\n\n\t\t\tMUSTERI GIRIS");
    printf("\n\t\t\t1. Seferleri Listele");
    printf("\n\t\t\t2. Sefer Rezervasyon Yap");
    printf("\n\t\t\t3. Geri");
    printf("\n\t\t\t4. Rezervasyon Goster");
    kontrol1:
    printf("\n\t\t\tLutfen bir giris yapiniz -> ");
    scanf("%s", &a);

    switch (a){
    case '1':
        seferList();
        break;
    case '2':
        rezervasyon();
        break;
    case '3':
        main();
        break;
    case '4':
        rezervGor();
        break;
    default:
        printf("\n\t\t\tHatali giris yaptiniz. Lutfen tekrar deneyin.");
        goto kontrol1;
        break;
    }
}
void seferList(){
    system("cls");
    FILE *ptr;
    ptr=fopen("sefer.txt","r");
    while (fscanf(ptr,"%d %d %d %s %d %d %s %s %d %f",&otobusNo_Sec, &koltuk, &personel, hex,&baslangicSaat,&varisSaat,basSehir,varSehir,&hasilat,&ucret)!=EOF){
        printf("%s Sefer numarali sefer: ", hex);
        printf("\nOtobus No: %d\nPersonel Sayisi: %d\nKoltuk Sayisi: %d\nKalkis Saati: %d\nVaris Saati: %d\nSefer %s - %s 'ye\nHasilat: %d\n\n", otobusNo_Sec,personel,koltuk,baslangicSaat,varisSaat,basSehir,varSehir,hasilat);
    }
     fclose(ptr);
     don:
    printf("Geri donmek icin 1 tuslayin -> ");
    scanf("%d", &b);
    if (b==1){
        musteriGiris();
    }
    else {
        printf("Gecersiz karakter tusladiniz.");
        goto don;
    }

}
void rezervasyon(){
    system("cls");
    FILE *asd,*qwe,*jkl;
    asd=fopen("sefer.txt","r");
    qwe=fopen("sefer.txt","r");
    jkl=fopen("rezerve.txt","a+");
    char seferNo[10];
    int sutun;
    char koltuklar[50][4];

    while (fscanf(asd,"%d %d %d %s %d %d %s %s %d %f",&otobusNo_Sec, &koltuk, &personel, hex,&baslangicSaat,&varisSaat,basSehir,varSehir,&hasilat,&ucret)!=EOF){
        printf("%s\n", hex);
    }
    printf("Sefer No? ");
    scanf("%s", seferNo);

        while (fscanf(qwe,"%d %d %d %s %d %d %s %s %d %f",&otobusNo_Sec, &koltuk, &personel, hex,&baslangicSaat,&varisSaat,basSehir,varSehir,&hasilat,&ucret)!=EOF){
        if (strcmp(hex,seferNo)==0){
        printf("%s Sefer Numarali Yolculuk",hex);
        printf("\nOtobus No: %d\nPersonel Sayisi: %d\nKoltuk Sayisi: %d\nKalkis Saati: %d\nVaris Saati: %d\nSefer %s - %s 'ye\nHasilat: %d\n", otobusNo_Sec,personel,koltuk,baslangicSaat,varisSaat,basSehir,varSehir,hasilat);
            }
        }

    fclose(asd);
    fclose(qwe);
    sutun = koltuk/4;
    if (koltuk%4!=0){
        for (i=0;i<sutun;i++){
            printf("\n%2d", i+1);
        for (j=0;j<4;j++){
                printf("[ ]\t", koltuklar[i][j]);

            }
        }
        for (i=0;i<koltuk%4;i++){
            printf("[ ]\t");
        }
    }
    else {
    for (i=0;i<sutun;i++){
            printf("\n%2d", i+1);
        for (j=0;j<4;j++){
                printf("[ ]\t", koltuklar[i][j]);

            }
        }
    }
    char ad[20];
    char soyad[20];
    int a,b;
    //char rezerveKoltuk[50][4];

    printf("\nRezervasyon yapilacak kisinin adi, soyadi: ");
    scanf("%s %s", ad, soyad);
    printf("\nKac numarali koltuk rezerve edilecek? (satir ve sutun numarasi olarak giriniz)");
    printf("\nSatir: ");
    scanf("%d", &a);
    printf("\nSutun: ");
    scanf("%d", &b);
    if (koltuk%4!=0){
        for (i=0;i<sutun;i++){
            printf("\n%2d", i+1);
        for (j=0;j<4;j++){
                printf("[ ]\t", koltuklar[i][j]);
                if (i+1==a&&j+2==b){
                    printf("[x]\t", koltuklar[a][b]);
                }

            }
        }
        for (i=0;i<koltuk%4;i++){
            printf("[ ]\t");
        }
    }
    else {
    for (i=0;i<sutun;i++){
            printf("\n%2d", i+1);
        for (j=0;j<4;j++){
                printf("[ ]\t", koltuklar[i][j]);
                if (i+1==a&&j+2==b){
                    printf("[x]\t", koltuklar[a][b]);
                }

            }
        }
    }

    int length;
    char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXVZ";
    char cevap;
    kotnrol:
    printf("\nOnayliyor musunuz?");
    scanf(" %c", &cevap);
    switch (cevap){
    case 'E':
    srand((unsigned int) time(0) + getpid());
    length = 8;
    printf("\nRezervasyon numarasi: ");
    while(length--) {
        putchar(str[rand() % 36]);
        srand(rand());
    }
    printf("\n");
        printf("Lutfen size atanan 8 haneli rezervasyon numarasini giriniz: ");
        scanf("%s", rezervNo);
        fprintf(jkl,"%s %d %d %s %s %d %d %s %d %d %s %s %f\n",rezervNo,a,b,ad,soyad,koltuk,personel,hex,baslangicSaat,varisSaat,basSehir,varSehir,ucret);
        fclose(jkl);
        printf("Kayit tamamlandi\a\a\a");
        don:
    printf("Geri donmek icin 1 tuslayin -> ");
    scanf("%d", &b);
    if (b==1){
        musteriGiris();
    }
    else {
        printf("Gecersiz karakter tusladiniz.");
        goto don;
    }
        break;
        case 'H':
        musteriGiris();
        break;
        default:
            printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
            goto kotnrol;
            break;

    }
}
void rezervGor(){
    system("cls");
    FILE *qwe;
    qwe=fopen("rezerve.txt","r");
    printf("Rezervasyon numaranizi giriniz: ");
    scanf("%s", rezervNo);
    while(fscanf(qwe,"%s %d %d %s %s %d %d %s %d %d %s %s %f",rezervNo,&a,&b,ad,soyad,&koltuk,&personel,hex,&baslangicSaat,&varisSaat,basSehir,varSehir,&ucret)!=EOF){
        printf("Koltuk Numarasi: %d %d\nAd: %s\nSoyad: %s\nSefer Bilgileri:\nKoltuk Sayisi: %d\nPersonel Sayisi: %d\nSefer Numarasi: %s\nSefer Baslangic Saati: %d\nSefer Varis Saati: %d\nSefer %s-%s sehirleri arasindadir\nKisi basi ucret: %.2f TL\n",a,b,ad,soyad,koltuk,personel,hex,baslangicSaat,varisSaat,basSehir,varSehir,ucret);
    }
    don:
    printf("Geri donmek icin 1 tuslayin -> ");
    scanf("%d", &b);
    if (b==1){
        musteriGiris();
    }
    else {
        printf("Gecersiz karakter tusladiniz.");
        goto don;
    }

}
void firmaGiris(){
    system("cls");
    char a;
    printf("\n\n\n\n\t\t\tFIRMA GIRIS");
    printf("\n\t\t\t1. Otobus Ekle");
    printf("\n\t\t\t2. Sefer Bilgisi Ekle");
    printf("\n\t\t\t3. Sefer/Koltuk Bilgisi");
    printf("\n\t\t\t4. Geri");
    kontrol1:
    printf("\n\t\t\tLutfen bir giris yapiniz -> ");
    scanf("%s", &a);

    switch (a){
    case '1':
        otobusEkle();
        break;
    case '2':
        seferBilgisi();
        break;
    case '3':
        seferKoltuk();
        break;
    case '4':
        main();
        break;
    default:
        printf("\n\t\t\tHatali giris yaptiniz. Lutfen tekrar deneyin.");
        goto kontrol1;
    }
}
void otobusEkle(){
    FILE *ptr;
    ptr=fopen("kayit.txt","a+");
    int otobus[10][3];
    char modeli[50];
    char b;
    int koltuk;
    int otobusNo;
    int personel;
    system("cls");
    printf("Kac adet otobus eklenecek? ");
    scanf("%d", &a);

    for (otobusNo=0;otobusNo<a;otobusNo++){
        printf("Otobus kapasitesi: ");
        scanf("%d", &koltuk);
        if (koltuk>30){
                printf("Personel sayisi 3 olarak atanmistir.\n");
                personel=3;
        }
        else {
        printf("Personel sayisi: ");
        scanf("%d", &personel);
        }
        otobus[otobusNo][0]=otobusNo+1;
        otobus[otobusNo][1]=koltuk;
        otobus[otobusNo][2]=personel;
        printf("Otobus modelini girin: ");
        scanf("%s", modeli);
    }
    printf("Otobus No\t Koltuk \tPersonel\t\n");
    for (i=0;i<a;i++){
        for (j=0;j<3;j++){
            fprintf(ptr,"%d\t", otobus[i][j]);
            printf("%4d\t\t", otobus[i][j]);
        }
        fprintf(ptr,"\n");
        printf("\n");
    }
    fclose(ptr);
    printf("%d adet otobusun kaydi basariyla tamamlanmistir. ", a);
    printf("\a\a\a");
    don:
    printf("Geri donmek icin 1 tuslayin -> ");
    scanf("%d", &b);
    if (b==1){
        firmaGiris();
    }
    else {
        printf("Gecersiz karakter tusladiniz.");
        goto don;
    }

}
void seferBilgisi(){
    FILE *ptr,*fptr;
    ptr=fopen("kayit.txt","r");
    fptr=fopen("sefer.txt","a+");
    system("cls");
    int length,hasilat;
    int koltuk;
    int koltuk1;
    float ucret;
    char hex[10];
    char basSehir[20];
    char varSehir[20];
    int otobusNo_Sec,baslangicSaat,varisSaat,yolculukSure;
    printf("Sefer atanacak otobus numarasini girin: ");
    scanf("%d", &otobusNo_Sec);
    while (fscanf(ptr,"%d\t%d\t%d", &otobusNo,&koltuk,&personel)!=EOF){
        if (otobusNo_Sec==otobusNo){
                printf("Otobus No\t Koltuk \tPersonel\t\n");
            printf("%4d\t\t%4d\t\t%4d\t\t",otobusNo,koltuk,personel);
            koltuk1=koltuk;
        }
    }
    char str[] = "0123456789ABCDEF";
    srand((unsigned int) time(0) + getpid());
    length = 4;
    printf("\nAtanan Sefer No: 42");
    while(length--) {
        putchar(str[rand() % 16]);
        srand(rand());
    }
    char u;
    printf("\nLutfen bu sefere atanan Sefer Numarasini girin: ");
    scanf("%s", &hex);
    printf("SYSTEM: Saatleri basina sifir (0) koymadan yaziniz.");
    printf("\nSefer baslangic saati: (ssdd) ");
    scanf("%d", &baslangicSaat);
    if ((baslangicSaat%100)!=42){
        printf("\nSefer bu saatte gerceklesemez.");
        baslangicSaat = (baslangicSaat-(baslangicSaat%100))+42;
        printf("\nYeni sefer saati: %d ", baslangicSaat);
    }
    printf("\nTahmini varis saati: (ssdd) ");
    scanf("%d",&varisSaat);
    if (varisSaat>baslangicSaat){
        yolculukSure=(varisSaat-baslangicSaat)/100;
        if (yolculukSure==0){
            printf("\nYolculuk 1 saatten az surecektir.\n");
        }
        else if (yolculukSure>=4){
            if (koltuk1>=30||personel>=3){
                    printf("Sefer saatleri belirlendi.\n");
                    printf("Yolculuk yaklasik %d saat surecektir.\n", yolculukSure);
                }
            else {
                    printf("Kisa yol araciyla uzun yol yapilamaz. Lutfen tekrar deneyin.\n");
                    printf("Devam etmek icin bir karaktere basin. ");
                    scanf(" %c", &u);
                    seferBilgisi();
                    }
            }
            else {
                printf("Sefer saatleri belirlendi\n");
                printf("Yolculuk yaklasik %d saat surecektir.\n", yolculukSure);
            }
    }
    else {
        yolculukSure=24-((abs(varisSaat-baslangicSaat))/100);
        if (yolculukSure==0){
            printf("\nYolculuk 1 saatten az surecektir.\n");
        }
           else if (yolculukSure>=4){
                    if (koltuk1>=30||personel>=3){
                        printf("Sefer saatleri belirlendi.\n");
                        printf("Yolculuk yaklasik %d saat surecektir.\n", yolculukSure);
                }
                    else {
                        printf("Kisa yol araciyla uzun yol yapilamaz. Lutfen tekrar deneyin.\n");
                        printf("Devam etmek icin bir karaktere basin. ");
                        scanf(" %c", &u);
                        seferBilgisi();
                    }
            }
            else {
                printf("Sefer saatleri belirlendi\n");
                printf("Yolculuk yaklasik %d saat surecektir.\n", yolculukSure);
            }
    }

    printf("Sefer baslangic konumunu girin: \n");
    scanf(" %s", &basSehir);
    printf("Varis konumunu girin: \n");
    scanf(" %s", &varSehir);
    printf("Toplam hasilati girin: \n");
    scanf("%d", &hasilat);
    ucret=hasilat/koltuk1;
    printf("Kisi basi ucret: %.2f TL\n", ucret);

    fprintf(fptr,"%d %d %d %s %d %d %s %s %d %.2f\n", otobusNo_Sec, koltuk1, personel, hex,baslangicSaat,varisSaat,basSehir,varSehir,hasilat,ucret);

    fclose(ptr);
    fclose(fptr);
    printf("Sefer kaydi basariyla alinmistir. ");
    printf("\a\a\a");
    don:
    printf("Geri donmek icin 1 tuslayin -> ");
    scanf("%d", &b);
    if (b==1){
        firmaGiris();
    }
    else {
        printf("Gecersiz karakter tusladiniz.");
        goto don;
    }
}
void seferKoltuk(){
    system("cls");
    FILE *asd,*qwe,*jkl;
    jkl=fopen("rezerve.txt","r");
    asd=fopen("sefer.txt","r");
    qwe=fopen("sefer.txt","r");
    char seferNo[10];
    int sutun;
    char koltuklar[50][4];

    while (fscanf(asd,"%d %d %d %s %d %d %s %s %d %f",&otobusNo_Sec, &koltuk, &personel, hex,&baslangicSaat,&varisSaat,basSehir,varSehir,&hasilat,&ucret)!=EOF){
        printf("%s\n", hex);
    }
    printf("Sefer No? ");
    scanf("%s", seferNo);

        while (fscanf(qwe,"%d %d %d %s %d %d %s %s %d %f",&otobusNo_Sec, &koltuk, &personel, hex,&baslangicSaat,&varisSaat,basSehir,varSehir,&hasilat,&ucret)!=EOF){
        if (strcmp(hex,seferNo)==0){
        //printf("%d %d %d %s %d %d %s %s %d %.2f", otobusNo_Sec, koltuk, personel, hex,baslangicSaat,varisSaat,basSehir,varSehir,hasilat,ucret);
        printf("%s Sefer Numarali Yolculuk",hex);
        printf("\nOtobus No: %d\nPersonel Sayisi: %d\nKoltuk Sayisi: %d\nKalkis Saati: %d\nVaris Saati: %d\nSefer %s - %s 'ye\nHasilat: %d\n", otobusNo_Sec,personel,koltuk,baslangicSaat,varisSaat,basSehir,varSehir,hasilat);
            }
        }
    fclose(asd);
    fclose(qwe);
    /*printf("%s Sefer Numarali Yolculuk",hex);
    printf("\nOtobus No: %d\nPersonel Sayisi: %d\nKoltuk Sayisi: %d\nKalkis Saati: %d\nVaris Saati: %d\nSefer %s - %s 'ye\nHasilat: %d", otobusNo_Sec,personel,koltuk,baslangicSaat,varisSaat,basSehir,varSehir,hasilat);
    */
    sutun = koltuk/4;
    if (koltuk%4!=0){
        for (i=0;i<sutun;i++){
            printf("\n%2d", i+1);
        for (j=0;j<4;j++){
                printf("[ ]\t", koltuklar[i][j]);
            }
        }
         printf("\n");
        for (int k=0;k<koltuk%4;k++){
            printf("  [ ] ");
        }
    }
    else {
    for (i=0;i<sutun;i++){
            printf("\n%2d", i+1);
        for (j=0;j<4;j++){
                printf("[ ]\t", koltuklar[i][j]);

            }
        }
    }
        fclose(jkl);
    don:
    printf("\nGeri donmek icin 1 tuslayin -> ");
    scanf("%d", &b);
    if (b==1){
        firmaGiris();
    }
    else {
        printf("Gecersiz karakter tusladiniz.");
        goto don;
    }
}
