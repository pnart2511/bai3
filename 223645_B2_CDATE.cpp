#include <iostream>
#include <stdexcept>
using namespace std;
 
class CDate{
	
	
	private:
		int iYear , iMonth , iDay;
		static int DayinMonth[13];
	public:
		//ham dung k tham so 
		CDate(){
			iYear = iMonth = iDay = 0;
		}
		CDate(CDate& d)
		{
			iDay = d.iDay;
			iMonth = d.iMonth;
			iYear = d.iYear;
		}
		CDate(int day , int month , int year){
			iDay = day;
			iMonth = month;
			iYear = year;
			if(IsLeapYear())
			{
				DayinMonth[2] = 29;
			}
		}
		//ham in
		
		void Print(){
			if(!IsYear())
			{
				throw invalid_argument("Nam Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			if(!IsMonth())
			{
				throw invalid_argument("Thang Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			if(!IsDay())
			{
				throw invalid_argument("Ngay Khong Hop Le!!!!!!!!!!!!!!!!!!!!");
				
			}
			
			cout<<iDay<<"/"<<iMonth<<"/"<<iYear<<endl;
		}
		//ham 14 ->17
		bool IsYear()
		{
					 if(iYear> 0 )
				 {
				 	return true;
				 }
				 else
				 {
				 	return false;
				 }
		}
		
		
		bool IsMonth()
		{
			if(iMonth >= 1 && iMonth <= 12)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		
		
		
	
		bool IsDay()
		{
			if(iDay >= 1 && iDay <= DayinMonth[iMonth] )
			{
				return true;
				
			}
			else {
				return false;
			}
		}
		bool IsLeapYear(){
			
			if(iYear % 4 == 0 && iYear % 100 != 0 || (iYear % 400 == 0)) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
};
int CDate::DayinMonth[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
int main()
{
	
	try{
		CDate d2(29,2,2024);
	d2.Print();
	}
	catch(logic_error e)
	{
		cout<<e.what()<<endl;
	}
	
	
	
	

	
	
	
	return 0;
}
