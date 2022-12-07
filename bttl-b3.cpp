#include <iostream>
#include <string.h>
using namespace std;

//----Ham khai bao bien nhap danh sach quan ly cua hang----
typedef struct khachhang
{
    int MaKH;
    char tenKH[20];
    int Matruyen;
    char tentruyen[30];
    float giathue;
    //float giadatcoc;
    int dd, mm, yyyy;
    int dd1, mm1, yyyy1;
}khach;

//----Khai bao cau truc cua 1 node trong queue----
typedef struct ptrnode
{
    khach info; //node queue chua cac thong tin da nhap vao danh sach
    struct ptrnode* pnext; //con tro de lien ket cac node danh sach thong tin voi nha
}Node, * node;

//----Khai bao cau truc cua queue----
typedef struct QUeue
{
	//dung node dau va node cuoi cua danh sach thong tin cac quyen truyen
    node phead; //khai bao node dau
    node ptail; //khai bao node cuoi
    
}queue;

//----Ham khoi tao node----
void init(queue& q)
{
    q.phead = NULL; //cho node dau bang NULL la bang rong
    q.ptail = NULL;//cho node cuoi bang NULL la bang rong
}

//----Ham Kiem tra queue co rong hay khong----
bool isempty(queue q)
{
    if (q.phead == NULL) //neu node dau rong thi tra ve null
        return true; //sau do tra ve true
    return false; //con neu node khong rong thi tra ve false
}

//----Ham khoi tao 1 cai node----
node createnode(khach kh)
{
    node p = new Node; //cap phat vung nho cho node p
    if (p == NULL)  //de luu y nguoi dung khi bo nho may khong du de cap phat 
    			   // cho viec tao node moi
    {
        cout << "\nKhong du bo nho de cap phat!";
        return NULL;
    }
    p->info = kh; //truyen thong tin khach hang cho thue cho info
    p->pnext = NULL; //dau tien khai bao node thi node do chua lien ket den node nao het
    				 //=>con tro cua no se tro den NULL
	return p;//tra ve node p vua khoi tao
}


//'---Ham them danh sach dau vao cuoi node p----
bool push(queue& q, node p)
{
    if (p == NULL)
    {
        return false;
    }
    //neu danh sach rong
    if (isempty(q) == true)
    {
        q.phead = q.ptail = p; //node p chinh la node dau va node cuoi
    }
    else //danh sach da co phan tu
    {
        q.ptail->pnext = p; //lien ket con tro cuoi cua danh sach voi phan tu p can them vao
        q.ptail = p; //cap nhat lai con tro cuoi la node p
    }
    return true;
}

//----Ham lay thong tin danh sach dau queue va huy no di-----
bool pop(queue& q, khach &kh) //kh la gia tri can lay trong node
{
    //neu danh sach rong
    if (isempty(q) == true)
    {
        return false;
    }
    else // danh sach da co phan tu
    {
        node p = q.phead; //node p chinh la node the de xoa no di
        kh = p->info; //gan gia tri o node dau queue la node tiep theo
        q.phead = q.phead->pnext; //cap nhap node dau queue la node tiep theo
        delete p;
    }
    return true;
}

//----Ham Nhap Thong Tin cua 1 khach hang da cho thue truyen----
void nhap1kh(khach& kh)
{
    //int n;
    cout << "nhap Ma Khach Hang: ";
    cin >> kh.MaKH;

    cout << "\nnhap ho ten khach hang: ";
    cin.ignore(1);
    cin.getline(kh.tenKH, 20);

    cout << "\nNhap Ma Truyen: ";
    cin >> kh.Matruyen;

    cout << "\nNhap Ten truyen: ";
    cin.ignore(1);
    cin.getline(kh.tentruyen, 30);

    cout << "\nGia cho thue: ";
    cin >> kh.giathue;

    cout << "\nNhap ngay thang nam thue: ";
    cin >> kh.dd >> kh.mm >> kh.yyyy;

    cout << "\nNhap ngay thang nam tra: ";
    cin >> kh.dd1 >> kh.mm1 >> kh.yyyy1;
}

//----Ham xuat thong tin cua 1 khach hang----
void xuat1kh(khach kh)
{
    cout << "\nMaKH: " << kh.MaKH << " ";
    cout << "\nHo Ten Khach Hang la: " << kh.tenKH << " ";
    cout << "\nMa Truyen " << kh.Matruyen << " ";
    cout << "\nTen Truyen " << kh.tentruyen << " ";
	cout << "\nGia cho Thue: " << kh.giathue << " ";
    cout << "\nNgay thang nam Thue: " << kh.dd << "/" << kh.mm << "/" << kh.yyyy << " ";
    cout << "\nNgay thang nam Tra: " << kh.dd1 << "/" << kh.mm1 << "/" << kh.yyyy1 << " ";
}

//----Ham xuat danh sach cac khach hang cho thue----
void xuatds(queue q)
{
	//dau tien cho p la danh sach dau tien
	//ham duyet tu dau den cuoi danh sach p
	//gap danh sach p nao bang null se dung 
	for(node p = q.phead; p!=NULL; p = p->pnext)
	{
		xuat1kh(p->info);
		cout << endl;
	}
}

//----Khai bao ham hoan vi de su dung cho chuc nang quan li danh sach----
void hoanvi(khach &a, khach &b) 
{
	khach t = a; //khai bao 1 bien tam va truyen thong tin dau vao bien tam do
	a = b; //cap nhap lai thong tin sau len thong tin dau
	b = t; //cap lai thong tin dau vua khai bao o bien tam ra thong tin phia sau
}

//----Ham chuc nang tim thong tin theo ma khach hang thue de xoa no di----
void xoa(queue q, int x)
{
	//vi la dung queue nen phai cap nhat thong tin can xoa len dau
    for (node p = q.phead; p != NULL; p = p->pnext)//duyet danh sach cho toi khi cuoi 
    											   //danh sach co gia tri NULL
    {
        if (p->info.MaKH == x)//Neu ma khach hang nhap trung voi thong tin dang duyet
        {
        	hoanvi(q.phead->info, p->info);//thi dua no len dau(vi la dung queue nen
										   //nen muon xoa phai cap nhat len dau danh sach)
        }
    }
    //sau khi thu hien duoi ham main goi lai ham pop de xoa no di
}

//----Ham chuc nang tim kiem thong tin khach hang theo ten(ten nhap tu ban phim)----
void search1(queue q, char y[20])
{
    for (node p = q.phead; p != NULL; p = p->pnext)//duyet danh sach cho toi khi cuoi 
    {											   //danh sach co gia tri NULL
        if (strcmp(y, p->info.tenKH) == 0)//Neu thong tin danh sach co ten 
        {								  //trung voi gia tri nhap vao
        	xuat1kh(p->info);//thi xuat thong tin do ra
        }
    }
}

//----Ham chuc nang sap xep thong tin khach hang theo ma khach hang----
void sort(queue &q)
{
	for(node k = q.phead; k != NULL; k= k->pnext)
	{
		for(node h = q.phead; h != NULL; h = h->pnext)//vi la danh sach lien ket don nen khi khai bao k, q la danh sach dau
													  //no se lay tung node co gia tri ma khach hang di so sanh voi nhau
		{
			if(k->info.MaKH < h->info.MaKH)
			{
				hoanvi(k->info, h->info); //cai node nao co thong tin ma khach hang nho hon thi se dua len dau 
			}
		}
	}
}

//----Khai bao ham main de thuc hien cac chuc nang----
int main()
{
    queue q;
    khach kh;
    init(q);
    int key;
    cout << endl;
    do
    {
        cout << "\n*************************MENU*************************\n";
        cout << "** 0. Thoat                                           **\n";
        cout << "** 1. Them 1 khach hang.                              **\n";
        cout << "** 2. Xuat Danh Sach Khach Hang.                      **\n";
        cout << "** 3. Tim Khach Hang Theo Ten Khach Hang.             **\n";
        cout << "** 4. Xoa Khach Hang Theo Ma Khach Hang.              **\n";
        cout << "** 5. Sap xep danh sach tang dan theo Ma Khach Hang.  **\n";
        cout << "********************************************************\n";
        cout << "\nNhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 0:break;
        case 1:
        {
            system("cls");//Lenh nay chi de xoa man hinh, de khi chay trong man hinh console se do roi mat hon
            nhap1kh(kh);
            node p = createnode(kh);
            push(q, p);
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n==========Danh Sach Thong Tin Khach Hang Cho Thue Truyen==========\n";
            xuatds(q);
            break;
        }
        case 3:
        {
            system("cls");
            cin.ignore();
            char y[20];
            cout << "Nhap Ten Khach Hang muon tim: ";
            cin.getline(y, 20);
            search1(q, y);
            break;
        }
        case 4:
        {
            system("cls");
            int x;
            cout << "\nNhap Ma Khach Hang tra truyen: ";
            cin >> x;
            xoa(q, x);
            pop(q,kh);
            cout << "\nDa xoa thong tin khach hang tra sach, vui long nhap 2 lai de kiem tra!";
            break;
        }
        case 5:
		{
			system("cls");
			sort(q);
    		cout << "\nDanh Sach Sau Khi Sap Xep La\n";
    		xuatds(q);
    		break;
		}

        default: cout << "\nNhap Lai!";
        }
    } while (key);
    return 0;
}

