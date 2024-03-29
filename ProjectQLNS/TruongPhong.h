#pragma once
#include "NhanSu.h"
#include "NhanVienThuong.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
class NhanVienThuong;

class TruongPhong : public NhanSu
{
private:
  int soLuongNhanVien;
  vector<NhanVienThuong *> listNV;
  string maPhongBan;
  void setSoLuongNhanVien(int soLuongNhanVien);
  int getSoLuongNhanVien();

public:
  TruongPhong();
  TruongPhong(string maSo,
              string hoTen,
              string soDienThoai,
              float soNgayLamViec);
  vector<NhanVienThuong *> &getListNV();
  string getMaSo();
  string getTenTP();
  void setListNV(vector<NhanVienThuong *> listNV);
  void setMaPhongBan(string maPhongBan);
  void nhap();
  void xuat();
  void tangNhanVien();
  void giamNhanVien();
  void tinhLuong();
  // friend istream &operator>>(istream &is, TruongPhong &tp);
  friend ostream &operator<<(ostream &os, const TruongPhong &tp);
  string getMaPhongBan();
  void xuatMaVaTen();
};