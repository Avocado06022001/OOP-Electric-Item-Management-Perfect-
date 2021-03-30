#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<fstream>

class thongtinkhachhang{
protected:
    string makhachhang;
    string tenkhachhang;
    string sodienthoai;
    string diachi;
public:
    void setInformation(){
        cout<<"Thong tin khach hang: "<<endl;
        cout<<"Ma khach hang: ";
        cin>>this->makhachhang;
        cout<<"Ten khach hang: ";
        cin>>this->makhachhang;
        cout<<"So dien thoai: ";
        cin>>this->sodienthoai;
        cout<<"Dia chi: ";
        cin>>this->diachi;
    }
    string outputkhachhang(){
        string output;
        output="Thong tin khach hang: "+makhachhang+" "+tenkhachhang+" "+diachi+" "+sodienthoai+"\n";
        return output;
    }
};

class ngaythangnam{
protected:
    int ngay;
    int thang;
    int nam;
public:
    void setNgaythangnam(){
        cout<<"Nhap ngay lap hoa don: ";
        cin>>this->ngay>>this->thang>>this->nam;
    }
    string outputngaythangnam(){
        string output;
        output=to_string(ngay)+"/"+to_string(thang)+"/"+to_string(nam);
        return output;
    }
};

class mayquat{
protected:
    string masanpham;
    string tensanpham;
    double giaban;
    string noisanxuat;
    string loaimayquat;
    double sosanpham;
public:
    void setThongtin(){
        cout<<"Nhap ma: ";
        cin>>this->masanpham;
        cout<<"Ten san pham: ";
        cin>>this->tensanpham;
        cout<<"Noi san xuat: ";
        cin>>this->noisanxuat;
        cout<<"So luong ban ra: ";
        cin>>this->sosanpham;
    }
    double giabansanpham();

    string outputmayquat(){
        string out;
        out="May quat: "+masanpham+" "+loaimayquat+" "+tensanpham+" "+noisanxuat+" "+to_string(giaban);
        return out;
    }

};

class mayquatdung:public mayquat{
public:
    void setThongtin(){
        mayquat::setThongtin();
        this->giaban=500;
        this->loaimayquat="may quat dung";
    }
    double giabansanpham(){
        return this->giaban * this->sosanpham;
    }
    string outputmayquat(){
        return mayquat::outputmayquat()+" "+to_string(sosanpham)+"\n";
    }
};

class mayquathoinuoc:public mayquat{
protected:
    double dungtich;
public:
    void setThongtin(){
        mayquat::setThongtin();
        cout<<"Dung tich nuoc: ";
        cin>>this->dungtich;
        this->loaimayquat="may quat hoi nuoc";
        this->giaban=400*this->dungtich;
    }
    double giabansanpham(){return this->giaban * this->sosanpham;}
    string outputmayquat(){
        return mayquat::outputmayquat()+" "+to_string(dungtich)+" "+to_string(sosanpham)+"\n";
    }
};

class mayquatdien:public mayquat{
protected:
    double dungluong;
public:
    void setThongtin(){
        mayquat::setThongtin();
        cout<<"Dung luong pin: ";
        cin>>this->dungluong;
        this->loaimayquat="may quat dien";
        this->giaban=500*this->dungluong;
    }
    double giabansanpham(){return this->giaban * this->sosanpham;}
    string outputmayquat(){
        return mayquat::outputmayquat()+" "+to_string(dungluong)+" "+to_string(sosanpham)+"\n";
    }
};


class maylanh{
protected:
    string masanpham;
    string tensanpham;
    double giaban=0;
    string noisanxuat;
    double sosanpham;
    string loaimaylanh;
    int sudungcongngheinverter;
    int sudungcongnghekhangkhuan;
    int sudungcongnghekhumui;
public:
    void setThongtin(){
        cout<<"Nhap ma: ";
        cin>>this->masanpham;
        cout<<"Ten san pham: ";
        cin>>this->tensanpham;
        cout<<"Noi san xuat: ";
        cin>>this->noisanxuat;
        cout<<"So luong ban ra: ";
        cin>>this->sosanpham;
        cout<<"Co su dung cong nghe inverter khong (1-co, 2-khong): ";
        cin>>this->sudungcongngheinverter;
        cout<<"Co su dung cong nghe khu mui khong (1-co, 2-khong): ";
        cin>>this->sudungcongnghekhumui;
        if (this->sudungcongnghekhumui==1){this->giaban+=500;}
        cout<<"Co su dung cong nghe khang khuan khong (1-co, 2-khong): ";
        cin>>this->sudungcongnghekhangkhuan;
        if (this->sudungcongnghekhangkhuan==1){this->giaban+=500;}
    }

    double giabansanpham();

    string outputmaylanh(){
        string out;
        out="May lanh: "+masanpham+" "+loaimaylanh+" "+tensanpham+" "+noisanxuat+" "+to_string(giaban);
        if (this->sudungcongngheinverter==1){out+=" su dung inverter ";}
        else{out+=" khong su dung inverter ";}
        if (this->sudungcongnghekhangkhuan==1){out+=" su dung cong nghe khang khuan ";}
        else{out+=" khong su dung cong nghe khang khuan ";}
        if (this->sudungcongnghekhumui==1){out+=" su dung cong nghe khang khuan ";}
        else{out+=" khong su dung cong nghe khang khuan ";}
        out+=to_string(sosanpham);
        out+="\n";
        return out;
    }

};

class maylanhmotchieu:public maylanh{
public:
    void setThongtin(){
        maylanh::setThongtin();
        if (this->sudungcongngheinverter==1){this->giaban+=1500;}
        else{this->giaban+=1000;}
        this->loaimaylanh="may lanh mot chieu";
    }
    double giabansanpham(){return this->giaban*this->sosanpham;}
};

class maylanhhaichieu:public maylanh{
public:
    void setThongtin(){
        maylanh::setThongtin();
        if (this->sudungcongngheinverter==1){this->giaban+=2500;}
        else{this->giaban+=2000;}
        this->loaimaylanh="may lanh hai chieu";
    }
    double giabansanpham(){return this->giaban * this->sosanpham;}
};

class hoadon{
protected:
    int sohoadonchitiet;
    string mahoadon;
    double tongtien;
    string thongtintong;
public:
    void setSohoadon(){
        double sum=0;
        string thongtinhoadon;
        int num, num1;
        cout<<"Ma hoa don: ";
        cin>>this->mahoadon;
        ngaythangnam date;
        date.setNgaythangnam();
        thongtinkhachhang tt;
        tt.setInformation();
        thongtinhoadon+=(tt.outputkhachhang());
        thongtinhoadon+=(date.outputngaythangnam()+" ");
        cout<<"Nhap danh sach chi tiet cac hoa don: "<<endl;
        cout<<"So luong chi tiet trong danh sach cac chi tiet hoa don: ";
        cin>>this->sohoadonchitiet;
        cout<<endl;
        for (int j=1; j<=sohoadonchitiet; j++){
            cout<<"Nhap chi tiet hoa don thu "<<j<<endl;
            cout<<"Chon loai thiet bi dien (1-may quat, 2-may lanh): ";
            cin>>num;
            if (num==1){
                cout<<"Chon loai may quat (1-may quat dung, 2-may quat hoi nuoc, 3-may quat dien): ";
                cin>>num1;
                if (num1==1){
                    mayquatdung m1;
                    m1.setThongtin();
                    sum+=m1.giabansanpham();
                    thongtinhoadon+=m1.outputmayquat();
                }else if (num1==2){
                    mayquathoinuoc m2;
                    m2.setThongtin();
                    sum+=m2.giabansanpham();
                    thongtinhoadon+=m2.outputmayquat();
                }else{
                    mayquatdien m3;
                    m3.setThongtin();
                    sum+=m3.giabansanpham();
                    thongtinhoadon+=m3.outputmayquat();
                }
            }else{
                cout<<"Chon loai may lanh (1-may lanh 1 chieu, 2-may lanh 2 chieu): ";
                cin>>num1;
                if (num1==1){
                    maylanhmotchieu l1;
                    l1.setThongtin();
                    sum+=l1.giabansanpham();
                    thongtinhoadon+=l1.outputmaylanh();
                }else{
                    maylanhhaichieu l2;
                    l2.setThongtin();
                    sum+=l2.giabansanpham();
                    thongtinhoadon+=l2.outputmaylanh();
                }
            }
        }
        this->tongtien=sum;
        this->thongtintong=thongtinhoadon;
    }
    double getTongtien(){return this->tongtien;}
    string getTongthongtin(){return this->thongtintong;}
    ~hoadon(){}
};

class Quanly{
protected:
    vector<hoadon*>list;
public:
    void addEntity(hoadon* h){
        list.push_back(h);
    }
    double tongthunhap(){
        double sum=0;
        for (int i=0; i<list.size(); i++){
            sum+=list[i]->getTongtien();
        }
        return sum;
    }
};

int main(){
    ofstream file("Danh_sach_hoa_don.txt");
    int soluonghoadon;
    Quanly q;
    cout<<"So luong hoa don muon nhap: ";
    cin>>soluonghoadon;
    for (int i=1; i<=soluonghoadon; i++){
        cout<<"Nhap thong tin hoa don "<<i<<endl;
        hoadon* h1=new(hoadon);
        h1->setSohoadon();
        file<<h1->getTongthongtin();
        q.addEntity(h1);
    }
    cout<<"Here is all the money you gain: ";
    cout<<q.tongthunhap();
    file.close();
}
