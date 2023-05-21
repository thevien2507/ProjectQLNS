#include "DanhSachPhongBan.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

vector<PhongBan *> &DanhSachPhongBan::getDsPhongBan()
{
  return dsPhongBan;
}

void DanhSachPhongBan::setDsPhongBan(vector<PhongBan *> dsPhongBan)
{
  this->dsPhongBan = dsPhongBan;
}

void DanhSachPhongBan::nhapPB()
{
  int n;
  cout << "\t\t\t\tNhap so luong phong ban: ";
  cin >> n;
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i = 0; i < n; i++)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\tNhap phong ban thu " << i + 1 << " ✍️" << endl;
    SetConsoleTextAttribute(color, 7);
    PhongBan *pb = new PhongBan();
    pb->nhapPB();
    dsPhongBan.push_back(pb);
  }
  SetConsoleTextAttribute(color, 10);
  cout << "\t\t\t\tDa nhap xong phong ban ✅" << endl;
  SetConsoleTextAttribute(color, 7);
}

void DanhSachPhongBan::xuatPB()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (dsPhongBan.size() == 0)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tChua co phong ban nao trong cong ty ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
  else
  {
    int cyan = 11;
    int brightYellow = 14;
    int darkWhite = 7;
    cout << "                                      ╔═════════════════════════════════╗\n";
    cout << "                                      ║ ";
    SetConsoleTextAttribute(color, cyan);
    cout << "   Thong tin phong ban  📂   ";
    SetConsoleTextAttribute(color, 7);
    cout << "   ║                \n";
    cout << "╔═══════════╦══════════════╦══════════╩═══════╦══════════════════════╦══╩═════════════════════════════════╦══════════════════════════════════════════════╗\n";
    cout << "║ ";
    cout << "          ";
    cout << "║ ";
    cout << "             ";
    cout << "║   ";
    cout << "               ";
    cout << "║   ";
    cout << "                   ";
    cout << "║    ";
    SetConsoleTextAttribute(color, cyan);
    cout << " Thong tin nguoi quan ly    ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "    ║        ";
    SetConsoleTextAttribute(color, cyan);
    cout << "       Thong tin nhan vien   ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "         ║\n";
    cout << "║ ";
    SetConsoleTextAttribute(color, cyan);
    cout << "So Thu Tu ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║ ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Ma phong ban ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║  ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Ten phong ban   ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║   ";
    SetConsoleTextAttribute(color, cyan);
    cout << "So luong nhan su   ";
    SetConsoleTextAttribute(color, darkWhite);
    PhongBan *firstPB = dsPhongBan.front();
    cout << "╠════════════╦═══════════════════════╬═════════╦════════════╦═══════════════════════╣\n";
    cout << "║           ║              ║                  ║                      ║    Ma so   ║       Ho & ten        ║   STT   ║   Ma so    ║        Ho & ten       ║\n";
    if (firstPB->getTruongPhong() == nullptr && firstPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╠════════════╩═══════════════════════╬═════════╩════════════╩═══════════════════════╣\n";
    }
    else if (firstPB->getTruongPhong() == nullptr)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╠════════════╩═══════════════════════╬═════════╬════════════╬═══════════════════════╣\n";
    }
    else if (firstPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╠════════════╬═══════════════════════╬═════════╩════════════╩═══════════════════════╣\n";
    }
    else
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╠════════════╬═══════════════════════╬═════════╬════════════╬═══════════════════════╣\n";
    }

    PhongBan *next = nullptr;
    PhongBan *lastPB = dsPhongBan.back();
    int j = 1;
    for (int i = 0; i < dsPhongBan.size(); i++)
    {
      if (dsPhongBan[i + 1] != nullptr)
      {
        next = dsPhongBan[i + 1];
      }
      else
      {
        next = nullptr;
      }

      cout << "║ " << std::setw(5) << std::setfill(' ');
      SetConsoleTextAttribute(color, cyan);
      cout << j;
      SetConsoleTextAttribute(color, darkWhite);
      cout << std::setw(4) << std::setfill(' ') << ""
           << " ║";
      dsPhongBan[i]->xuatPB();
      cout << endl;

      if (dsPhongBan[i] != lastPB && dsPhongBan[i]->getTruongPhong() == nullptr && dsPhongBan[i]->getDsNV().size() == 0)
      {
        checkNextAllNull(next);
      }
      else if (dsPhongBan[i] != lastPB && dsPhongBan[i]->getTruongPhong() == nullptr)
      {
        checkNextTPNull(next);
      }
      else if (dsPhongBan[i] != lastPB && dsPhongBan[i]->getDsNV().size() == 0)
      {
        checkNextNVNull(next);
      }
      else if (dsPhongBan[i] != lastPB)
      {
        checkNextAllKhongNull(next);
      }
      if (dsPhongBan[i] == lastPB && dsPhongBan[i]->getTruongPhong() == nullptr && dsPhongBan[i]->getDsNV().size() == 0)
      {
        cout << "╚═══════════╩══════════════╩══════════════════╩══════════════════════╩════════════════════════════════════╩══════════════════════════════════════════════╝\n";
      }
      else if (dsPhongBan[i] == lastPB && dsPhongBan[i]->getTruongPhong() == nullptr)
      {
        cout << "╚═══════════╩══════════════╩══════════════════╩══════════════════════╩════════════════════════════════════╩═════════╩════════════╩═══════════════════════╝\n";
      }
      else if (dsPhongBan[i] == lastPB && dsPhongBan[i]->getDsNV().size() == 0)
      {
        cout << "╚═══════════╩══════════════╩══════════════════╩══════════════════════╩════════════╩═══════════════════════╩══════════════════════════════════════════════╝\n";
      }
      else if (dsPhongBan[i] == lastPB)
      {
        cout << "╚═══════════╩══════════════╩══════════════════╩══════════════════════╩════════════╩═══════════════════════╩═════════╩════════════╩═══════════════════════╝\n";
      }
      j++;
    }
  }
}

void DanhSachPhongBan::checkNextAllNull(PhongBan *nextPB)
{
  if (nextPB != nullptr)
  {
    if (nextPB->getTruongPhong() == nullptr && nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════════════════════════════╬══════════════════════════════════════════════╣\n";
    }
    else if (nextPB->getTruongPhong() == nullptr)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════════════════════════════╬═════════╦════════════╦═══════════════════════╣\n";
    }
    else if (nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╦═══════════════════════╬══════════════════════════════════════════════╣\n";
    }
    else
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╦═══════════════════════╬═════════╦════════════╦═══════════════════════╣\n";
    }
  }
}

void DanhSachPhongBan::checkNextTPNull(PhongBan *nextPB)
{
  if (nextPB != nullptr)
  {
    if (nextPB->getTruongPhong() == nullptr && nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════════════════════════════╬═════════╩════════════╩═══════════════════════╣\n";
    }
    else if (nextPB->getTruongPhong() == nullptr)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════════════════════════════╬═════════╬════════════╬═══════════════════════╣\n";
    }
    else if (nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╦═══════════════════════╬═════════╩════════════╩═══════════════════════╣\n";
    }
    else
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╦═══════════════════════╬═════════╬════════════╬═══════════════════════╣\n";
    }
  }
}

void DanhSachPhongBan::checkNextNVNull(PhongBan *nextPB)
{
  if (nextPB != nullptr)
  {
    if (nextPB->getTruongPhong() == nullptr && nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╩═══════════════════════╬══════════════════════════════════════════════╣\n";
    }
    else if (nextPB->getTruongPhong() == nullptr)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╩═══════════════════════╬═════════╦════════════╦═══════════════════════╣\n";
    }
    else if (nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╬═══════════════════════╬══════════════════════════════════════════════╣\n";
    }
    else
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╬═══════════════════════╬═════════╦════════════╦═══════════════════════╣\n";
    }
  }
}

void DanhSachPhongBan::checkNextAllKhongNull(PhongBan *nextPB)
{
  if (nextPB != nullptr)
  {
    if (nextPB->getTruongPhong() == nullptr && nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╩═══════════════════════╬═════════╩════════════╩═══════════════════════╣\n";
    }
    else if (nextPB->getTruongPhong() == nullptr)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╩═══════════════════════╬═════════╬════════════╬═══════════════════════╣\n";
    }
    else if (nextPB->getDsNV().size() == 0)
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╬═══════════════════════╬═════════╩════════════╩═══════════════════════╣\n";
    }
    else
    {
      cout << "╠═══════════╬══════════════╬══════════════════╬══════════════════════╬════════════╬═══════════════════════╬═════════╬════════════╬═══════════════════════╣\n";
    }
  }
}

void DanhSachPhongBan::docFilePB(string fileName)
{
  ifstream file(fileName);
  if (file.is_open())
  {
    while (file.good())
    {
      PhongBan *pb = new PhongBan();
      file >> *pb;
      this->dsPhongBan.push_back(pb);
    }
    file.close();
  }
  else
  {
    cout << "Khong mo duoc file!" << endl;
  }
}

DanhSachPhongBan::DanhSachPhongBan()
{
  docFilePB("PhongBan.txt");
}