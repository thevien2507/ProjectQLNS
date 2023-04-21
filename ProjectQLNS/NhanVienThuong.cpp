#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

// istream &operator>>(istream &is, NhanVienThuong &nvt)
// {
//   // Read data from the input stream and populate the ns object
//   is >> nvt.hoTen >> nvt.maSo >> nvt.soDienThoai >> nvt.soNgayLamViec;
//   return is;
// }

string NhanVienThuong::getMaPhongBan()
{
  return maPhongBan;
}

void NhanVienThuong::setMaPhongBan(string maPhongBan)
{
  this->maPhongBan = maPhongBan;
}

NhanVienThuong::~NhanVienThuong()
{
  delete[] tp;
}

TruongPhong *NhanVienThuong::getTruongPhong()
{
  return tp;
}

// ostream &operator<<(ostream &os, const NhanVienThuong &nvt)
// {
//   os << "Ho ten: " << nvt.hoTen << endl;
//   os << "Ma so: " << nvt.maSo << endl;
//   os << "So dien thoai: " << nvt.soDienThoai << endl;
//   os << "So ngay lam viec: " << nvt.soNgayLamViec << endl;
//   if (nvt.tp != nullptr)
//   {
//     os << "___________Thong tin nguoi quan ly__________" << endl;
//     os << "Ho ten truong phong: " << nvt.tp->getHoTen() << endl;
//     os << "Ma so truong phong: " << nvt.tp->getMaSo() << endl;
//   }
//   if (nvt.maPhongBan != "")
//   {
//     os << "Ma phong ban: " << nvt.maPhongBan << endl;
//   }
//   os << endl;
//   return os;
// }

ostream &operator<<(ostream &os, const NhanVienThuong &nvt)
{
  os << nvt.maSo << "\t" << nvt.hoTen << "\t" << nvt.soDienThoai << "\t" << nvt.soNgayLamViec << "\t" << nvt.luong << "\t";
  if (nvt.maPhongBan != "")
  {
    os << nvt.maPhongBan << "\t";
  }
  else
  {
    os << "\t";
  }
  if (nvt.tp != nullptr)
  {
    os << nvt.tp->getHoTen() << "\t" << nvt.tp->getMaSo() << "\t";
  }
  return os;
}

void NhanVienThuong::setTruongPhong(TruongPhong *tp)
{
  this->tp = tp;
}

NhanVienThuong::NhanVienThuong()
{
  tp = nullptr;
  maPhongBan = "";
}

NhanVienThuong::NhanVienThuong(string maSo, string hoTen, string soDienThoai, float soNgayLamViec) : NhanSu(maSo, hoTen, soDienThoai, soNgayLamViec)
{
}

void NhanVienThuong::tinhLuong()
{
  this->luong = luong1NgayNVT * this->soNgayLamViec;
}

void NhanVienThuong::nhap()
{
  NhanSu::nhap();
}

void NhanVienThuong::xuat()
{
  NhanSu::xuat();
  cout << "\t\t\t|Luong\t\t\t| " << this->luong << "\t\t|" << endl;

  if (maPhongBan != "")
  {
    cout << "\t\t\t|Ma phong ban\t\t| " << this->maPhongBan << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;
  }
  if (tp != nullptr)
  {
    cout << "\t\t\t|____Day la thong tin nguoi quan ly____"
         << "\t|" << endl;
    cout << "\t\t\t|Ten truong phong\t| " << tp->getHoTen() << "\t\t|" << endl;
    cout << "\t\t\t|Ma truong phong\t| " << tp->getMaSo() << "\t\t|" << endl;
    cout << "\t\t\t_________________________________________" << endl;

    // output << "Luong:"
    //        << "\t" << this->luong << endl;
    // output << "___________Thong tin nguoi quan ly__________" << endl;
    // output << "Ten truong phong: "
    //        << "\t" << this->hoTen << endl;
    // output << "Ma truong phong:"
    //        << "\t" << this->getMaSo() << endl;
    // output << endl;
  }
}
