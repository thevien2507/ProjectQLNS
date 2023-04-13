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

public:
  TruongPhong();
  TruongPhong(string maSo,
              string hoTen,
              string soDienThoai,
              float soNgayLamViec);
  vector<NhanVienThuong *> &getListNV();
  string
  getMaSo();
  string getTenTP();
  void nhap();
  void xuat();
  void tangNhanVien();
  void giamNhanVien();
  void tinhLuong();
  // friend istream &operator>>(istream &is, TruongPhong &tp);
};