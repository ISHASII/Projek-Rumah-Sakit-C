#include<stdio.h>
#include<string.h>
#include<time.h>

void garis();
void namars();
void welcome();
void blokir();
void back();
void pasien();
void r_jalan();
void r_inap();
void rincian();
void rincian2();
void struk();
void struk2();
void biaya();
void info();
void tebus_obat();
void balik();
void kop_struk();

int const rj=100000,ri3=500000,ri2=750000,ri1=1000000,adm=25000,bk=50000,adm2=25000,bk2=50000;
int kembali(int jb,int rj,int bk,int adm,int total_pembelian);
int login,login2,um,tb,bb,um2,tb2,bb2,pilih,jb,jb2,li,kls,total_biaya,harga,ri,mp;
int obat,kode,total_pembelian=0,total_pembelian2=0,to,i=1,repeat=0;
char user[25],user2[25],pass[10],pass2[10],pilihan,na[50],al[200],pe[20],di[20],jk,gd,na2[50],al2[200],pe2[20],di2[20],jk2,gd2;
char a='y';
time_t waktu;

int main(void){
system("cls");
    while(repeat<=3){
    strcpy(user,"AIDA");
    strcpy(pass,"2022");
    namars();
    printf("\n\t\t\t\t\t\t| LOGIN |\n\n");
    printf("\t\t\t\tMasukkan Username : ");
    scanf("%s",&user2);
    login=strcmp(user,user2);
        if(login==0){
            printf("\t\t\t\tMasukkan Password : ");
            scanf("%s",&pass2);
            login2=strcmp(pass,pass2);
            if(login2==0){
                welcome();
                return 0;}
            else{
                printf("\n\n\n\t\t==========================================================================\n");
                printf("\t\t\t\t PASSWORD SALAH!!! Sisa Percobaan Login = %d Kali \n",2-repeat);
                printf("\t\t==========================================================================\n\n\n");
                printf("\t\tTekan Enter Untuk Kembali Ke Awal.\n\n\n");
                system("pause");}}
        else{
                printf("\n\n\n\t\t==========================================================================\n");
                printf("\t\t\t\t USERNAME SALAH!!! Sisa Percobaan Login = %d Kali \n",2-repeat);
                printf("\t\t==========================================================================\n\n\n");
                printf("\t\tTekan Enter Untuk Kembali Ke Awal.\n\n\n");
                system("pause");
                }
                repeat++;
                if(repeat==3){
                    blokir();
                    system("pause");
                    return 0;
            }
            system("cls");
        }
        return 0;
}
void garis(){
    printf("\n\t\t==========================================================================\n");
}
void kop_struk(){
    struct tm *Sys_T;
    time_t Unsika;
    Unsika = time(NULL);
    Sys_T = localtime(&Unsika); /* Untuk mendapatkan waktu lokal komputer */
        garis();
        printf("\n\t\t\t\t\t  RS. AIDA MEDIKA\n");
        printf("\t\t\t Jl. Singaperbangsa, Telukjaambe Timur, Kab. Karawang\n");
        printf("\t\t\t\t\t  Telp. 021-7354-3751\n");
        garis();
        printf("\n\t\t\t\t\t Hari/Tanggal/Waktu\n\t\t\t\t      %s", asctime (Sys_T));
        garis();
}
void balik(){
char pil2;
    printf("\n\t\tM : Menu Utama\n\t\tO : Logout\n\t\tE : Keluar\n");
    printf("\n\t\tPilih : ");
    scanf("%s",&pil2);
    if (pil2=='M'||pil2=='m') {
        return welcome();
    }
    else if (pil2=='O'||pil2=='o') {
        return main();
    }
    else if (pil2=='E'||pil2=='e') {
        return 0;
    }
    else {
        printf("\n\t\tERROR!!\n\n");
    }
}
void namars(){
    garis();
    printf("\n\t\t\t\t\t     RS. AIDA MEDIKA\n");
    garis();
}
void welcome(){
system("cls");
    namars();
    printf("\n\t\t\tSelamat Datang, %s.\n\n",user2);
    printf("\t\t\t1. Pasien\n");
    printf("\t\t\t2. Biaya Pengobatan\n");
    printf("\t\t\t3. Info Akun\n");
    printf("\t\t\t4. Logout Akun\n");
    printf("\t\t\t5. Keluar\n");
    garis();
    printf("\n\t\t\tPilih : ");
    scanf("%d",&pilih);
        switch(pilih){
            case 1:
                pasien();
            break;
            case 2:
                biaya();
            break;
            case 3:
                return info();
            break;
            case 4:
                return main();
            break;
            case 5:
                return 0;
            break;
            default:
                printf("\n\t\t\tERROR, Masukkan Pilihan Yang Tersedia!\n\n");
                system("pause");
                return welcome;
    }
}
void blokir(){
system("cls");
    namars();
    printf("\n\t\t==========================================================================");
    printf("\n\t\t\t\tANDA TELAH GAGAL SEBANYAK %dX, AKSES DIBLOKIR!!!\n", repeat);
    printf("\t\t==========================================================================");
    printf("\n\n\t\tUsername terakhir yang anda masukkan : %s \n",user2);
    printf("\t\tPassword terakhir yang anda masukkan : %s \n",pass2);
    printf("\n\t\tProgram akan keluar secara otomatis setelah anda menekan ENTER\n");
    garis();
return 0;
}
void back(){
    char pil;
    printf("\n\t\tB : Kembali \n\t\tO : Logout \n\t\tE : Keluar \n\n");
    printf("\t\tPilih : ");
    scanf("%s",&pil);
        if (pil=='B'||pil=='b'){
            welcome();
        }
        else if (pil=='O'||pil=='o'){
            main();
        }
        else if (pil=='E'||pil=='e'){
            return 0;
        }
        else {
        printf("\n\t\tERROR!!!\n\n");
        }
    system("pause");
    return 0;
}
void biaya(){
system("cls");
    namars();
    printf("\n\t\t\t\t\t  | BIAYA PENGOBATAN |\n");
    garis();
    printf("\t\tJenis Pelayanan\t\t\t\t\t|     Biaya");
    garis();
    printf("\n\t\tRawat Jalan (Per Kunjungan)\t\t\t|    Rp %d\n",rj);
    printf("\t\tRawat Inap kelas 3 (Per Hari)\t\t\t|    Rp %d\n",ri3);
    printf("\t\tRawat Inap kelas 2 (Per Hari)\t\t\t|    Rp %d\n",ri2);
    printf("\t\tRawat Inap kelas 1 (Per Hari)\t\t\t|    Rp %d\n",ri1);
    printf("\t\tBiaya Admin\t\t\t\t\t|    Rp %d\n",adm);
    printf("\t\tBiaya Konsultasi\t\t\t\t|    Rp %d\n",bk);
    garis();
    back();
}
void info() {
system ("cls");
    namars();
    printf("\n\t\t\tKamu login sebagai :\n\n");
    printf("\t\t\tUsername : %s\n",user2);
    printf("\t\t\tPassword : %s\n",pass2);
    garis();
    back();
}
void pasien() {
system("cls");
    namars();
    printf("\n\t\t\t1. Rawat Jalan\n");
    printf("\t\t\t2. Rawat Inap\n");
    printf("\t\t\t3. Kembali\n");
    printf("\t\t\t4. Keluar\n");
    garis();
    printf("\n\t\t\tPilih : ");
    scanf("%d", &pilih);
        switch (pilih) {
            case 1:
                r_jalan();
            break;
            case 2:
                r_inap();
            break;
            case 3:
                 welcome();
            break;
            case 4:
                return 0;
            break;
            default:
                printf("\n\t\t\tERROR, Masukkan pilihan yang tersedia!\n\n");
                system("pause");
                pasien();
        }
}
void r_jalan() {
system("cls");
    namars();
    printf("\n\t\t\t\t\t     | DATA PASIEN |\n\n");
    printf("\t\t\tNama                      : ");
    scanf("%s",&na);
    ulang:
    printf("\t\t\tJenis Kelamin (P/W)       : ");
    scanf("%s",&jk);
        if (jk=='P'||jk=='p'||jk=='W'||jk=='w'){
        }
        else {
        printf("\n\t\t\tMasukkan Kategori Yang Tersedia!!!\n\n");
        goto ulang;
        }
    printf("\t\t\tUmur                      : ");
    scanf("%d",&um);
    printf("\t\t\tTinggi Badan              : ");
    scanf("%d",&tb);
    printf("\t\t\tBerat Badan               : ");
    scanf("%d",&bb);
    ulangs:
    printf("\t\t\tGolongan Darah            : ");
    scanf("%s",&gd);
        if (gd=='A'||gd=='a'||gd=='B'||gd=='b'||gd=='AB'||gd=='ab'||gd=='O'||gd=='o'||gd=='-'){
        }
        else {
        printf("\n\t\t\tTidak Ada Manusia Dengan Golongan Darah Itu!!!\n\n");
        goto ulangs;
        }
    printf("\t\t\tDomisili                  : ");
    scanf("%s",&al);
    printf("\t\t\tPemeriksa                 : ");
    scanf("%s",&pe);
    printf("\t\t\tDiagnosa                  : ");
    scanf("%s",&di);
    balik:
    printf("\n\t\t\tApakah Kamu Mau Menebus Obat? (y/n) : ");
    scanf("%s",&to);
    if(to=='Y'||to=='y'){
        tebus_obat();}
    else if(to=='N'||to=='n'){
        rincian();}
    else{
        printf("\n\t\t\tPilihan Tidak Tersedia!\n");
        goto balik;
    }
    garis();
    rincian();
}
void rincian() {
system("cls");
char pil3;
    namars();
    printf("\n\t\t\t\t\t    | RINCIAN BIAYA | \n");
    printf("\t\t\tRawat Jalan\t\t\t\t     Rp %d\n",rj);
    printf("\t\t\tBiaya Konsultasi\t\t\t     Rp %d\n",bk);
    printf("\t\t\tBiaya Admin\t\t\t\t     Rp %d\n",adm);
    printf("\t\t\tBiaya Obat\t\t\t\t     Rp %d\n",total_pembelian);
    garis();
    printf("\n\t\t\tTotal \t\t\t\t\t     Rp %d\n",rj+bk+adm+total_pembelian);
    printf("\n\t\t\tPilih Metode Pembayaran : \n\t\t\t1. Bayar Menggunakan Asuransi\n\t\t\t2. Bayar Pribadi\n");
    printf("\n\t\t\tPilihan : ");
    scanf("%d",&mp);

        if (mp==1){
            harga=0;
            printf("\n\t\t\tJumlah Bayar\t\t\t\t      Rp %d\n",harga);
            printf("\t\t\tKarena seluruh biaya sudah ditanggung oleh pihak asuransi.\n");
        }
        else if (mp==2) {
            harga=rj+bk+adm+total_pembelian;
            printf("\n\t\t\tBiaya yang harus dibayar\t\t       Rp %d\n",harga);
            bayar:
            printf("\n\t\t\tJumlah Bayar\t\t\t\t       Rp ",jb);
            scanf("%d",&jb);
            if(jb<harga){
                printf("\n\t\t\tMaaf, uang Anda kurang.\n\t\t\tSilahkan ulangi pembayaran!\n");
                garis();
                goto bayar;
            }
            else{
                printf("\t\t\tKembali\t\t\t\t\t       Rp %d\n",jb-harga);
            }
        }
        else {
            printf("\n\t\tMetode Pembayaran Tidak Tersedia!!!\n\n");
        }
        garis();
        printf("\n\t\t\tP : Cetak Struk\n\t\t\tM : Menu Utama\n\t\t\tO : Logout\n\t\t\tE : Keluar\n");
        printf("\n\t\t\tPilih : ");
        scanf("%s",&pil3);
            if (pil3=='P'||pil3=='p') {
            return struk();}
            else if (pil3=='M'||pil3=='m') {
                welcome();}
            else if (pil3=='O'||pil3=='o') {
                main();}
            else if (pil3=='E'||pil3=='e') {
                return 0;}
            else {
            printf("\n\t\t\tERROR!!\n\n");}
        system("pause");
        return 0;
    }
void struk() {
    system("cls");
    FILE *fp;
    fp = fopen("ExcelDataRawatJalan.csv", "a");
    struct tm *Sys_T;
    time_t Unsika;
    Unsika = time(NULL);
    Sys_T = localtime(&Unsika); /* Untuk mendapatkan waktu lokal komputer */
    if(mp==1){
        kop_struk();
        printf("\n\t\t\t\t         | DATA PASIEN |\n\n");
        printf("\t\t\t\tNama            : %s\n",&na);
        printf("\t\t\t\tJenis Kelamin   : %s\n",&jk);
        printf("\t\t\t\tUmur            : %d\n",um);
        printf("\t\t\t\tTinggi Badan    : %d\n",tb);
        printf("\t\t\t\tBerat Badan     : %d\n",bb);
        printf("\t\t\t\tGolongan Darah  : %s\n",&gd);
        printf("\t\t\t\tDomisili        : %s\n",&al);
        printf("\t\t\t\tPemeriksa       : %s\n",&pe);
        printf("\t\t\t\tDiagnosa        : %s\n\n",&di);
        garis();
        printf("\n\t\t\t\t\t\t| STRUK |\n");
        garis();
        printf("\n\t\tRawat Jalan\t\t\t\t   Rp %d\n",rj);
        printf("\t\tBiaya Konsultasi\t\t\t   Rp %d\n",bk);
        printf("\t\tBiaya Admin\t\t\t\t   Rp %d\n",adm);
        printf("\t\tBiaya Obat\t\t\t\t   Rp %d\n",total_pembelian);
        garis();
        printf("\n\t\tTotal\t\t\t\t\t   Rp %d\n",rj+bk+adm+total_pembelian);
        printf("\t\tJumlah Bayar\t\t\t\t   Rp %d\n",jb);
        garis();

        //Program memasukkan data dari  terminal ke dalam file Excel
        if(fp == NULL){
            printf("file ngga bisa dibuka");
            system("pause");
            return 1;
        }
        fprintf(fp,"\n,%s,%s,%d,%d,%d,%s,%s,%s,%s,%d,%s",&na,&jk,um,tb,bb,&gd,&al,&pe,&di,bk+adm+total_pembelian,asctime (Sys_T));
        fclose(fp);
        fp = 0;
        balik();
        system("pause");
        return 0;
    }
    else if (mp==2){
        kop_struk();
        printf("\n\t\t\t\t         | DATA PASIEN |\n\n");
        printf("\t\t\t\tNama            : %s\n",&na);
        printf("\t\t\t\tJenis Kelamin   : %s\n",&jk);
        printf("\t\t\t\tUmur            : %d\n",um);
        printf("\t\t\t\tTinggi Badan    : %d\n",tb);
        printf("\t\t\t\tBerat Badan     : %d\n",bb);
        printf("\t\t\t\tGolongan Darah  : %s\n",&gd);
        printf("\t\t\t\tDomisili        : %s\n",&al);
        printf("\t\t\t\tPemeriksa       : %s\n",&pe);
        printf("\t\t\t\tDiagnosa        : %s\n\n",&di);
        garis();
        printf("\n\t\t\t\t\t\t| STRUK |\n");
        garis();
        printf("\n\t\tRawat Jalan\t\t\t\t\t\t   Rp %d\n",rj);
        printf("\t\tBiaya Konsultasi\t\t\t\t\t   Rp %d\n",bk);
        printf("\t\tBiaya Admin\t\t\t\t\t\t   Rp %d\n",adm);
        garis();
        printf("\n\t\tTotal\t\t\t\t\t\t\t   Rp %d\n",rj+bk+adm+total_pembelian);
        printf("\t\tJumlah Bayar\t\t\t\t\t\t   Rp %d\n",jb);
        printf("\t\tKembali\t\t\t\t\t\t\t   Rp %d\n",kembali(jb,rj,bk,adm,total_pembelian));
        garis();
        //Program memasukkan data dari  terminal ke dalam file Excel
        if(fp == NULL){
            printf("file ngga bisa dibuka");
            system("pause");
            return 1;
        }
        fprintf(fp,"\n%s,%s,%d,%d,%d,%s,%s,%s,%s,%d,%s",&na,&jk,um,tb,bb,&gd,&al,&pe,&di,bk+adm+total_pembelian,asctime (Sys_T));
        fclose(fp);
        fp = 0;
        balik();
    }
system("pause");
return 0;
}
void tebus_obat(){
system("cls");
    namars();
    printf("\t\t\t\t +============================================+\n");
    printf("\t\t\t\t |1. SANMOL TABLET         | 4. REDOXON       |\n");
    printf("\t\t\t\t |2. SANMOL SYRUP          | 5. ANTASIDA      |\n");
    printf("\t\t\t\t |3. METFORMIN             | 6. RVASK         |\n");
    printf("\t\t\t\t +============================================+\n");

    awal:
    while(a=='y'||a=='Y'){
        printf("\n\t\t\t\t MASUKKAN KODE OBAT KE-%d : ",i);
        scanf("%d",&kode);
        fflush(stdin);
        if(kode==1){
            obat = 5000 ;
            printf("\t\t\t\t |SANMOL TABLET = Rp %d          |",obat);
        }
        else if(kode==2){
            obat = 7000;
            printf("\t\t\t\t |SANMOL SYRUP = Rp %d          |",obat);
        }
        else if(kode==3){
            obat = 12000;
            printf("\n\t\t\t\t |METFORMIN = Rp %d          |",obat);
        }
        else if(kode==4){
            obat = 3000;
            printf("\t\t\t\t |REDOXON = Rp %d          |",obat);
        }
        else if(kode==5){
            obat = 6000;
            printf("\t\t\t\t |ANTASIDA = Rp %d          |",obat);
        }
        else if(kode==6){
            obat = 8000;
            printf("\t\t\t\t |RVASK = Rp %d          |",obat);
        }
        else{
            printf("\n\t\t\t\t |KODE OBAT TIDAK TERDAFTAR          |\n");
            goto awal;
        }
        total_pembelian=total_pembelian+obat;
        printf("\n\t\t\t\t |APAKAH MAU MENAMBAH OBAT YANG DI BELI? (y/n) : ");
        scanf("%c",&a);
        i++;
        }
        rincian();
}
void r_inap() {
system("cls");
    namars();
    printf("\n\t\t\t\t           | DATA PASIEN |\n\n");
    printf("\t\t\tNama                      : ");
    scanf("%s",&na2);
    ulanglagi:
    printf("\t\t\tJenis Kelamin (P/W)       : ");
    scanf("%s",&jk2);
        if (jk2=='P'||jk2=='p'||jk2=='W'||jk2=='w'){
        }
        else {
        printf("\n\t\t\tMasukkan Kategori Yang Tersedia!!!\n\n");
        goto ulanglagi;
        }
    printf("\t\t\tUmur                      : ");
    scanf("%d",&um2);
    printf("\t\t\tTinggi Badan              : ");
    scanf("%d",&tb2);
    printf("\t\t\tBerat Badan               : ");
    scanf("%d",&bb2);
    ulangi:
    printf("\t\t\tGolongan Darah            : ");
    scanf("%s",&gd2);
        if (gd2=='A'||gd2=='a'||gd2=='B'||gd2=='b'||gd2=='AB'||gd2=='ab'||gd2=='O'||gd2=='o'||gd2=='-'){
        }
        else {
        printf("\n\t\t\tTidak Ada Manusia Dengan Golongan Darah Itu!!!\n\n");
        goto ulangi;
        }
    printf("\t\t\tDomisili                  : ");
    scanf("%s",&al2);
    printf("\t\t\tPemeriksa                 : ");
    scanf("%s",&pe2);
    printf("\t\t\tDiagnosa                  : ");
    scanf("%s",&di2);
    printf("\t\t\tLama Menginap (hari)      : ");
    scanf("%d",&li);
    printf("\n\t\t\tPilihan 1 = Kelas 1/VVIP      Rp 1.000.000");
    printf("\n\t\t\tPilihan 2 = Kelas 2/VIP       Rp 750.000");
    printf("\n\t\t\tPilihan 3 = Kelas 3/Standart  Rp 500.000");

    printf("\n\n\t\t\tPilih Kelas Rawat Inap : ");
    scanf("%d", &kls);
    if (kls==1){
            harga=1000000;
            printf("\nHARGA KELAS : Rp %d\n\n",harga);
        }
        else if (kls==2) {
            harga=750000;
            printf("\nHARGA KELAS : Rp %d\n\n",harga);
        }
        else if (kls==3) {
            harga=500000;
            printf("\nHARGA KELAS : Rp %d\n\n",harga);
        }
        else {
            printf("\nERROR!!\n\n");
        }
    total_biaya=li*harga;
    garis();
    rincian2();
}
void rincian2() {
    system("cls");
    char pil3;
        namars();
        printf("\n\t\t\t\t\t    | RINCIAN BIAYA | \n\n");
        printf("\t\tRawat Inap %d Hari x %d Harga Kelas\t\t     Rp %d\n",li,harga,total_biaya);
        printf("\t\tBiaya Konsultasi\t\t\t\t     Rp %d\n",bk2);
        printf("\t\tBiaya Admin\t\t\t\t\t     Rp %d\n",adm2);
        garis();
        printf("\n\t\tTotal\t\t\t\t\t\t     Rp %d\n\n",bk2+adm2+total_biaya+total_pembelian2);

        printf("\t\tPilih Metode Pembayaran : \n\t\t1. Bayar Menggunakan Asuransi\n\t\t2. Bayar Pribadi\n\n");
        printf("\t\tPilihan : ");
        scanf("%d",&mp);

        if (mp==1){
            harga=0;
            printf("\n\t\tJumlah Bayar\t\t\t\t\t     Rp %d\n",harga);
            printf("\t\tKarena seluruh biaya sudah ditanggung oleh pihak asuransi.\n");
        }
        else if (mp==2) {
            harga=bk2+adm2+total_biaya+total_pembelian2;
            printf("\n\t\tBiaya yang harus dibayar  \t\t\t     Rp %d\n",harga);
            bayar:
            printf("\n\t\tJumlah Bayar\t\t\t\t\t     Rp ",jb2);
            scanf("%d",&jb2);
           if(jb2<harga){
                printf("\n\t\tMaaf, uang Anda kurang.\n\t\tSilahkan ulangi pembayaran!\n");
                garis();
                goto bayar;
            }
            else{
                printf("\t\tKembali\t\t\t\t\t\t     Rp %d\n",jb2-harga);
            }
        }
        else {
            printf("\nMetode pembayaran tidak tersedia!!!\n\n");
        }
        garis();
        printf("\n\t\tP : Cetak Struk\n\t\tM : Menu Utama\n\t\tO : Logout\n\t\tE : Keluar\n\n");
        printf("\t\tPilih : ");
        scanf("%s",&pil3);
            if (pil3=='P'||pil3=='p') {
                struk2();
            }
            else if (pil3=='M'||pil3=='m') {
                welcome();
            }
            else if (pil3=='O'||pil3=='o') {
                main();
            }
            else if (pil3=='E'||pil3=='e') {
                return 0;
            }
            else {
            printf("\n\t\tERROR!!!\n\n");
            }
        system("pause");
        return 0;
    }
void struk2() {
    system("cls");
    FILE *fp;
    fp = fopen("ExcelDataRawatInap.csv", "a");
    struct tm *Sys_T;
    time_t Unsika;
    Unsika = time(NULL);
    Sys_T = localtime(&Unsika); /* Untuk mendapatkan waktu lokal komputer */

    if(mp==1){
        kop_struk();
        printf("\n\t\t\t\t         | DATA PASIEN |\n\n");
        printf("\t\t\t\tNama            : %s\n",&na2);
        printf("\t\t\t\tJenis Kelamin   : %s\n",&jk2);
        printf("\t\t\t\tUmur            : %d\n",um2);
        printf("\t\t\t\tTinggi Badan    : %d\n",tb2);
        printf("\t\t\t\tBerat Badan     : %d\n",bb2);
        printf("\t\t\t\tGolongan Darah  : %s\n",&gd2);
        printf("\t\t\t\tDomisili        : %s\n",&al2);
        printf("\t\t\t\tPemeriksa       : %s\n",&pe2);
        printf("\t\t\t\tDiagnosa        : %s\n\n",&di2);
        garis();
        printf("\n\t\t\t\t\t      | STRUK |\n");
        garis();
        printf("\n\t\tRawat Inap %d Hari \t\t\t\t   Rp %d\n",li,total_biaya);
        printf("\t\tBiaya Konsultasi\t\t\t\t   Rp %d\n",bk2);
        printf("\t\tBiaya Admin\t\t\t\t\t   Rp %d\n",adm2);
        printf("\t\tBiaya Obat\t\t\t\t\t   Rp %d\n",total_pembelian2);
        garis();
        printf("\n\t\tTotal\t\t\t\t\t\t    Rp %d\n",bk2+adm2+total_biaya+total_pembelian2);
        printf("\t\tJumlah Bayar\t\t\t\t\t    Rp %d\n",jb2);
        garis();

        //Program memasukkan data dari  terminal ke dalam file Excel
        if(fp == NULL){
            printf("file ngga bisa dibuka");
            system("pause");
            return 1;
        }
        fprintf(fp,"\n,%s,%s,%d,%d,%d,%s,%s,%s,%s,%d,%s",&na2,&jk2,um2,tb2,bb2,&gd2,&al2,&pe2,di2,bk2+adm2+total_biaya+total_pembelian2,asctime (Sys_T));
        fclose(fp);
        fp = 0;
        balik();
        system("pause");
        return 0;
    }
    else if (mp==2){
        kop_struk();
        printf("\n\t\t\t\t         | DATA PASIEN |\n\n");
        printf("\t\t\t\tNama            : %s\n",&na2);
        printf("\t\t\t\tJenis Kelamin   : %s\n",&jk2);
        printf("\t\t\t\tUmur            : %d\n",um2);
        printf("\t\t\t\tTinggi Badan    : %d\n",tb2);
        printf("\t\t\t\tBerat Badan     : %d\n",bb2);
        printf("\t\t\t\tGolongan Darah  : %s\n",&gd2);
        printf("\t\t\t\tDomisili        : %s\n",&al2);
        printf("\t\t\t\tPemeriksa       : %s\n",&pe2);
        printf("\t\t\t\tDiagnosa        : %s\n\n",&di2);
        garis();
        printf("\n\t\t\t\t\t      | STRUK |\n");
        garis();
        printf("\n\t\tRawat Inap %d Hari \t\t\t\t\t   Rp %d\n",li,total_biaya);
        printf("\t\tBiaya Konsultasi\t\t\t\t\t   Rp %d\n",bk2);
        printf("\t\tBiaya Admin\t\t\t\t\t\t   Rp %d\n",adm2);
        garis();
        printf("\n\t\tTotal\t\t\t\t\t\t\t   Rp %d\n",bk2+adm2+total_biaya+total_pembelian2);
        printf("\t\tJumlah Bayar\t\t\t\t\t\t   Rp %d\n",jb2);
        printf("\t\tKembali\t\t\t\t\t\t\t   Rp %d\n",jb2-(total_biaya+bk2+adm2+total_pembelian2));
        garis();

        if(fp == NULL){
            printf("file ngga bisa dibuka");
            system("pause");
            return 1;
        }
        fprintf(fp,"\n,%s,%s,%d,%d,%d,%s,%s,%s,%s,%d,%s",&na2,&jk2,um2,tb2,bb2,&gd2,&al2,&pe2,di2,bk2+adm2+total_biaya+total_pembelian2,asctime (Sys_T));
        fclose(fp);
        balik();
    }
system("pause");
return 0;
}

int kembali(int jb,int rj,int bk,int adm,int total_pembelian){
int result;
result=jb-(rj+bk+adm+total_pembelian);
return result;
}
