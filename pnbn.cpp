#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo{
	
	private:
		int tu;
		int mau;
	public:
		
	
		
		 
		PhanSo(int t = 0 , int m = 1) : tu(t) , mau(m){
		}
		
		friend istream& operator >>(istream& in, PhanSo& ps)
		{
			cout<<"Nhap tu so:"; in>>ps.tu;
			cout<<"Nhap mau so:"; in>>ps.mau;
			return in;
			while(ps.mau == 0 )
			{
				cout<<"Nhap Lai mau so #0: ";
				in>>ps.mau;
			}
			return in;
			
			
		}
		friend ostream& operator<<(ostream& out , PhanSo ps)
		{
			out<<ps.tu<<"/"<<ps.mau<<endl;
			return out;
		}
		PhanSo operator+(PhanSo ps)
		{
			
			PhanSo tmp;
			tmp.tu = tu * ps.mau + mau * ps.tu;
			tmp.mau = mau * ps.mau;
			tmp.toiGian();
			return tmp;
		}
		PhanSo operator-(PhanSo ps)
		{
			
			PhanSo tmp;
			tmp.tu = tu * ps.mau - mau * ps.tu;
			tmp.mau = mau * ps.mau;
			tmp.toiGian();
			return tmp;
		}
		void toiGian()
		{
			int UCLN = __gcd(tu, mau);
			tu = tu / UCLN;
			mau = mau / UCLN;
			if(mau <0) mau = -mau; tu = -tu;
		}
};
int main()
{
	PhanSo ps1;
	cin>>ps1;
	PhanSo ps2;
	cin>>ps2;
	PhanSo ps3 = ps1 + ps2;
	cout<<ps3;
	return 0; 
}
